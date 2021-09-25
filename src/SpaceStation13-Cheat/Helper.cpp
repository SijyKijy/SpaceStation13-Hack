#include "Helper.h"

DWORD GetPointerAddress(DWORD address, std::vector<DWORD> offsets)
{
    DWORD newAddress = address;
    for (int i = 0; i < offsets.size(); ++i)
    {
        newAddress = *(DWORD*)newAddress;
        newAddress += offsets[i];
    }

    return newAddress;
}