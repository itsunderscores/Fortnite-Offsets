inline std::string DecryptWeapon(uintptr_t Player)
{
	uint64_t current_weapon = memory.read<uint64_t>((uintptr_t)Player + offsets::weapon::CurrentWeapon);
	uint64_t weapon_data    = memory.read<uint64_t>(current_weapon + offsets::weapon::WeaponData);
	if (!is_valid_address(weapon_data) || !offsets::weapon::ItemName)
		return _s("Pickaxe");

	const std::string weapon_name = read_ftext_display_string(
		memory.read<uintptr_t>(weapon_data + offsets::weapon::ItemName));
	return weapon_name.empty() ? _s("Pickaxe") : weapon_name;
}

weaponname = DecryptWeapon(pawn);
