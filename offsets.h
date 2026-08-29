namespace offsets
{
	namespace core
	{
		constexpr uintptr_t UWORLD = 0x1B315998;
		constexpr uintptr_t gEngine = 0x1B3172F8;
		constexpr uintptr_t GameViewport = 0xB70;
		constexpr uintptr_t GameInstance = 0x248;
		constexpr uintptr_t GameState = 0x1D0;
		constexpr uintptr_t RootComponent = 0x1B0;
		constexpr uintptr_t ComponentToWorld = 0x1E0;
		constexpr uintptr_t BoneArray = 0x660;
		constexpr uintptr_t BoneArray_cache = 0x670;
		constexpr uintptr_t PlayerArray = 0x288;
		constexpr uintptr_t RelativeLocation = 0x140;
		constexpr uintptr_t LocationPointer = 0x170;
		constexpr uintptr_t RotationPointer = 0x180;
		constexpr uintptr_t Seconds = 0x190;
		constexpr uintptr_t FOV = 0x374;
		constexpr uintptr_t ServerWorldTime = 0x2A0;
		constexpr uintptr_t LastRenderTime = 0x338;
		constexpr uintptr_t PersistentLevel = 0x38;
		constexpr uintptr_t Levels = 0x1E8;
		constexpr uintptr_t Actors = 0x210;
		constexpr uintptr_t ReviveFromDBNOTime = 0x4A78;
		constexpr uintptr_t LifespanAfterDeath = 0x10A8;
		constexpr uintptr_t ServerCriticalHealth = 0x1BFC;
		constexpr uintptr_t CachedComponentSpaceTransforms = 0x9D0;
		constexpr uintptr_t CurrentReadComponentTransforms = 0x48;
	}

	namespace player
	{
		constexpr uintptr_t Mesh = 0x2F0;
		constexpr uintptr_t LocalPlayers = 0x38;
		constexpr uintptr_t PlayerController = 0x30;
		constexpr uintptr_t LocalPawn = 0x318;
		constexpr uintptr_t PawnPrivate = 0x2E8;
		constexpr uintptr_t PlayerState = 0x290;
		constexpr uintptr_t TeamIndex = 0xF61;
		constexpr uintptr_t PlayerName = 0x9E8;
		constexpr uintptr_t KillScore = 0xF78;
		constexpr uintptr_t Platform = 0x400;
		constexpr uintptr_t bIsDying = 0x728;
		constexpr uintptr_t bIsDBNO = 0x851;
		constexpr uintptr_t bIsABot = 0x27A;
		constexpr uintptr_t bIsCrouched = 0x430;
		constexpr uintptr_t HabaneroComponent = 0x918;
	}

	namespace weapon
	{
		constexpr uintptr_t CurrentWeapon = 0x9A0;
		constexpr uintptr_t WeaponData = 0x608;
		constexpr uintptr_t ItemName = 0x38;
		constexpr uintptr_t AmmoCount = 0x1140;
		constexpr uintptr_t bIsReloadingWeapon = 0x359;
		constexpr uintptr_t LastFireTime = 0x104C;
		constexpr uintptr_t LastFireTimeVerified = 0x1054;
		constexpr uintptr_t LastDamagedTime = 0xDB8;
		constexpr uintptr_t ProjectileSpeed = 0x2490;
		constexpr uintptr_t ProjectileGravity = 0x2494;
		constexpr uintptr_t ComponentVelocity = 0x188;
	}

	namespace aim
	{
		constexpr uintptr_t TargetedFortPawn = 0x16C0;
		constexpr uintptr_t LocationUnderReticle = 0x2188;
		constexpr uintptr_t NetConnection = 0x4A8;
		constexpr uintptr_t RotationInput = 0x4B0;
		constexpr uintptr_t WeaponOffsetCorrection = 0x2340;
		constexpr uintptr_t WeaponRecoilOffset = 0x2328;
		constexpr uintptr_t PlayerAimOffset = 0x2310;
	}

	namespace loot
	{
		constexpr uintptr_t SpawnSourceOverride = 0xB78;
		constexpr uintptr_t SearchedFlags = 0xCE2;
		constexpr uintptr_t SearchText = 0xD38;
		constexpr uintptr_t ChosenRandomUpgrade = 0xBC4;
	}

	namespace pickup
	{
		constexpr uintptr_t SimulatingTooLongLength = 0x290;
		constexpr uintptr_t PrimaryPickupItemEntry = 0x368;
		constexpr uintptr_t ItemEntryItemDefinition = 0x10;
		constexpr uintptr_t ItemDefinitionName = 0x38;
		constexpr uintptr_t ItemDefinitionDataList = 0x68;
		constexpr uintptr_t ItemEntryItemDataList = 0x28;
		constexpr uintptr_t WeaponDisplayTier = 0x296;
		constexpr uintptr_t RarityStruct = 0x187DABE8;
		constexpr uintptr_t PickupFlags = 0x28C;
		constexpr uintptr_t PickupExtendedFlags = 0x28D;
		constexpr uintptr_t PickupLocationData = 0x410;
	}
}
