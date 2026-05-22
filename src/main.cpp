#include <iostream>

#include "hasher.h"
#include "process_enum.h"
#include "file_reader.h"
#include "packet_sniffer.h"

int main()
{
    int option;

    do
    {
        std::cout << "\n===== SimulatorPIA =====\n";

        std::cout << "1. Leer archivo\n";
        std::cout << "2. Generar hash\n";
        std::cout << "3. Enumerar procesos\n";
        std::cout << "4. Iniciar sniffer\n";
        std::cout << "5. Salir\n";

        std::cout << "\nSelecciona una opcion: ";
        std::cin >> option;

        switch(option)
        {
            case 1:
                std::cout << "\n[LECTURA DE ARCHIVO]\n";
                readFile("test.txt");
                break;

            case 2:
                std::cout << "\n[HASH]\n";
                generateHash("test.txt");
                break;

            case 3:
                std::cout << "\n[PROCESOS ACTIVOS]\n";
                listProcesses();
                break;

            case 4:
                std::cout << "\n[SNIFFER]\n";
                startSniffer();
                break;

            case 5:
                std::cout << "\nSaliendo del programa...\n";
                break;

            default:
                std::cout << "\nOpcion invalida\n";
        }

    } while(option != 5);

    return 0;
}
