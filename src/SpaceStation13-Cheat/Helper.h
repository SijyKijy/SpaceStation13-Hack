#pragma once
#include <Windows.h>
#include <vector>

DWORD GetPointerAddress(DWORD ptr, std::vector<DWORD> offsets);
