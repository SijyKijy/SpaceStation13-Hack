#include <Windows.h>
#include <iostream>
#include "Helper.h"
#include "Addresses.h"

DWORD WINAPI Main(HMODULE hModule) {
	HMODULE byondcoreModule = GetModuleHandle("byondcore.dll");

	char* fullbrightAddr = (char*)AOBScan(byondcoreModule, Addresses::Fullbright_pattern);
	char* wallhackAddr = (char*)AOBScan(byondcoreModule, Addresses::Wallhack_pattern);

	bool isfullbrightActivate = false; bool iswallhackActivate = false;

	while (!GetAsyncKeyState(VK_INSERT))
	{
		// Wallhack
		if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
			iswallhackActivate = !iswallhackActivate;

			int size = sizeof(Addresses::Wallhack_on) - 1;

			if (iswallhackActivate)
				Patch(wallhackAddr, Addresses::Wallhack_on, size);
			else
				Patch(wallhackAddr, Addresses::Wallhack_off, size);
		}

		// Fullbright
		if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
			isfullbrightActivate = !isfullbrightActivate;

			int size = sizeof(Addresses::Fullbright_on) - 1;

			if (isfullbrightActivate)
				Patch(fullbrightAddr, Addresses::Fullbright_on, size);
			else
				Patch(fullbrightAddr, Addresses::Fullbright_off, size);
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
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr));
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

