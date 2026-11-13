namespace offsets {
    namespace core {
        constexpr std::uintptr_t UWORLD = 0x1C9DA790; // GWorld
        constexpr std::uintptr_t gEngine = 0x1C9DC1D8; // GEngine
        constexpr std::uintptr_t GameViewport = 0xB70; // GameViewport (calculated)
        constexpr std::uintptr_t GameInstance = 0x238; // UWorld::OwningGameInstance
        constexpr std::uintptr_t GameState = 0x1C0; // UWorld::GameState
        constexpr std::uintptr_t RootComponent = 0x1B0; // AActor::RootComponent
        constexpr std::uintptr_t ComponentToWorld = 0x1E0; // USceneComponent::ComponentToWorld
        constexpr std::uintptr_t BoneArray = 0x650; // BoneArray (calculated)
        constexpr std::uintptr_t BoneArray_cache = 0x660; // BoneArray_cache (calculated)
        constexpr std::uintptr_t PlayerArray = 0x290; // PlayerArray (calculated)
        constexpr std::uintptr_t RelativeLocation = 0x140; // USceneComponent::RelativeLocation
        constexpr std::uintptr_t LocationPointer = 0x168; // LocationPointer (calculated)
        constexpr std::uintptr_t RotationPointer = 0x178; // RotationPointer (calculated)
        constexpr std::uintptr_t Seconds = 0x188; // Seconds (calculated)
        constexpr std::uintptr_t FOV = 0x37c; // FOV (calculated)
        constexpr std::uintptr_t ServerWorldTime = 0x2B0; // AGameStateBase::ServerWorldTimeSeconds
        constexpr std::uintptr_t LastRenderTime = 0x328; // LastRenderTime (calculated)
        constexpr std::uintptr_t PersistentLevel = 0x40; // UWorld::PersistentLevel
        constexpr std::uintptr_t Levels = 0x1D8; // Levels (calculated)
        constexpr std::uintptr_t Actors = 0x1D8; // Actors (calculated)
        constexpr std::uintptr_t ReviveFromDBNOTime = 0x4e30; // AFortPlayerPawnAthena::ReviveFromDBNOTime
        constexpr std::uintptr_t LifespanAfterDeath = 0x10d0; // AFortAthenaVehicle::LifespanAfterDeath
        constexpr std::uintptr_t ServerCriticalHealth = 0x1c5c; // AFortAthenaVehicle::ServerCriticalHealth
        constexpr std::uintptr_t CachedComponentSpaceTransforms = 0xa40; // USkinnedMeshComponent::CachedComponentSpaceTransforms
        constexpr std::uintptr_t CurrentReadComponentTransforms = 0x48; // CurrentReadComponentTransforms (calculated)
    }

    namespace player {
        constexpr std::uintptr_t Mesh = 0x2F8; // ACharacter::Mesh
        constexpr std::uintptr_t LocalPlayers = 0x38; // UGameInstance::LocalPlayers
        constexpr std::uintptr_t PlayerController = 0x30; // UPlayer::PlayerController
        constexpr std::uintptr_t LocalPawn = 0x320; // APlayerController::AcknowledgedPawn
        constexpr std::uintptr_t PawnPrivate = 0x2F0; // APlayerState::PawnPrivate
        constexpr std::uintptr_t PlayerState = 0x298; // APawn::PlayerState
        constexpr std::uintptr_t TeamIndex = 0xF81; // AFortPlayerStateAthena::TeamIndex
        constexpr std::uintptr_t PlayerName = 0x9F0; // PlayerName (calculated)
        constexpr std::uintptr_t KillScore = 0xF98; // AFortPlayerStateAthena::KillScore
        constexpr std::uintptr_t Platform = 0x408; // AFortPlayerState::Platform
        constexpr std::uintptr_t bIsDying = 0x738; // AFortPawn::bIsDying
        constexpr std::uintptr_t bIsDBNO = 0x892; // AFortPawn::bIsDBNO
        constexpr std::uintptr_t bIsABot = 0x282; // AFortPlayerStateAthena::bIsABot
        constexpr std::uintptr_t bIsCrouched = 0x440; // ACharacter::bIsCrouched
        constexpr std::uintptr_t HabaneroComponent = 0x920; // AFortPlayerStateAthena::HabaneroComponent
    }

    namespace weapon {
        constexpr std::uintptr_t CurrentWeapon = 0x9E0; // AFortPawn::CurrentWeapon
        constexpr std::uintptr_t WeaponData = 0x6d0; // AFortWeapon::WeaponData
        constexpr std::uintptr_t ItemName = 0x38; // UItemDefinitionBase::ItemName
        constexpr std::uintptr_t AmmoCount = 0x11e0; // AFortWeapon::AmmoCount
        constexpr std::uintptr_t bIsReloadingWeapon = 0x379; // AFortWeapon::bIsReloadingWeapon
        constexpr std::uintptr_t LastFireTime = 0x10dc; // AFortWeapon::LastFireTime
        constexpr std::uintptr_t LastFireTimeVerified = 0x10e4; // AFortWeapon::LastFireTimeVerified
        constexpr std::uintptr_t LastDamagedTime = 0xE40; // AFortWeapon::LastDamagedTime
        constexpr std::uintptr_t ProjectileSpeed = 0x2540; // UProjectileMovementComponent::InitialSpeed
        constexpr std::uintptr_t ProjectileGravity = 0x2544; // UProjectileMovementComponent::ProjectileGravityScale
        constexpr std::uintptr_t ComponentVelocity = 0x188; // USceneComponent::ComponentVelocity
    }

    namespace aim {
        constexpr std::uintptr_t TargetedFortPawn = 0x1750; // AFortPlayerController::TargetedFortPawn
        constexpr std::uintptr_t LocationUnderReticle = 0x2218; // AFortPlayerController::LocationUnderReticle
        constexpr std::uintptr_t NetConnection = 0x4B0; // NetConnection (calculated)
        constexpr std::uintptr_t RotationInput = 0x4B8; // APlayerController::RotationInput
        constexpr std::uintptr_t WeaponOffsetCorrection = 0x23d0; // AFortWeapon::WeaponOffsetCorrection
        constexpr std::uintptr_t WeaponRecoilOffset = 0x23b8; // AFortWeapon::WeaponRecoilOffset
        constexpr std::uintptr_t PlayerAimOffset = 0x23a0; // AFortWeapon::PlayerAimOffset
    }

    namespace loot {
        constexpr std::uintptr_t SpawnSourceOverride = 0xBC0; // AFortPickup::SpawnSourceOverride
        constexpr std::uintptr_t SearchedFlags = 0xD2A; // BuildingContainer::SearchedFlags
        constexpr std::uintptr_t SearchText = 0xD80; // BuildingContainer::SearchText
        constexpr std::uintptr_t ChosenRandomUpgrade = 0xC0C; // BuildingContainer::ChosenRandomUpgrade
    }

    namespace pickup {
        constexpr std::uintptr_t SimulatingTooLongLength = 0x298; // AFortPickup::SimulatingTooLongLength
        constexpr std::uintptr_t PrimaryPickupItemEntry = 0x370; // AFortPickup::PrimaryPickupItemEntry
        constexpr std::uintptr_t ItemEntryItemDefinition = 0x10; // FFortItemEntry::ItemDefinition
        constexpr std::uintptr_t ItemDefinitionName = 0x38; // UItemDefinitionBase::ItemName
        constexpr std::uintptr_t ItemDefinitionDataList = 0x68; // UFortItemDefinition::ItemDataList
        constexpr std::uintptr_t ItemEntryItemDataList = 0x28; // FFortItemEntry::ItemDataList
        constexpr std::uintptr_t WeaponDisplayTier = 0x296; // UFortItemDefinition::Tier
        constexpr std::uintptr_t RarityStruct = 0x19C10580; // GRarityStruct
        constexpr std::uintptr_t PickupFlags = 0x294; // AFortPickup::PickupFlags
        constexpr std::uintptr_t PickupExtendedFlags = 0x295; // AFortPickup::PickupExtendedFlags
        constexpr std::uintptr_t PickupLocationData = 0x418; // AFortPickup::PickupLocationData
    }
}
