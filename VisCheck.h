bool IsEnemyVisible(uintptr_t Mesh) {
	auto Seconds = memory.read<double>(cache::uworld + offsets::core::Seconds);
	auto LastRenderTime = memory.read<float>(Mesh + offsets::core::LastRenderTime);
	if (Seconds - LastRenderTime > 0.06f) return false;

	return true;
}
