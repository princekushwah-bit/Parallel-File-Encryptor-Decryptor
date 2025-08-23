# Parallel File Encryptor Decryptor

This project is a parallel file encryptor and decryptor implemented in C++. It allows you to encrypt and decrypt files using multiple threads for improved performance.

## Usage

To use this program, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the program by running the following command:

    ```
    make
    ```

4. Once the program is compiled, you can encrypt a file by running the following command:

    ```
    ./encrypt_decrypt
    Enter the directory path: <filePath>
    Enter the action (encrypt/decrypt): encrypt
    ```

    Replace `<filePath>` with the path to the file you want to encrypte.

5. To decrypt a file, use the following command:

    ```
   ./encrypt_decrypt
    Enter the directory path: <filePath>
    Enter the action (encrypt/decrypt): decrypt
    ```

    Replace `<filePath>` with the path to the encrypted file.

## Makefile Commands

The Makefile included in this project provides the following commands:

- `make`: Compiles the program.
- `make clean`: Removes the compiled program and any generated files.

Please note that this project requires a C++ compiler and the pthread library to be installed on your system.

## Output

### Encryption

![image](https://github.com/anujagrawal699/Parallel-File-Encryptor-Decryptor/assets/121146661/0c89bd7c-11a6-4900-a17b-2bc0a2b9af54)

### Decryption

![image](https://github.com/anujagrawal699/Parallel-File-Encryptor-Decryptor/assets/121146661/12ea1d29-d8b8-4319-8e14-ceb6ca3af0cd)
