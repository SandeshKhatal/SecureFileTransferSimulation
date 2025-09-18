// ServerCipher.cpp
#include"pch.h"
#include <windows.h>
#include <stdio.h>

#define MAX_SIZE 1024

// Caesar Cipher Encryption
extern "C" __declspec(dllexport) int Encrypt_Caesar_Cipher(const char* Src, const char* Dest, int Key)
{
    FILE* fSrc = nullptr;
    FILE* fDest = nullptr;
    char Buffer[MAX_SIZE];
    size_t bytes;

    if (fopen_s(&fSrc, Src, "rb") != 0) return -1;
    if (fopen_s(&fDest, Dest, "wb") != 0) { fclose(fSrc); return -2; }

    while ((bytes = fread(Buffer, 1, MAX_SIZE, fSrc)) > 0)
    {
        for (size_t i = 0; i < bytes; i++)
            Buffer[i] = Buffer[i] + Key;
        fwrite(Buffer, 1, bytes, fDest);
    }

    fclose(fSrc);
    fclose(fDest);
    return 0;
}

// Caesar Cipher Decryption
extern "C" __declspec(dllexport) int Decrypt_Caesar_Cipher(const char* Src, const char* Dest, int Key)
{
    FILE* fSrc = nullptr;
    FILE* fDest = nullptr;
    char Buffer[MAX_SIZE];
    size_t bytes;

    if (fopen_s(&fSrc, Src, "rb") != 0) return -1;
    if (fopen_s(&fDest, Dest, "wb") != 0) { fclose(fSrc); return -2; }

    while ((bytes = fread(Buffer, 1, MAX_SIZE, fSrc)) > 0)
    {
        for (size_t i = 0; i < bytes; i++)
            Buffer[i] = Buffer[i] - Key;
        fwrite(Buffer, 1, bytes, fDest);
    }

    fclose(fSrc);
    fclose(fDest);
    return 0;
}

// XOR Cipher Encryption
extern "C" __declspec(dllexport) int Encrypt_XOR_Cipher(const char* Src, const char* Dest, char Key)
{
    FILE* fSrc = nullptr;
    FILE* fDest = nullptr;
    char Buffer[MAX_SIZE];
    size_t bytes;

    if (fopen_s(&fSrc, Src, "rb") != 0) return -1;
    if (fopen_s(&fDest, Dest, "wb") != 0) { fclose(fSrc); return -2; }

    while ((bytes = fread(Buffer, 1, MAX_SIZE, fSrc)) > 0)
    {
        for (size_t i = 0; i < bytes; i++)
            Buffer[i] ^= Key;
        fwrite(Buffer, 1, bytes, fDest);
    }

    fclose(fSrc);
    fclose(fDest);
    return 0;
}

// XOR Cipher Decryption (same as encryption)
extern "C" __declspec(dllexport) int Decrypt_XOR_Cipher(const char* Src, const char* Dest, char Key)
{
    return Encrypt_XOR_Cipher(Src, Dest, Key);
}

// DLL Entry
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
