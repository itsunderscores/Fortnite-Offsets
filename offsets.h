namespace offsets {
    namespace core {
        constexpr std::uintptr_t UWORLD = 0x1C9DA790;
        constexpr std::uintptr_t gEngine = 0x1C9DC1D8;
        constexpr std::uintptr_t GameViewport = 0xB70;
        constexpr std::uintptr_t GameInstance = 0x238;
        constexpr std::uintptr_t GameState = 0x1C0;
        constexpr std::uintptr_t RootComponent = 0x1B0;
        constexpr std::uintptr_t ComponentToWorld = 0x1E0;
        constexpr std::uintptr_t BoneArray = 0x660;
        constexpr std::uintptr_t BoneArray_cache = 0x670;
        constexpr std::uintptr_t PlayerArray = 0x290;
        constexpr std::uintptr_t RelativeLocation = 0x140;
        constexpr std::uintptr_t LocationPointer = 0x168;
        constexpr std::uintptr_t RotationPointer = 0x178;
        constexpr std::uintptr_t Seconds = 0x188;
        constexpr std::uintptr_t FOV = 0x37c;
        constexpr std::uintptr_t ServerWorldTime = 0x2B0;
        constexpr std::uintptr_t LastRenderTime = 0x328;
        constexpr std::uintptr_t PersistentLevel = 0x38;
        constexpr std::uintptr_t Levels = 0x1D8;
        constexpr std::uintptr_t Actors = 0x1D8;
        constexpr std::uintptr_t ReviveFromDBNOTime = 0x4e30;
        constexpr std::uintptr_t LifespanAfterDeath = 0x10d0;
        constexpr std::uintptr_t ServerCriticalHealth = 0x1c5c;
        constexpr std::uintptr_t CachedComponentSpaceTransforms = 0xa40;
        constexpr std::uintptr_t CurrentReadComponentTransforms = 0x48;
    }
 
    namespace player {
        constexpr std::uintptr_t Mesh = 0x2F8;
        constexpr std::uintptr_t LocalPlayers = 0x38;
        constexpr std::uintptr_t PlayerController = 0x30;
        constexpr std::uintptr_t LocalPawn = 0x320;
        constexpr std::uintptr_t PawnPrivate = 0x2F0;
        constexpr std::uintptr_t PlayerState = 0x298;
        constexpr std::uintptr_t TeamIndex = 0xF81;
        constexpr std::uintptr_t PlayerName = 0x9F0;
        constexpr std::uintptr_t KillScore = 0xF98;
        constexpr std::uintptr_t Platform = 0x408;
        constexpr std::uintptr_t bIsDying = 0x738;
        constexpr std::uintptr_t bIsDBNO = 0x892;
        constexpr std::uintptr_t bIsABot = 0x282;
        constexpr std::uintptr_t bIsCrouched = 0x440;
        constexpr std::uintptr_t HabaneroComponent = 0x920;
    }
 
    namespace weapon {
        constexpr std::uintptr_t CurrentWeapon = 0x9E0;
        constexpr std::uintptr_t WeaponData = 0x6d0;
        constexpr std::uintptr_t ItemName = 0x38;
        constexpr std::uintptr_t AmmoCount = 0x11e0;
        constexpr std::uintptr_t bIsReloadingWeapon = 0x379;
        constexpr std::uintptr_t LastFireTime = 0x10dc;
        constexpr std::uintptr_t LastFireTimeVerified = 0x10e4;
        constexpr std::uintptr_t LastDamagedTime = 0xE40;
        constexpr std::uintptr_t ProjectileSpeed = 0x21e4;
        constexpr std::uintptr_t ProjectileGravity = 0x21e8;
        constexpr std::uintptr_t ComponentVelocity = 0x188;
    }
 
    namespace aim {
        constexpr std::uintptr_t TargetedFortPawn = 0x1750;
        constexpr std::uintptr_t LocationUnderReticle = 0x2218;
        constexpr std::uintptr_t NetConnection = 0x4B0;
        constexpr std::uintptr_t RotationInput = 0x4B8;
        constexpr std::uintptr_t WeaponOffsetCorrection = 0x23d0;
        constexpr std::uintptr_t WeaponRecoilOffset = 0x23b8;
        constexpr std::uintptr_t PlayerAimOffset = 0x23a0;
    }
 
    namespace loot {
        constexpr std::uintptr_t SpawnSourceOverride = 0xBC0;
        constexpr std::uintptr_t SearchedFlags = 0xD2A;
        constexpr std::uintptr_t SearchText = 0xD80;
        constexpr std::uintptr_t ChosenRandomUpgrade = 0xC0C;
    }
 
    namespace pickup {
        constexpr std::uintptr_t SimulatingTooLongLength = 0x298;
        constexpr std::uintptr_t PrimaryPickupItemEntry = 0x370;
        constexpr std::uintptr_t ItemEntryItemDefinition = 0x10;
        constexpr std::uintptr_t ItemDefinitionName = 0x38;
        constexpr std::uintptr_t ItemDefinitionDataList = 0x68;
        constexpr std::uintptr_t ItemEntryItemDataList = 0x28;
        constexpr std::uintptr_t WeaponDisplayTier = 0x296;
        constexpr std::uintptr_t RarityStruct = 0x19C10580;
        constexpr std::uintptr_t PickupFlags = 0x294;
        constexpr std::uintptr_t PickupExtendedFlags = 0x295;
        constexpr std::uintptr_t PickupLocationData = 0x418;
    }
}
