#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

// Function pointer typedefs
typedef int (*CAESAR_ENCRYPT)(const char*, const char*, int);
typedef int (*CAESAR_DECRYPT)(const char*, const char*, int);
typedef int (*XOR_ENCRYPT)(const char*, const char*, char);
typedef int (*XOR_DECRYPT)(const char*, const char*, char);

int main()
{
    HMODULE hDll = LoadLibrary(L"ServerCipher.dll");
    if (!hDll) {
        cerr << "Unable to load ServerCipher.dll" << endl;
        return -1;
    }

    // Get function addresses
    CAESAR_ENCRYPT Encrypt_Caesar_Cipher = (CAESAR_ENCRYPT)GetProcAddress(hDll, "Encrypt_Caesar_Cipher");
    CAESAR_DECRYPT Decrypt_Caesar_Cipher = (CAESAR_DECRYPT)GetProcAddress(hDll, "Decrypt_Caesar_Cipher");
    XOR_ENCRYPT Encrypt_XOR_Cipher = (XOR_ENCRYPT)GetProcAddress(hDll, "Encrypt_XOR_Cipher");
    XOR_DECRYPT Decrypt_XOR_Cipher = (XOR_DECRYPT)GetProcAddress(hDll, "Decrypt_XOR_Cipher");

    if (!Encrypt_Caesar_Cipher || !Decrypt_Caesar_Cipher || !Encrypt_XOR_Cipher || !Decrypt_XOR_Cipher) {
        cerr << "Unable to get function addresses from DLL" << endl;
        FreeLibrary(hDll);
        return -1;
    }

    int choice;
    cout << "Choose Cipher:\n1. Caesar Cipher\n2. XOR Cipher\n";
    cin >> choice;

    string srcName, destName;
    int cKey;
    char xKey;

    if (choice == 1) { // Caesar Cipher
        cout << "Enter source file name: ";
        cin >> srcName;
        cout << "Enter encrypted file name: ";
        cin >> destName;
        cout << "Enter key (integer): ";
        cin >> cKey;

        if (Encrypt_Caesar_Cipher(srcName.c_str(), destName.c_str(), cKey) == 0)
            cout << "Encryption done using Caesar Cipher!" << endl;
        else
            cout << "Encryption failed!" << endl;

        cout << "Enter source (encrypted) file name: ";
        cin >> srcName;
        cout << "Enter decrypted file name: ";
        cin >> destName;

        if (Decrypt_Caesar_Cipher(srcName.c_str(), destName.c_str(), cKey) == 0)
            cout << "Decryption done using Caesar Cipher!" << endl;
        else
            cout << "Decryption failed!" << endl;
    }
    else if (choice == 2) { // XOR Cipher
        cout << "Enter source file name: ";
        cin >> srcName;
        cout << "Enter encrypted file name: ";
        cin >> destName;
        cout << "Enter key (single char): ";
        cin >> xKey;

        if (Encrypt_XOR_Cipher(srcName.c_str(), destName.c_str(), xKey) == 0)
            cout << "Encryption done using XOR Cipher!" << endl;
        else
            cout << "Encryption failed!" << endl;

        cout << "Enter source (encrypted) file name: ";
        cin >> srcName;
        cout << "Enter decrypted file name: ";
        cin >> destName;

        if (Decrypt_XOR_Cipher(srcName.c_str(), destName.c_str(), xKey) == 0)
            cout << "Decryption done using XOR Cipher!" << endl;
        else
            cout << "Decryption failed!" << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    FreeLibrary(hDll);
    return 0;
}
