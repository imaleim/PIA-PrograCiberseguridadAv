#include "process_enum.h"

#include <iostream>
#include <dirent.h>
#include <cctype>
#include <fstream>
#include <string>

void listProcesses()
{
    DIR *dir;
    struct dirent *ent;

    dir = opendir("/proc");

    if(dir != NULL)
    {
        std::cout << "\n[PROCESOS ACTIVOS]\n";

        while((ent = readdir(dir)) != NULL)
        {
            // Detectar directorios numéricos (PIDs)
            if(isdigit(ent->d_name[0]))
            {
                std::string pid = ent->d_name;

                // Ruta al archivo que contiene el nombre del proceso
                std::string path =
                    "/proc/" + pid + "/comm";

                std::ifstream processFile(path);

                std::string processName;

                if(processFile.is_open())
                {
                    getline(processFile, processName);

                    std::cout
                        << "PID: "
                        << pid
                        << " | "
                        << processName
                        << std::endl;

                    processFile.close();
                }
            }
        }

        closedir(dir);
    }
    else
    {
        std::cout
            << "[ERROR] No se pudo abrir /proc\n";
    }
}
