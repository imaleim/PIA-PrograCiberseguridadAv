# Borrador técnico — SimulatorPIA

## Descripción del payload

SimulatorPIA es un componente educativo desarrollado en C++ orientado al aprendizaje de técnicas básicas utilizadas en análisis defensivo, reversing y monitoreo de comportamiento dentro de un entorno virtual controlado.

El proyecto fue diseñado para ejecutarse únicamente dentro de máquinas virtuales Ubuntu y no realiza acciones maliciosas reales.

Actualmente el sistema implementa:

- lectura de archivos locales
- captura de tráfico ICMP mediante libpcap
- enumeración de procesos activos
- generación de hashes SHA-256 reales usando OpenSSL
- arquitectura modular en C++
- compilación debug y release
- menú interactivo de ejecución

El objetivo principal es permitir prácticas de análisis estático, análisis dinámico y reversing básico sobre binarios ELF dentro de un entorno seguro y reproducible.

---

# Diseño del sistema

El proyecto utiliza una arquitectura modular dividida en componentes independientes.

## Módulos implementados

### file_reader

Permite abrir y leer archivos locales del sistema para pruebas controladas de acceso y análisis de archivos.

### packet_sniffer

Utiliza la librería libpcap para capturar paquetes ICMP dentro de la máquina virtual.

El módulo identifica:

- IP origen
- IP destino
- tamaño del paquete

### process_enum

Realiza enumeración de procesos activos del sistema Linux mediante acceso al directorio `/proc`.

El módulo obtiene:

- PID
- nombre del proceso

### hasher

Genera hashes SHA-256 reales utilizando OpenSSL para verificar integridad de archivos.

### main.cpp

Coordina todos los módulos mediante un menú interactivo y controla el flujo general del programa.

---

# Pruebas realizadas

Las pruebas fueron ejecutadas dentro de una máquina virtual Ubuntu aislada.

## Compilación

Se generaron dos binarios:

### Debug

```bash
g++ src/*.cpp -lpcap -lssl -lcrypto -g -o bin/SimulatorPIA_debug
```

### Release

```bash
g++ src/*.cpp -lpcap -lssl -lcrypto -o bin/SimulatorPIA_release
strip bin/SimulatorPIA_release
```

---

# Ejecución

```bash
sudo ./bin/SimulatorPIA_debug
```

---

# Resultados observados

Durante la ejecución el sistema mostró correctamente:

- lectura de archivos locales
- generación de hashes SHA-256
- enumeración de procesos Linux
- captura de tráfico ICMP real
- detección de IP origen y destino
- funcionamiento modular mediante menú interactivo

También se verificó el funcionamiento del sniffer realizando tráfico ping dentro de la máquina virtual.

---

# Hallazgos iniciales del análisis

Se realizó análisis estático preliminar usando:

- strings
- rabin2
- análisis ELF
- reversing básico

## Hallazgos relevantes

Se identificaron referencias a:

- libpcap
- OpenSSL
- pcap_loop
- pcap_open_live
- SHA256_Init
- SHA256_Update
- SHA256_Final
- símbolos debug
- secciones ELF (.text, .data, .bss)

La versión debug contiene información útil para reversing debido a la presencia de símbolos y secciones de depuración.

La versión release elimina parcialmente esta información utilizando strip.

---

# Riesgos y mitigaciones

## Riesgos identificados

Aunque el proyecto es educativo, algunas técnicas implementadas podrían parecer similares a comportamientos observados en herramientas ofensivas o malware real, especialmente:

- sniffing de tráfico
- monitoreo del sistema
- análisis de procesos
- inspección de comportamiento

## Mitigaciones aplicadas

Para reducir riesgos:

- el proyecto se ejecuta únicamente en máquinas virtuales
- no existe persistencia
- no hay comunicación remota
- no se modifican archivos críticos del sistema
- no se realizan acciones ofensivas reales
- no existe exfiltración de información

El objetivo del proyecto es exclusivamente académico y defensivo.

---

# Trabajo pendiente

Para la entrega final se planea:

- ampliar documentación técnica
- generar análisis más profundo en Ghidra/radare2
- realizar mayor documentación de reversing
- mejorar evidencias visuales
- generar reporte técnico final en PDF
- grabar video demo del funcionamiento del proyecto

También se planea fortalecer el análisis dinámico y la documentación de comportamiento observada durante la ejecución.
