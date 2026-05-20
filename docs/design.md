# Diseño técnico – SimulatorPIA

## Arquitectura general

SimulatorPIA es un componente educativo de ciberseguridad desarrollado en C++ utilizando una arquitectura modular. Cada técnica implementada se encuentra separada en módulos independientes dentro del directorio `/src`.

El archivo `main.cpp` coordina la ejecución del sistema mediante un menú interactivo que permite ejecutar cada módulo de forma individual.

El proyecto fue desarrollado y probado dentro de una máquina virtual Ubuntu para mantener un entorno aislado y reproducible.

---

# Módulos implementados

## file_reader

Realiza lectura controlada de archivos locales utilizando `test.txt` como archivo de prueba. El módulo permite simular acceso y análisis básico de archivos dentro del entorno controlado.

---

## hasher

Genera hashes SHA-256 reales utilizando OpenSSL para verificar integridad de archivos y simular procesos básicos de análisis defensivo.

---

## process_enum

Enumera procesos activos del sistema Linux leyendo información desde `/proc`. El módulo obtiene PID y nombre de los procesos activos.

---

## packet_sniffer

Captura tráfico de red utilizando la librería libpcap y detecta paquetes ICMP en tiempo real dentro de la red virtual.

El módulo identifica:

- IP origen
- IP destino
- tamaño del paquete

---

# Flujo general del programa

Inicio del programa

↓

Visualización del menú principal

↓

Selección del módulo por el usuario

↓

Ejecución de:
- lectura de archivos
- generación de hash
- enumeración de procesos
- captura de tráfico ICMP

↓

Finalización controlada del programa

---

# Dependencias técnicas

- Compilador g++
- Librería libpcap
- Librería OpenSSL
- Linux Ubuntu
- VMware Workstation / VirtualBox

---

# Binarios generados

El proyecto genera dos versiones del ejecutable:

## Debug

Versión con símbolos de depuración utilizada para reversing y análisis estático.

## Release

Versión optimizada y sin símbolos utilizada para comparación y análisis profesional del binario.
