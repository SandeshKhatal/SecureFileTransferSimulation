🔐 Secure File Transfer Simulation

📌 Overview
The Secure File Transfer Simulation project demonstrates secure file handling using C, Win32 SDK, DLLs, and cryptography. It simulates encryption/decryption during file transfer using Caesar Cipher and XOR Cipher, packaged inside a modular DLL for reusability.

🛠️ Technology Stack
•	Language: C (Win32 API)
•	Cryptography: Caesar Cipher, XOR Cipher
•	File Handling: Win32 API (CreateFile, ReadFile, WriteFile)
•	Architecture: DLL (Server) + Console App (Client)

📂 Project Structure
SecureFileTransferSimulation/
├── ServerCipher/          # DLL Project
│   └── ServerCipher.cpp   # Cipher logic
├── ClientCipher/          # Console App
│   └── ClientCipher.cpp   # Loads DLL & simulates transfer
├── PPA.txt                # Sample input file
└── README.md              # Documentation

🔑 Features
•	Caesar Cipher Encryption/Decryption
•	XOR Cipher Encryption/Decryption
•	File I/O with Windows API
•	DLL-based Modular Design
•	Simulation of Secure File Transfer

🔄 Workflow
Plaintext File → Encrypt with DLL → Encrypted File → Transfer Simulation → Decrypt with DLL → Recovered File
🚀 How to Run
1.	1. Build DLL: Open ServerCipher project in Visual Studio and build to generate ServerCipher.dll.
2.	2. Build Client App: Open ClientCipher project and build to generate ClientCipher.exe.
3.	3. Place DLL with Client: Copy ServerCipher.dll into the same folder as ClientCipher.exe.
4.	4. Run Simulation: Execute ClientCipher.exe
      
🖥️ Example Execution
Choose Cipher:
1. Caesar Cipher
2. XOR Cipher
1
Enter source file: PPA.txt
Enter encrypted file: ENCRYPTED.txt
Enter key (integer): 3
Encryption successful!

Enter encrypted file: ENCRYPTED.txt
Enter decrypted file: DECRYPTED.txt
Enter key (integer): 3
Decryption successful!

✔️ DECRYPTED.txt matches original PPA.txt.

