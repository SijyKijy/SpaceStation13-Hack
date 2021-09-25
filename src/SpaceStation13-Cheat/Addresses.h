#pragma once
#include <Windows.h>
#include <vector>

namespace Addresses {
	// Fullbright
	DWORD Fullbright_adr = 0x0035D3D8;
	std::vector<DWORD> Fullbright_offsets = { 0x0, 0x4, 0x10, 0x90, 0x190 };
	int Fullbright_on = 17785856;
	int Fullbright_off = 18441216;

	// Wallhack
	DWORD Wallhack_adr = 0x0035D3D8;
	std::vector<DWORD> Wallhack_offsets = { 0x0, 0x10, 0x90, 0x18C };
	int Wallhack_on = 60;
	int Wallhack_off = 0;
}