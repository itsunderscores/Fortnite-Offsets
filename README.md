# Fortnite Offsets

Up-to-date Unreal Engine offsets for Fortnite, dumped as both a C++ header (`offsets.h`) and JSON (`offsets.json`).

| | |
|---|---|
| **Last updated** | August 28, 2026 |
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
| [`Uworld.h`](Uworld.h) | GEngine → GameViewport → UWorld resolve |
| [`Camera.h`](Camera.h) | Location / rotation pointers, FOV, world-to-screen |
| [`PlayerName.h`](PlayerName.h) | Player name decrypt from `PlayerState` |
| [`DecryptWeapon.h`](DecryptWeapon.h) | Current weapon name from pawn |
| [`VisCheck.h`](VisCheck.h) | Visibility check via `Seconds` vs `LastRenderTime` |
| [`RankedProgress.h`](RankedProgress.h) | Ranked tier from `HabaneroComponent` |
| [`Matrix.h`](Matrix.h) | `FTransform` / matrix helpers for bones |

---

## How to use

Drop `offsets.h` into your project and include it:

```cpp
#include "offsets.h"

auto uworld = Read<uintptr_t>(base + offsets::core::UWORLD);
auto mesh   = Read<uintptr_t>(pawn + offsets::player::Mesh);
```

If you load offsets at runtime instead of compiling them in, parse `offsets.json`. The keys match the C++ names.

---

## Main offsets

Values are copied from `offsets.h`. Globals (`UWORLD`, `gEngine`) are relative to the game module base. Everything else is a class member offset.

### Core / world

| Name | Offset | Notes |
|---|---|---|
| **UWorld** | `0x1B315998` | Global. `base + UWORLD` |
| **UEngine** (`gEngine`) | `0x1B3172F8` | Global. `base + gEngine` |
| **GameViewport** | `0xB70` | `UEngine` → `GameViewport` |
| **GameInstance** | `0x248` | `UWorld` → `GameInstance` |
| **GameState** | `0x1D0` | `UWorld` → `GameState` |
| **RootComponent** | `0x1B0` | Actor → `RootComponent` |
| **ComponentToWorld** | `0x1E0` | Component → world transform |
| **BoneArray** | `0x660` | Mesh bone array |
| **BoneArray_cache** | `0x670` | Cached bone array |
| **PlayerArray** | `0x288` | `GameState` → players |
| **RelativeLocation** | `0x140` | Component relative location |
| **Location pointer** | `0x170` | `UWorld` camera location ptr |
| **Rotation pointer** | `0x180` | `UWorld` camera rotation ptr |
| **Seconds** | `0x190` | `UWorld` world time (double) |
| **FOV** | `0x374` | `PlayerController` FOV |
| **ServerWorldTime** | `0x2A0` | Server world time |
| **LastRenderTime** | `0x338` | Mesh last render (visibility) |
| **PersistentLevel** | `0x38` | `UWorld` → persistent level |
| **Levels** | `0x1E8` | `UWorld` → levels |
| **Actors** | `0x210` | Level → actor array |
| **ReviveFromDBNOTime** | `0x4A78` | DBNO revive timer |
| **LifespanAfterDeath** | `0x10A8` | Time after death |
| **ServerCriticalHealth** | `0x1BFC` | Critical health |
| **CachedComponentSpaceTransforms** | `0x9D0` | Cached component transforms |
| **CurrentReadComponentTransforms** | `0x48` | Current read transforms |

### Player

| Name | Offset | Notes |
|---|---|---|
| **Mesh** | `0x2F0` | Pawn → skeletal mesh |
| **LocalPlayers** | `0x38` | `GameInstance` → local players |
| **PlayerController** | `0x30` | LocalPlayer → controller |
| **LocalPawn** | `0x318` | Controller → acknowledged pawn |
| **PawnPrivate** | `0x2E8` | PlayerState → pawn |
| **PlayerState** | `0x290` | Pawn → player state |
| **PlayerName** | `0x9E8` | PlayerState name (`FString`, encrypted) |
| **KillScore** | `0xF78` | PlayerState kills |
| **Platform** | `0x400` | PlayerState platform string |
| **TeamIndex** | `0xF61` | Team index |
| **bIsDying** | `0x728` | Dying flag |
| **bIsDBNO** | `0x851` | Knocked / DBNO flag |
| **bIsABot** | `0x27A` | Bot flag |
| **bIsCrouched** | `0x430` | Crouch flag |
| **HabaneroComponent** | `0x918` | Ranked component |

