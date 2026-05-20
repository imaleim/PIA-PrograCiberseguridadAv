#include "hasher.h"

#include <iostream>
#include <fstream>
#include <iomanip>

#include <openssl/sha.h>

void generateHash(const char* filename)
{
    std::ifstream file(filename, std::ios::binary);

    if(!file)
    {
        std::cout << "\n[ERROR HASH]\n";
        std::cout << "No se pudo abrir el archivo\n";

        return;
    }

    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    char buffer[4096];

    while(file.read(buffer, sizeof(buffer)))
    {
        SHA256_Update(&sha256, buffer, file.gcount());
    }

    SHA256_Update(&sha256, buffer, file.gcount());

    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_Final(hash, &sha256);

    std::cout << "\n[SHA-256]\n";
    std::cout << "Archivo: "
              << filename
              << "\n";

    std::cout << "Hash: ";

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        std::cout
            << std::hex
            << std::setw(2)
            << std::setfill('0')
            << (int)hash[i];
    }

    std::cout << "\n";

    file.close();
}
