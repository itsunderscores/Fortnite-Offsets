uintptr_t gengine  = Read<uintptr_t>(base + GEngine);           // GEngine*
uintptr_t viewport = Read<uintptr_t>(gengine + 0xB70);          // UEngine::GameViewport
uintptr_t uworld   = Read<uintptr_t>(viewport + 0x78);          // UGameViewportClient::World
