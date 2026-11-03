# Fortnite Offsets

Up-to-date Unreal Engine offsets for Fortnite, dumped as both a C++ header (`offsets.h`) and JSON (`offsets.json`).

| | |
|---|---|
| **Last updated** | November 1, 2026 |
| **Last checked** | November 3, 2026 at 6:14 AM ET |
| **Status** | ++Fortnite+Release-43.00-CL-59596594 |
| **Formats** | `offsets.h` · `offsets.json` |
| **SDK Viewer** | [underscores.dev](https://underscores.dev/) |
| **Contact** | [t.me/ReadAccess](https://t.me/ReadAccess) |

> Offsets change every Fortnite update. If something reads as null or garbage after a patch, grab the latest dump from this repo before anything else.

---

## Contents

- [What's in this repo](#whats-in-this-repo)
- [SDK Viewer](#sdk-viewer)
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
| [`Uworld.h`](Uworld.h) | GEngine → GameViewport → UWorld |
| [`Camera.h`](Camera.h) | Location / rotation pointers, FOV, world-to-screen |
| [`PlayerName.h`](PlayerName.h) | Player name decrypt from `PlayerState` |
| [`DecryptWeapon.h`](DecryptWeapon.h) | Current weapon name from pawn |
| [`VisCheck.h`](VisCheck.h) | Visibility check via `Seconds` vs `LastRenderTime` |
| [`RankedProgress.h`](RankedProgress.h) | Ranked tier from `HabaneroComponent` |
| [`Matrix.h`](Matrix.h) | `FTransform` / matrix helpers for bones |

---

## SDK Viewer

Browse classes, members, and offsets in the browser: **[underscores.dev](https://underscores.dev/)**.

Use it when you need the full SDK, not just the dump in this README.

---

## How to use

Drop `offsets.h` into your project and include it. Get `UWorld` from `gEngine`:

```cpp
#include "offsets.h"

auto gengine  = Read<uintptr_t>(base + offsets::core::gEngine);
auto viewport = Read<uintptr_t>(gengine + offsets::core::GameViewport);
auto uworld   = Read<uintptr_t>(viewport + 0x78); // UWorld

auto game_instance = Read<uintptr_t>(uworld + offsets::core::GameInstance);
auto local_players = Read<uintptr_t>(game_instance + offsets::player::LocalPlayers);
auto local_player  = Read<uintptr_t>(local_players);
auto controller    = Read<uintptr_t>(local_player + offsets::player::PlayerController);
auto pawn          = Read<uintptr_t>(controller + offsets::player::LocalPawn);
auto mesh          = Read<uintptr_t>(pawn + offsets::player::Mesh);
```

`UWORLD` at `0x1C8E1578` is encrypted. There is no decrypt in this dump yet — use the chain above.

If you load offsets at runtime instead of compiling them in, parse `offsets.json`. The keys match the C++ names.

---

## Main offsets

Values are copied from `offsets.h`. Globals (`UWORLD`, `gEngine`) are relative to the game module base. Resolve `UWorld` via `gEngine` → GameViewport → `+0x78`. Everything else is a class member offset. Labels use Unreal names (`Class::Member`).

### Core / world

#### Globals

| Name | Offset | Label |
|---|---|---|
| **UWorld** (`UWORLD`) | `0x1C8E1578` | Encrypted `GWorld` RVA — listed for reference; use `gEngine` chain for `UWorld` |
| **UEngine** (`gEngine`) | `0x1C8E2F48` | Global `GEngine` pointer — `base + gEngine` |

#### World chain

| Name | Offset | Label |
|---|---|---|
| **GameViewport** | `0xB70` | `UEngine::GameViewport` |
| **GameInstance** | `0x248` | `UWorld::OwningGameInstance` |
| **GameState** | `0x1D0` | `UWorld::GameState` |
| **PersistentLevel** | `0x40` | `UWorld::PersistentLevel` |
| **Levels** | `0x1E8` | `UWorld::Levels` |
| **Actors** | `0x208` | `ULevelActorContainer::Actors` |
| **PlayerArray** | `0x290` | `AGameStateBase::PlayerArray` |
| **ServerWorldTime** | `0x2B0` | `AGameStateBase::ServerWorldTimeSecondsDelta` |
| **Seconds** | `0x198` | `UWorld::TimeSeconds` — `RotationPointer + 0x10` |

#### Actor / component

| Name | Offset | Label |
|---|---|---|
| **RootComponent** | `0x1B0` | `AActor::RootComponent` |
| **RelativeLocation** | `0x140` | `USceneComponent::RelativeLocation` |
| **ComponentToWorld** | `0x1E0` | `USceneComponent::ComponentToWorld` (`Mobility + 0x3D`) |

`Mesh` lives under **player** (`ACharacter::Mesh @ 0x2F8`).

#### Mesh / bones

| Name | Offset | Label |
|---|---|---|
| **BoneArray** | `0x660` | `USkeletalMeshComponent` bone `TArray` (primary) |
| **BoneArray_cache** | `0x670` | `USkeletalMeshComponent` bone `TArray` (secondary) — always `BoneArray + 0x10` |
| **CurrentReadComponentTransforms** | `0x48` | `USkeletalMeshComponent` active bone buffer index |
| **CachedComponentSpaceTransforms** | `0x9C8` | `USkeletalMeshComponent::CachedComponentSpaceTransforms` |
| **LastRenderTime** | `0x2E8` | `UPrimitiveComponent::LastRenderTimeOnScreen` |

#### Camera / view

| Name | Offset | Label |
|---|---|---|
| **LocationPointer** | `0x178` | `UWorld` camera location pointer (view chain) |
| **RotationPointer** | `0x188` | `UWorld` camera rotation pointer (view chain) |
| **FOV** | `0x37C` | `APlayerController` FOV scalar (degrees / 90) |

#### Misc actor checks

| Name | Offset | Label |
|---|---|---|
| **ReviveFromDBNOTime** | `0x4E20` | `AFortPlayerPawnAthena::ReviveFromDBNOTime` |
| **LifespanAfterDeath** | `0x10B8` | `AFortAthenaVehicle::LifespanAfterDeath` |
| **ServerCriticalHealth** | `0x1C3C` | `AFortAthenaVehicle::ServerCriticalHealth` |

### Player

`UGameInstance` / `APlayerController` / `AFortPlayerState`

| Name | Offset | Label |
|---|---|---|
| **Mesh** | `0x2F8` | `ACharacter::Mesh` (`SkeletalMeshComponent*`) |
| **LocalPlayers** | `0x38` | `UGameInstance::LocalPlayers` |
| **PlayerController** | `0x30` | `UPlayer::PlayerController` |
| **LocalPawn** | `0x320` | `APlayerController::AcknowledgedPawn` |
| **PawnPrivate** | `0x2F0` | `APlayerState::PawnPrivate` |
| **PlayerState** | `0x298` | `APawn::PlayerState` |
| **TeamIndex** | `0xF81` | `AFortPlayerStateAthena::TeamIndex` |
| **PlayerName** | `0x9F0` | `AFortPlayerState` username struct (`FText`, encrypted) |
| **KillScore** | `0xF98` | `AFortPlayerStateAthena::KillScore` |
| **Platform** | `0x408` | `AFortPlayerState::Platform` |
| **HabaneroComponent** | `0x920` | `AFortPlayerState::HabaneroComponent` |
| **bIsDying** | `0x738` | `AFortPawn::bIsDying` (bit 5) |
| **bIsDBNO** | `0x881` | `AFortPawn::bIsDBNO` (bit 0) |
| **bIsABot** | `0x282` | `APlayerState::bIsABot` (bit 3) |
| **bIsCrouched** | `0x440` | `ACharacter::bIsCrouched` (bit 0) |

### Weapon

`AFortPawn` / `AFortWeapon` / `UFortWeaponItemDefinition`

| Name | Offset | Label |
|---|---|---|
| **CurrentWeapon** | `0x9E0` | `AFortPawn::CurrentWeapon` |
| **WeaponData** | `0x650` | `AFortWeapon::WeaponData` |
| **ItemName** | `0x38` | `UItemDefinitionBase::ItemName` |
| **AmmoCount** | `0x1138` | `AFortWeapon::AmmoCount` |
| **bIsReloadingWeapon** | `0x391` | `AFortWeapon::bIsReloadingWeapon` (bit 0) |
| **LastFireTime** | `0x1034` | `AFortWeapon::LastFireTime` |
| **LastFireTimeVerified** | `0x103C` | `AFortWeapon::LastFireTimeVerified` |
| **LastDamagedTime** | `0xE40` | `AFortPawn::LastDamagedTime` |
| **ProjectileSpeed** | `0x21e4` | `AFortWeapon` projectile speed (float on weapon) |
| **ProjectileGravity** | `0x21e8` | `AFortWeapon::ProjectileGravityScale` — `ProjectileSpeed + 0x4` |
| **ComponentVelocity** | `0x188` | `USceneComponent::ComponentVelocity` (read from `RootComponent`) |

### Aim

`AFortPlayerController` / `APlayerController`

| Name | Offset | Label |
|---|---|---|
| **TargetedFortPawn** | `0x1740` | `AFortPlayerController::TargetedFortPawn` |
| **LocationUnderReticle** | `0x2208` | `AFortPlayerController::LocationUnderReticle` |
| **NetConnection** | `0x4B0` | `APlayerController::NetConnection` |
| **RotationInput** | `0x4B8` | Rotation write — `NetConnection + 0x08` |
| **WeaponOffsetCorrection** | `0x23C0` | `AFortPlayerController::WeaponOffsetCorrection` |
| **WeaponRecoilOffset** | `0x23A8` | `AFortPlayerController::WeaponRecoilOffset` |
| **PlayerAimOffset** | `0x2390` | `AFortPlayerController::PlayerAimOffset` |

### Loot

`ABuildingContainer` (chest / ammo box)

| Name | Offset | Label |
|---|---|---|
| **SpawnSourceOverride** | `0xBC0` | `ABuildingContainer::SpawnSourceOverride` |
| **SearchedFlags** | `0xD2A` | `ABuildingContainer` (`bAlreadySearched` bit 4) |
| **SearchText** | `0xD80` | `ABuildingContainer::SearchText` |
| **ChosenRandomUpgrade** | `0xC0C` | `ABuildingContainer::ChosenRandomUpgrade` |

### Pickup

`AFortPickup` (floor loot)

| Name | Offset | Label |
|---|---|---|
| **SimulatingTooLongLength** | `0x298` | `AFortPickup` |
| **PrimaryPickupItemEntry** | `0x370` | `AFortPickup` |
| **PickupFlags** | `0x294` | `AFortPickup` (`bPickedUp` bit 1) |
| **PickupExtendedFlags** | `0x295` | `AFortPickup` (`bClientUseInterpolationOnly` bit 1) |
| **PickupLocationData** | `0x418` | `AFortPickup` (`FFortPickupLocationData`) |
| **ItemEntryItemDefinition** | `0x10` | `FItemEntry` → `UItemDefinitionBase* ItemDefinition` |
| **ItemEntryItemDataList** | `0x28` | `FItemEntry::ItemData.DataList` (`FItemComponentDataList`) |
| **ItemDefinitionName** | `0x38` | `UItemDefinitionBase::ItemName` |
| **ItemDefinitionDataList** | `0x68` | `UItemDefinitionBase::DataList` |
| **WeaponDisplayTier** | `0x296` | `UFortWeaponItemDefinition::DisplayTier` |
| **RarityStruct** | `0x1C8E1578` | `GRarityStruct` — module offset, not an absolute pointer |

---

## Common pointer chain

Typical resolve from module base to local pawn and mesh:

```text
base
 └─ + gEngine           → UEngine
      └─ + GameViewport → UGameViewportClient
           └─ + 0x78    → UWorld
                ├─ + GameInstance → GameInstance
                │    └─ + LocalPlayers[0]
                │         └─ + PlayerController
                │              ├─ + LocalPawn     → pawn
                │              ├─ + FOV
                │              └─ + TargetedFortPawn / LocationUnderReticle
                ├─ + GameState
                │    └─ + PlayerArray
                ├─ + PersistentLevel / Levels
                │    └─ + Actors
                └─ + LocationPointer / RotationPointer / Seconds

 pawn
 ├─ + Mesh              → skeletal mesh (BoneArray / BoneArray_cache)
 ├─ + RootComponent     → ComponentToWorld, RelativeLocation
 ├─ + PlayerState       → PlayerName, KillScore, Platform, TeamIndex
 └─ + CurrentWeapon     → WeaponData, AmmoCount, ProjectileSpeed, ProjectileGravity
```

UWorld resolve (from `Uworld.h`):

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

- **Patch cadence** — Fortnite ships updates often. Globals like `gEngine` almost always move. Member offsets move less often but still can.
- **Two copies** — Keep `offsets.h` and `offsets.json` in sync. If you only update one, the other will be stale.
- **Names** — `PlayerName` is encrypted. Use the decrypt in `PlayerName.h`, do not treat it as a raw string.
- **Visibility** — `VisCheck.h` treats a mesh as hidden if `Seconds - LastRenderTime > 0.06`.
- **Ranked** — `HabaneroComponent` is on `PlayerState`. Ranked tier is read from that component (see `RankedProgress.h`).
- **UWORLD** — The value at `0x1C8E1578` is encrypted. Decrypt is not in this repo yet. Use `gEngine` → GameViewport → `+0x78` for `UWorld`.
- **Validation** — Always null-check pointers (`UWorld`, pawn, mesh, weapon). A bad chain is the usual cause of crashes after an update.

Offsets outdated? Ping **[@ReadAccess](https://t.me/ReadAccess)** on Telegram.
