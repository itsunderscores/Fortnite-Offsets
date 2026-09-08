# Fortnite Offsets

Up-to-date Unreal Engine offsets for Fortnite, dumped as both a C++ header (`offsets.h`) and JSON (`offsets.json`).

| | |
|---|---|
| **Last updated** | September 7, 2026 |
| **Last checked** | September 8, 2026 at 10:09 AM ET |
| **Status** | Current patch |
| **Formats** | `offsets.h` · `offsets.json` |
| **Contact** | [t.me/ReadAccess](https://t.me/ReadAccess) |

> Offsets change every Fortnite update. If something reads as null or garbage after a patch, grab the latest dump from this repo before anything else.

---

## Contents

- [What's in this repo](#whats-in-this-repo)
- [How to use](#how-to-use)
- [Main offsets](#main-offsets)
  - [Core / world](#core--world)
    - [Globals](#globals)
    - [World chain](#world-chain)
    - [Actor / component](#actor--component)
    - [Mesh / bones](#mesh--bones)
    - [Camera / view](#camera--view)
    - [Misc actor checks](#misc-actor-checks)
  - [Player](#player)
  - [Weapon](#weapon)
  - [Aim](#aim)
  - [Loot](#loot)
  - [Pickup](#pickup)
- [Common pointer chain](#common-pointer-chain)
- [Helper snippets](#helper-snippets)
- [Notes](#notes)

---

## What's in this repo

| File | What it is |
|---|---|
| [`offsets.h`](offsets.h) | C++ `constexpr` offsets, namespaced (`core`, `player`, `weapon`, `aim`, `loot`, `pickup`) |
| [`offsets.json`](offsets.json) | Same offsets as JSON for loaders, dumpers, or other languages |
| [`Uworld.h`](Uworld.h) | Encrypted `GWorld` decrypt, or GEngine → GameViewport → UWorld |
| [`Camera.h`](Camera.h) | Location / rotation pointers, FOV, world-to-screen |
| [`PlayerName.h`](PlayerName.h) | Player name decrypt from `PlayerState` |
| [`DecryptWeapon.h`](DecryptWeapon.h) | Current weapon name from pawn |
| [`VisCheck.h`](VisCheck.h) | Visibility check via `Seconds` vs `LastRenderTime` |
| [`RankedProgress.h`](RankedProgress.h) | Ranked tier from `HabaneroComponent` |
| [`Matrix.h`](Matrix.h) | `FTransform` / matrix helpers for bones |

---

## How to use

Drop `offsets.h` into your project and include it. `GWorld` at `0x1A9E6268` is encrypted — decrypt it to get `UWorld`:

```cpp
#include "offsets.h"
#include <intrin.h>

constexpr std::uintptr_t uworld_encrypted_rva = 0x1A9E6268;

auto encrypted = Read<uint64_t>(base + uworld_encrypted_rva);
auto uworld = static_cast<uintptr_t>(
    _byteswap_uint64(encrypted ^ 0x0000000001047ADE) - 0x0803A0EA
);

auto game_instance = Read<uintptr_t>(uworld + offsets::core::GameInstance);
auto local_players = Read<uintptr_t>(game_instance + offsets::player::LocalPlayers);
auto local_player  = Read<uintptr_t>(local_players);
auto controller    = Read<uintptr_t>(local_player + offsets::player::PlayerController);
auto pawn          = Read<uintptr_t>(controller + offsets::player::LocalPawn);
auto mesh          = Read<uintptr_t>(pawn + offsets::player::Mesh);
```

`gEngine` still works if you want the viewport chain instead:

```cpp
auto gengine  = Read<uintptr_t>(base + offsets::core::gEngine);
auto viewport = Read<uintptr_t>(gengine + offsets::core::GameViewport);
auto uworld   = Read<uintptr_t>(viewport + 0x78); // UWorld
```

If you load offsets at runtime instead of compiling them in, parse `offsets.json`. The keys match the C++ names.

---

## Main offsets

Values are copied from `offsets.h`. Globals (`GWorld`, `gEngine`) are relative to the game module base. `GWorld` is encrypted — XOR, byteswap, then subtract. Everything else is a class member offset. Labels use Unreal names (`Class::Member`).

### Core / world

#### Globals

| Name | Offset | Label |
|---|---|---|
| **UWorld** (`GWorld`) | `0x1A9E6268` | Encrypted `GWorld` RVA — `base + GWorld`, then decrypt |
| **UEngine** (`gEngine`) | `0x1A9E7BD8` | Global `GEngine` pointer — `base + gEngine` |

#### World chain

| Name | Offset | Label |
|---|---|---|
| **GameViewport** | `0xB70` | `UEngine::GameViewport` |
| **GameInstance** | `0x240` | `UWorld::OwningGameInstance` |
| **GameState** | `0x1C8` | `UWorld::GameState` |
| **PersistentLevel** | `0x38` | `UWorld::PersistentLevel` |
| **Levels** | `0x1E0` | `UWorld::Levels` |
| **Actors** | `0x218` | `ULevelActorContainer::Actors` |
| **PlayerArray** | `0x288` | `AGameStateBase::PlayerArray` |
| **ServerWorldTime** | `0x2A0` | `AGameStateBase::ServerWorldTimeSecondsDelta` |
| **Seconds** | `0x188` | `UWorld::TimeSeconds` — `RotationPointer + 0x10` |

#### Actor / component

| Name | Offset | Label |
|---|---|---|
| **RootComponent** | `0x1B0` | `AActor::RootComponent` |
| **RelativeLocation** | `0x140` | `USceneComponent::RelativeLocation` |
| **ComponentToWorld** | `0x1E0` | `USceneComponent::ComponentToWorld` (`Mobility + 0x3D`) |

`Mesh` lives under **player** (`ACharacter::Mesh @ 0x2F0`).

#### Mesh / bones

| Name | Offset | Label |
|---|---|---|
| **BoneArray** | `0x660` | `USkeletalMeshComponent` bone `TArray` (primary) |
| **BoneArray_cache** | `0x670` | `USkeletalMeshComponent` bone `TArray` (secondary) — always `BoneArray + 0x10` |
| **CurrentReadComponentTransforms** | `0x48` | `USkeletalMeshComponent` active bone buffer index |
| **CachedComponentSpaceTransforms** | `0x9E8` | `USkeletalMeshComponent::CachedComponentSpaceTransforms` |
| **LastRenderTime** | `0x290` | `UPrimitiveComponent::LastRenderTimeOnScreen` |

#### Camera / view

| Name | Offset | Label |
|---|---|---|
| **LocationPointer** | `0x168` | `UWorld` camera location pointer (view chain) |
| **RotationPointer** | `0x178` | `UWorld` camera rotation pointer (view chain) |
| **FOV** | `0x374` | `APlayerController` FOV scalar (degrees / 90) |

#### Misc actor checks

| Name | Offset | Label |
|---|---|---|
| **ReviveFromDBNOTime** | `0x4AC8` | `AFortPlayerPawnAthena::ReviveFromDBNOTime` |
| **LifespanAfterDeath** | `0x10A8` | `AFortAthenaVehicle::LifespanAfterDeath` |
| **ServerCriticalHealth** | `0x1BFC` | `AFortAthenaVehicle::ServerCriticalHealth` |

### Player

`UGameInstance` / `APlayerController` / `AFortPlayerState`

| Name | Offset | Label |
|---|---|---|
| **Mesh** | `0x2F0` | `ACharacter::Mesh` (`SkeletalMeshComponent*`) |
| **LocalPlayers** | `0x38` | `UGameInstance::LocalPlayers` |
| **PlayerController** | `0x30` | `UPlayer::PlayerController` |
| **LocalPawn** | `0x318` | `APlayerController::AcknowledgedPawn` |
| **PawnPrivate** | `0x2E8` | `APlayerState::PawnPrivate` |
| **PlayerState** | `0x290` | `APawn::PlayerState` |
| **TeamIndex** | `0xF61` | `AFortPlayerStateAthena::TeamIndex` |
| **PlayerName** | `0x9E8` | `AFortPlayerState` username struct (`FText`, encrypted) |
| **KillScore** | `0xF78` | `AFortPlayerStateAthena::KillScore` |
| **Platform** | `0x400` | `AFortPlayerState::Platform` |
| **HabaneroComponent** | `0x918` | `AFortPlayerState::HabaneroComponent` |
| **bIsDying** | `0x728` | `AFortPawn::bIsDying` (bit 5) |
| **bIsDBNO** | `0x881` | `AFortPawn::bIsDBNO` (bit 0) |
| **bIsABot** | `0x27A` | `APlayerState::bIsABot` (bit 3) |
| **bIsCrouched** | `0x430` | `ACharacter::bIsCrouched` (bit 0) |

### Weapon

`AFortPawn` / `AFortWeapon` / `UFortWeaponItemDefinition`

| Name | Offset | Label |
|---|---|---|
| **CurrentWeapon** | `0x9D0` | `AFortPawn::CurrentWeapon` |
| **WeaponData** | `0x638` | `AFortWeapon::WeaponData` |
| **ItemName** | `0x38` | `UItemDefinitionBase::ItemName` |
| **AmmoCount** | `0x1100` | `AFortWeapon::AmmoCount` |
| **bIsReloadingWeapon** | `0x381` | `AFortWeapon::bIsReloadingWeapon` (bit 0) |
| **LastFireTime** | `0xFFC` | `AFortWeapon::LastFireTime` |
| **LastFireTimeVerified** | `0x1004` | `AFortWeapon::LastFireTimeVerified` |
| **LastDamagedTime** | `0xDE8` | `AFortPawn::LastDamagedTime` |
| **ProjectileSpeed** | `0x210C` | `AFortWeapon` projectile speed (float on weapon) |
| **ProjectileGravity** | `0x2110` | `AFortWeapon::ProjectileGravityScale` — `ProjectileSpeed + 0x4` |
| **ComponentVelocity** | `0x188` | `USceneComponent::ComponentVelocity` (read from `RootComponent`) |

### Aim

`AFortPlayerController` / `APlayerController`

| Name | Offset | Label |
|---|---|---|
| **TargetedFortPawn** | `0x16C0` | `AFortPlayerController::TargetedFortPawn` |
| **LocationUnderReticle** | `0x2188` | `AFortPlayerController::LocationUnderReticle` |
| **NetConnection** | `0x4A8` | `APlayerController::NetConnection` |
| **RotationInput** | `0x4B0` | Rotation write — `NetConnection + 0x08` |
| **WeaponOffsetCorrection** | `0x2340` | `AFortPlayerController::WeaponOffsetCorrection` |
| **WeaponRecoilOffset** | `0x2328` | `AFortPlayerController::WeaponRecoilOffset` |
| **PlayerAimOffset** | `0x2310` | `AFortPlayerController::PlayerAimOffset` |

### Loot

`ABuildingContainer` (chest / ammo box)

| Name | Offset | Label |
|---|---|---|
| **SpawnSourceOverride** | `0xB78` | `ABuildingContainer::SpawnSourceOverride` |
| **SearchedFlags** | `0xCE2` | `ABuildingContainer` (`bAlreadySearched` bit 4) |
| **SearchText** | `0xD38` | `ABuildingContainer::SearchText` |
| **ChosenRandomUpgrade** | `0xBC4` | `ABuildingContainer::ChosenRandomUpgrade` |

### Pickup

`AFortPickup` (floor loot)

| Name | Offset | Label |
|---|---|---|
| **SimulatingTooLongLength** | `0x290` | `AFortPickup` |
| **PrimaryPickupItemEntry** | `0x368` | `AFortPickup` |
| **PickupFlags** | `0x28C` | `AFortPickup` (`bPickedUp` bit 1) |
| **PickupExtendedFlags** | `0x28D` | `AFortPickup` (`bClientUseInterpolationOnly` bit 1) |
| **PickupLocationData** | `0x410` | `AFortPickup` (`FFortPickupLocationData`) |
| **ItemEntryItemDefinition** | `0x10` | `FItemEntry` → `UItemDefinitionBase* ItemDefinition` |
| **ItemEntryItemDataList** | `0x28` | `FItemEntry::ItemData.DataList` (`FItemComponentDataList`) |
| **ItemDefinitionName** | `0x38` | `UItemDefinitionBase::ItemName` |
| **ItemDefinitionDataList** | `0x68` | `UItemDefinitionBase::DataList` |
| **WeaponDisplayTier** | `0x296` | `UFortWeaponItemDefinition::DisplayTier` |
| **RarityStruct** | `0x17EF48D8` | `GRarityStruct` — module offset, not an absolute pointer |

---

## Common pointer chain

Typical resolve from module base to local pawn and mesh:

```text
base
 ├─ + GWorld (encrypted) → decrypt → UWorld
 │    ├─ + GameInstance → GameInstance
 │    │    └─ + LocalPlayers[0]
 │    │         └─ + PlayerController
 │    │              ├─ + LocalPawn     → pawn
 │    │              ├─ + FOV
 │    │              └─ + TargetedFortPawn / LocationUnderReticle
 │    ├─ + GameState
 │    │    └─ + PlayerArray
 │    ├─ + PersistentLevel / Levels
 │    │    └─ + Actors
 │    └─ + LocationPointer / RotationPointer / Seconds
 │
 └─ + gEngine → GameViewport → +0x78 → UWorld  (alternate)

 pawn
 ├─ + Mesh              → skeletal mesh (BoneArray / BoneArray_cache)
 ├─ + RootComponent     → ComponentToWorld, RelativeLocation
 ├─ + PlayerState       → PlayerName, KillScore, Platform, TeamIndex
 └─ + CurrentWeapon     → WeaponData, AmmoCount, ProjectileSpeed, ProjectileGravity
```

`GWorld` decrypt:

```cpp
constexpr std::uintptr_t uworld_encrypted_rva = 0x1A9E6268;

auto encrypted = Read<uint64_t>(base + uworld_encrypted_rva);
auto uworld = static_cast<uintptr_t>(
    _byteswap_uint64(encrypted ^ 0x0000000001047ADE) - 0x0803A0EA
);
```

Alternate UWorld resolve from `gEngine` (from `Uworld.h`):

```cpp
auto gengine  = Read<uintptr_t>(base + offsets::core::gEngine);
auto viewport = Read<uintptr_t>(gengine + offsets::core::GameViewport); // 0xB70
auto uworld   = Read<uintptr_t>(viewport + 0x78);                       // UGameViewportClient::World
```

---

## Helper snippets

These headers are examples of how the offsets are typically read. Copy what you need; they are not a full project.

| Need | File |
|---|---|
| Camera location, rotation, FOV | `Camera.h` |
| Decrypt player name | `PlayerName.h` |
| Current weapon name | `DecryptWeapon.h` |
| Visible / recently rendered | `VisCheck.h` (`Seconds` − `LastRenderTime`) |
| Ranked rank from player state | `RankedProgress.h` |
| Bone / component matrices | `Matrix.h` |

---

## Notes

- **Patch cadence** — Fortnite ships updates often. Globals like `GWorld` and `gEngine` almost always move. The `GWorld` xor/subtract constants can change too. Member offsets move less often but still can.
- **Two copies** — Keep `offsets.h` and `offsets.json` in sync. If you only update one, the other will be stale.
- **Names** — `PlayerName` is encrypted. Use the decrypt in `PlayerName.h`, do not treat it as a raw string.
- **Visibility** — `VisCheck.h` treats a mesh as hidden if `Seconds - LastRenderTime > 0.06`.
- **Ranked** — `HabaneroComponent` is on `PlayerState`. Ranked tier is read from that component (see `RankedProgress.h`).
- **GWorld** — The value at `0x1A9E6268` is encrypted. XOR with `0x1047ADE`, `_byteswap_uint64`, then subtract `0x0803A0EA`. Do not use it as a raw pointer.
- **Validation** — Always null-check pointers (`UWorld`, pawn, mesh, weapon). A bad chain is the usual cause of crashes after an update.

Offsets outdated? Ping **[@ReadAccess](https://t.me/ReadAccess)** on Telegram.
