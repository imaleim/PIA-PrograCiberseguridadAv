# Notas de reversing

## Strings identificados

Durante el análisis estático se identificaron referencias relacionadas con:

- libpcap
- OpenSSL
- SHA256
- pcap_loop
- pcap_open_live
- funciones de C++
- mensajes internos del programa
- tráfico ICMP
- procesos Linux

También se identificaron cadenas relacionadas con:

- menú interactivo
- generación de hashes
- análisis de tráfico
- lectura de archivos

---

# Funciones detectadas

El binario contiene funciones relacionadas con:

- captura de tráfico ICMP
- lectura de archivos
- generación de hashes SHA-256
- enumeración de procesos
- análisis de paquetes
- lectura de directorios `/proc`

---

# Imports relevantes

Durante el análisis de imports se identificaron funciones importantes como:

- pcap_loop
- pcap_open_live
- pcap_findalldevs
- pcap_close
- SHA256_Init
- SHA256_Update
- SHA256_Final
- opendir
- readdir
- closedir

Estas funciones permiten identificar capacidades de monitoreo, análisis de red y generación de hashes.

---

# Observaciones técnicas

La versión debug contiene símbolos visibles y múltiples secciones `.debug_*` que facilitan el análisis estático y reversing.

También se identificaron secciones ELF relevantes como:

- .text
- .data
- .bss
- .rodata
- .symtab
- .strtab

La versión release elimina parcialmente esta información utilizando `strip`, dificultando el análisis del binario.

---

# Hallazgos

El programa realiza correctamente:

- captura de tráfico ICMP mediante libpcap
- enumeración de procesos Linux
- generación de hashes SHA-256 reales
- lectura de archivos locales
- análisis modular mediante menú interactivo

El binario puede analizarse correctamente utilizando herramientas como:

- strings
- rabin2
- análisis ELF
- reversing básico
- Ghidra

