namespace offsets {
    namespace core {
        constexpr std::uintptr_t UWORLD = 0x1A821DE8;
        constexpr std::uintptr_t gEngine = 0x1a823758;
        constexpr std::uintptr_t GameViewport = 0xB70;
        constexpr std::uintptr_t GameInstance = 0x248;
        constexpr std::uintptr_t GameState = 0x1D0;
        constexpr std::uintptr_t RootComponent = 0x1B0;
        constexpr std::uintptr_t ComponentToWorld = 0x1E0;
        constexpr std::uintptr_t BoneArray = 0x660;
        constexpr std::uintptr_t BoneArray_cache = 0x670;
        constexpr std::uintptr_t PlayerArray = 0x288;
        constexpr std::uintptr_t RelativeLocation = 0x140;
        constexpr std::uintptr_t LocationPointer = 0x170;
        constexpr std::uintptr_t RotationPointer = 0x180;
        constexpr std::uintptr_t Seconds = 0x190;
        constexpr std::uintptr_t FOV = 0x374;
        constexpr std::uintptr_t ServerWorldTime = 0x2A0;
        constexpr std::uintptr_t LastRenderTime = 0x2E0;
        constexpr std::uintptr_t PersistentLevel = 0x38;
        constexpr std::uintptr_t Levels = 0x1E8;
        constexpr std::uintptr_t Actors = 0x158;
        constexpr std::uintptr_t ReviveFromDBNOTime = 0x4AC8;
        constexpr std::uintptr_t LifespanAfterDeath = 0x10A8;
        constexpr std::uintptr_t ServerCriticalHealth = 0x1BFC;
        constexpr std::uintptr_t CachedComponentSpaceTransforms = 0xA20;
        constexpr std::uintptr_t CurrentReadComponentTransforms = 0x48;
    }

    namespace player {
        constexpr std::uintptr_t Mesh = 0x2F0;
        constexpr std::uintptr_t LocalPlayers = 0x38;
        constexpr std::uintptr_t PlayerController = 0x30;
        constexpr std::uintptr_t LocalPawn = 0x318;
        constexpr std::uintptr_t PawnPrivate = 0x2E8;
        constexpr std::uintptr_t PlayerState = 0x290;
        constexpr std::uintptr_t TeamIndex = 0xf61;
        constexpr std::uintptr_t PlayerName = 0x9E8;
        constexpr std::uintptr_t KillScore = 0xf78;
        constexpr std::uintptr_t Platform = 0x400;
        constexpr std::uintptr_t bIsDying = 0x728;
        constexpr std::uintptr_t bIsDBNO = 0x851;
        constexpr std::uintptr_t bIsABot = 0x27A;
        constexpr std::uintptr_t bIsCrouched = 0x430;
        constexpr std::uintptr_t HabaneroComponent = 0x918;
    }

    namespace weapon {
        constexpr std::uintptr_t CurrentWeapon = 0x9D0;
        constexpr std::uintptr_t WeaponData = 0x6B0;
        constexpr std::uintptr_t ItemName = 0x38;
        constexpr std::uintptr_t AmmoCount = 0x1180;
        constexpr std::uintptr_t bIsReloadingWeapon = 0x371;
        constexpr std::uintptr_t LastFireTime = 0x108C;
        constexpr std::uintptr_t LastFireTimeVerified = 0x1094;
        constexpr std::uintptr_t LastDamagedTime = 0xDE8;
        constexpr std::uintptr_t ProjectileSpeed = 0x1e38;
        constexpr std::uintptr_t ProjectileGravity = 0x1e3c;
        constexpr std::uintptr_t ComponentVelocity = 0x188;
    }

    namespace aim {
        constexpr std::uintptr_t TargetedFortPawn = 0x16C0;
        constexpr std::uintptr_t LocationUnderReticle = 0x2188;
        constexpr std::uintptr_t NetConnection = 0x4A8;
        constexpr std::uintptr_t RotationInput = 0x4B0;
        constexpr std::uintptr_t WeaponOffsetCorrection = 0x2340;
        constexpr std::uintptr_t WeaponRecoilOffset = 0x2328;
        constexpr std::uintptr_t PlayerAimOffset = 0x2310;
    }

    namespace loot {
        constexpr std::uintptr_t SpawnSourceOverride = 0xB78;
        constexpr std::uintptr_t SearchedFlags = 0xCE2;
        constexpr std::uintptr_t SearchText = 0xD38;
        constexpr std::uintptr_t ChosenRandomUpgrade = 0xBC4;
    }

    namespace pickup {
        constexpr std::uintptr_t SimulatingTooLongLength = 0x290;
        constexpr std::uintptr_t PrimaryPickupItemEntry = 0x368;
        constexpr std::uintptr_t ItemEntryItemDefinition = 0x10;
        constexpr std::uintptr_t ItemDefinitionName = 0x38;
        constexpr std::uintptr_t ItemDefinitionDataList = 0x68;
        constexpr std::uintptr_t ItemEntryItemDataList = 0x28;
        constexpr std::uintptr_t WeaponDisplayTier = 0x296;
        constexpr std::uintptr_t RarityStruct = 0x17D4B9E8;
        constexpr std::uintptr_t PickupFlags = 0x28C;
        constexpr std::uintptr_t PickupExtendedFlags = 0x28D;
        constexpr std::uintptr_t PickupLocationData = 0x410;
    }
}
