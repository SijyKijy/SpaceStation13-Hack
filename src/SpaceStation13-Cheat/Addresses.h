#pragma once
#include <Windows.h>
#include <vector>

namespace Addresses {

	// Wallhack
	const char* Wallhack_pattern = "8B 93 24 02 00 00";
	char Wallhack_off[] = "\x8B\x93\x24\x02\x00\x00";
	char Wallhack_on[] = "\xBA\x3C\x00\x00\x00\x90";

	// Fullbright
	const char* Fullbright_pattern = "0F B6 83 29 02 00 00";
	char Fullbright_off[] = "\x0F\xB6\x83\x29\x02\x00\x00";
	char Fullbright_on[] = "\xB8\x55\x02\x00\x00\x66\x90";
}