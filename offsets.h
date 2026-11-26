namespace offsets
{
    namespace core
    {
        constexpr std::uintptr_t UWORLD = 0x1C14D610; // GWorld (calculated)
        constexpr std::uintptr_t gEngine = 0x1C14F058; // GEngine (calculated)
        constexpr std::uintptr_t GameViewport = 0xB70; // Engine::GameViewport
        constexpr std::uintptr_t GameInstance = 0x248; // UWorld::OwningGameInstance
        constexpr std::uintptr_t GameState = 0x1D0; // UWorld::GameState
        constexpr std::uintptr_t RootComponent = 0x1B0; // AActor::RootComponent
        constexpr std::uintptr_t ComponentToWorld = 0x1E0; // USceneComponent::ComponentToWorld (calculated)
        constexpr std::uintptr_t BoneArray = 0x660; // BoneArray (calculated)
        constexpr std::uintptr_t BoneArray_cache = 0x670; // BoneArray_cache (calculated)
        constexpr std::uintptr_t PlayerArray = 0x290; // GameStateBase::PlayerArray
        constexpr std::uintptr_t RelativeLocation = 0x140; // USceneComponent::RelativeLocation
        constexpr std::uintptr_t LocationPointer = 0x170; // LocationPointer (calculated)
        constexpr std::uintptr_t RotationPointer = 0x180; // RotationPointer (calculated)
        constexpr std::uintptr_t Seconds = 0x190; // Seconds (calculated)
        constexpr std::uintptr_t FOV = 0x37C; // FOV (calculated)
        constexpr std::uintptr_t ServerWorldTime = 0x2B0; // AGameStateBase::ServerWorldTimeSecondsDelta
        constexpr std::uintptr_t LastRenderTime = 0x290; // LastRenderTime (calculated)
        constexpr std::uintptr_t PersistentLevel = 0x38; // UWorld::PersistentLevel
        constexpr std::uintptr_t Levels = 0x1E8; // World::Levels
        constexpr std::uintptr_t Actors = 0x208; // Actors (calculated)
        constexpr std::uintptr_t ReviveFromDBNOTime = 0x4E60; // AFortPlayerPawnAthena::ReviveFromDBNOTime
        constexpr std::uintptr_t LifespanAfterDeath = 0x10D0; // AFortAthenaVehicle::LifespanAfterDeath
        constexpr std::uintptr_t ServerCriticalHealth = 0x1C5C; // AFortAthenaVehicle::ServerCriticalHealth
        constexpr std::uintptr_t CachedComponentSpaceTransforms = 0x9C8; // USkinnedMeshComponent::CachedComponentSpaceTransforms
        constexpr std::uintptr_t CurrentReadComponentTransforms = 0x48; // CurrentReadComponentTransforms (calculated)
    }

    namespace player
    {
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
        constexpr std::uintptr_t bIsDying = 0x770; // AFortPawn::bIsDying
        constexpr std::uintptr_t bIsDBNO = 0x8CA; // AFortPawn::bIsDBNO
        constexpr std::uintptr_t bIsABot = 0x282; // AFortPlayerStateAthena::bIsABot
        constexpr std::uintptr_t bIsCrouched = 0x440; // ACharacter::bIsCrouched
        constexpr std::uintptr_t HabaneroComponent = 0x920; // AFortPlayerState::HabaneroComponent
    }

    namespace weapon
    {
        constexpr std::uintptr_t CurrentWeapon = 0xA18; // AFortPawn::CurrentWeapon
        constexpr std::uintptr_t WeaponData = 0x658; // AFortWeapon::WeaponData
        constexpr std::uintptr_t ItemName = 0x38; // UItemDefinitionBase::ItemName
        constexpr std::uintptr_t AmmoCount = 0x1188; // AFortWeapon::AmmoCount
        constexpr std::uintptr_t bIsReloadingWeapon = 0x371; // AFortWeapon::bIsReloadingWeapon
        constexpr std::uintptr_t LastFireTime = 0x1084; // AFortWeapon::LastFireTime
        constexpr std::uintptr_t LastFireTimeVerified = 0x108C; // AFortWeapon::LastFireTimeVerified
        constexpr std::uintptr_t LastDamagedTime = 0xE70; // AFortPawn::LastDamagedTime
        constexpr std::uintptr_t ProjectileSpeed = 0x213C; // ProjectileSpeed (calculated)
        constexpr std::uintptr_t ProjectileGravity = 0x2140; // ProjectileGravity (calculated)
        constexpr std::uintptr_t ComponentVelocity = 0x188; // USceneComponent::ComponentVelocity
    }

    namespace aim
    {
        constexpr std::uintptr_t TargetedFortPawn = 0x1750; // AFortPlayerController::TargetedFortPawn
        constexpr std::uintptr_t LocationUnderReticle = 0x2218; // AFortPlayerController::LocationUnderReticle
        constexpr std::uintptr_t NetConnection = 0x4B0; // PlayerController::NetConnection
        constexpr std::uintptr_t RotationInput = 0x4B8; // NetConnection + 0x08
        constexpr std::uintptr_t WeaponOffsetCorrection = 0x23D0; // AFortPlayerController::WeaponOffsetCorrection
        constexpr std::uintptr_t WeaponRecoilOffset = 0x23B8; // AFortPlayerController::WeaponRecoilOffset
        constexpr std::uintptr_t PlayerAimOffset = 0x23A0; // AFortPlayerController::PlayerAimOffset
    }

    namespace loot
    {
        constexpr std::uintptr_t SpawnSourceOverride = 0xBC0; // ABuildingContainer::SpawnSourceOverride
        constexpr std::uintptr_t SearchedFlags = 0xD2A; // ABuildingContainer::bAlreadySearched
        constexpr std::uintptr_t SearchText = 0xD80; // ABuildingContainer::SearchText
        constexpr std::uintptr_t ChosenRandomUpgrade = 0xC0C; // ABuildingContainer::ChosenRandomUpgrade
    }

    namespace pickup
    {
        constexpr std::uintptr_t SimulatingTooLongLength = 0x298; // AFortPickup::SimulatingTooLongLength
        constexpr std::uintptr_t PrimaryPickupItemEntry = 0x370; // AFortPickup::PrimaryPickupItemEntry
        constexpr std::uintptr_t ItemEntryItemDefinition = 0x10; // FItemEntry::ItemDefinition
        constexpr std::uintptr_t ItemDefinitionName = 0x38; // ItemDefinitionBase::ItemName
        constexpr std::uintptr_t ItemDefinitionDataList = 0x68; // UFortItemDefinition::DataList
        constexpr std::uintptr_t ItemEntryItemDataList = 0x28; // FItemEntry::ItemData
        constexpr std::uintptr_t WeaponDisplayTier = 0x296; // UFortItemDefinition::Tier or FortWeaponItemDefinition::DisplayTier
        constexpr std::uintptr_t RarityStruct = 0x1944CB50; // GRarityStruct (calculated)
        constexpr std::uintptr_t PickupFlags = 0x294; // AFortPickup::bPickedUp
        constexpr std::uintptr_t PickupExtendedFlags = 0x295; // AFortPickup::bClientUseInterpolationOnly
        constexpr std::uintptr_t PickupLocationData = 0x418; // AFortPickup::PickupLocationData
    }

}
