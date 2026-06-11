#include <string>
#include <vector>
#include <cctype>

std::string DecryptUsername(uintptr_t PlayerState)
{
    // Step 1: Read FString pointer from PlayerState
    auto Name = memory.read<uintptr_t>(PlayerState + offsets::player::PlayerName);

    // Step 2: Read FString fields
    auto length = memory.read<int>(Name + 0x10);          // FString length
    auto v6     = (__int64)length;

    if (length <= 0 || length > 255)
        return "AI";  // invalid / bot / NPC

    auto FText = (uintptr_t)memory.read<__int64>(Name + 0x8);  // FString data pointer

    wchar_t* Buffer = new wchar_t[length];
    driver.ReadPhysicalMemory((PVOID)FText, Buffer, length * sizeof(wchar_t));

    char v21;
    int v22;
    int i;
    int v25;
    UINT16* v23;

    v21 = v6 - 1;
    if (!(UINT32)v6)
        v21 = 0;

    v22 = 0;
    v23 = (UINT16*)Buffer;

    for (i = (v21) & 3; ; *v23++ += i & 7)
    {
        v25 = v6 - 1;
        if (!(UINT32)v6)
            v25 = 0;

        if (v22 >= v25)
            break;

        i += 3;
        ++v22;
    }

    // Step 5: Convert to std::string
    std::wstring PlayerName{ Buffer };
    delete[] Buffer;

    return std::string(PlayerName.begin(), PlayerName.end());
}
