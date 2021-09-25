#include <Windows.h>
#include <iostream>
#include "Helper.h"
#include "Addresses.h"

DWORD WINAPI Main(HMODULE hModule) {
	DWORD byondcoreModule = (DWORD)GetModuleHandle("byondcore.dll");

	int* fullbright = (int*)GetPointerAddress(byondcoreModule + Addresses::Fullbright_adr, Addresses::Fullbright_offsets);
	int* wallhack = (int*)GetPointerAddress(byondcoreModule + Addresses::Wallhack_adr, Addresses::Wallhack_offsets);

	bool isfullbrightActivate = false; bool iswallhackActivate = false;

	while (!GetAsyncKeyState(VK_INSERT))
	{
		// Wallhack
		if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
			iswallhackActivate = !iswallhackActivate;
			if (!iswallhackActivate) *wallhack = Addresses::Wallhack_off;
		}

		if (iswallhackActivate) {
			*wallhack = Addresses::Wallhack_on;
		}

		// Fullbright
		if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
			isfullbrightActivate = !isfullbrightActivate;
			if (!isfullbrightActivate) *fullbright = Addresses::Fullbright_off;
		}

		if (isfullbrightActivate){
			*fullbright = Addresses::Fullbright_on;
		}
	}

	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr));
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