### Weapon

| Name | Offset | Notes |
|---|---|---|
| **CurrentWeapon** | `0x9A0` | Pawn → current weapon |
| **WeaponData** | `0x608` | Weapon → item definition |
| **ItemName** | `0x38` | Weapon data display name |
| **AmmoCount** | `0x1140` | Current ammo |
| **bIsReloadingWeapon** | `0x359` | Reloading flag |
| **LastFireTime** | `0x104C` | Last fire timestamp |
| **LastFireTimeVerified** | `0x1054` | Verified last fire |
| **LastDamagedTime** | `0xDB8` | Last damaged time |
| **ProjectileSpeed** | `0x2490` | Projectile muzzle speed |
| **ProjectileGravity** | `0x2494` | Projectile gravity scale |
| **ComponentVelocity** | `0x188` | Component velocity |

### Aim

| Name | Offset | Notes |
|---|---|---|
| **TargetedFortPawn** | `0x16C0` | Pawn currently under targeting |
| **LocationUnderReticle** | `0x2188` | World location under reticle |
| **PlayerAimOffset** | `0x2310` | Player aim offset |
| **NetConnection** | `0x4A8` | PlayerController net connection |
| **RotationInput** | `0x4B0` | Rotation input |
| **WeaponOffsetCorrection** | `0x2340` | Weapon offset correction |
| **WeaponRecoilOffset** | `0x2328` | Weapon recoil offset |

### Loot

| Name | Offset | Notes |
|---|---|---|
| **SpawnSourceOverride** | `0xB78` | Loot spawn source |
| **SearchedFlags** | `0xCE2` | Chest / container searched |
| **SearchText** | `0xD38` | Search prompt text |
| **ChosenRandomUpgrade** | `0xBC4` | Random upgrade |

### Pickup

| Name | Offset | Notes |
|---|---|---|
| **SimulatingTooLongLength** | `0x290` | Pickup sim timeout |
| **PrimaryPickupItemEntry** | `0x368` | Primary item entry |
| **ItemEntryItemDefinition** | `0x10` | Entry → item definition |
| **ItemDefinitionName** | `0x38` | Item definition name |
| **ItemDefinitionDataList** | `0x68` | Item definition data list |
| **ItemEntryItemDataList** | `0x28` | Entry data list |
| **WeaponDisplayTier** | `0x296` | Display tier / rarity |
| **RarityStruct** | `0x187DABE8` | Global rarity struct |
| **PickupFlags** | `0x28C` | Pickup flags |
| **PickupExtendedFlags** | `0x28D` | Extended pickup flags |
| **PickupLocationData** | `0x410` | Pickup location data |

---

## Common pointer chain

Typical resolve from module base to local pawn and mesh:

```text
base
 ├─ + UWORLD            → UWorld
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
 │    ├─ + LocationPointer / RotationPointer / Seconds
 │    └─ + GameViewport (via GEngine, see Uworld.h)
 │
 pawn
 ├─ + Mesh              → skeletal mesh (BoneArray / BoneArray_cache)
 ├─ + RootComponent     → ComponentToWorld, RelativeLocation
 ├─ + PlayerState       → PlayerName, KillScore, Platform, TeamIndex
 └─ + CurrentWeapon     → WeaponData, AmmoCount, ProjectileSpeed, ProjectileGravity
```

Alternate UWorld resolve (from `Uworld.h`):

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

- **Patch cadence** — Fortnite ships updates often. Globals like `UWORLD` and `gEngine` almost always move. Member offsets move less often but still can.
- **Two copies** — Keep `offsets.h` and `offsets.json` in sync. If you only update one, the other will be stale.
- **Names** — `PlayerName` is encrypted. Use the decrypt in `PlayerName.h`, do not treat it as a raw string.
- **Visibility** — `VisCheck.h` treats a mesh as hidden if `Seconds - LastRenderTime > 0.06`.
- **Ranked** — `HabaneroComponent` is on `PlayerState`. Ranked tier is read from that component (see `RankedProgress.h`).
- **Validation** — Always null-check pointers (`UWorld`, pawn, mesh, weapon). A bad chain is the usual cause of crashes after an update.

Offsets outdated? Ping **[@ReadAccess](https://t.me/ReadAccess)** on Telegram.
