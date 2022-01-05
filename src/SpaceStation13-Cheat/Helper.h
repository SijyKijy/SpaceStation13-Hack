#pragma once
#include <Windows.h>
#include <vector>

DWORD GetPointerAddress(DWORD ptr, std::vector<DWORD> offsets);
uint8_t* AOBScan(void* module, const char* signature);
void Patch(char* dst, char* src, int size);
void Nop(char* dst, unsigned int size);
