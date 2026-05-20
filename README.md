# SimulatorPIA – Componente educativo de ciberseguridad en C++

## Objetivo del proyecto

SimulatorPIA es un simulador educativo desarrollado en C++ orientado al aprendizaje de técnicas básicas de análisis defensivo, monitoreo de sistemas y reversing dentro de un entorno virtual controlado.

El proyecto permite practicar análisis estático y dinámico mediante módulos de lectura de archivos, generación de hashes SHA-256, enumeración de procesos y captura de tráfico ICMP utilizando herramientas y librerías reales de ciberseguridad.

---

# Descripción técnica

SimulatorPIA implementa una arquitectura modular en C++ compuesta por varios componentes independientes:

- lectura controlada de archivos locales
- generación de hashes SHA-256 usando OpenSSL
- enumeración de procesos activos en Linux mediante `/proc`
- captura y análisis de tráfico ICMP usando libpcap
- menú interactivo para ejecución modular
- compilación en versiones debug y release

El proyecto fue desarrollado y probado exclusivamente dentro de una máquina virtual Ubuntu.

---

# Dependencias

El proyecto requiere:

- g++
- libpcap-dev
- libssl-dev
- Linux Ubuntu
- VMware Workstation / VirtualBox

## Instalación de dependencias

```bash
sudo apt update
sudo apt install g++ libpcap-dev libssl-dev -y
```

---

# Estructura del proyecto

```text
SimulatorPIA/
│
├── src/
├── bin/
├── docs/
├── analysis/
├── evidence/
├── README.md
└── test.txt
```

---

# Compilación

## Versión debug (con símbolos)

```bash
g++ src/*.cpp -lpcap -lssl -lcrypto -g -o bin/SimulatorPIA_debug
```

## Versión release (sin símbolos)

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

# Funcionalidades implementadas

## Lectura de archivos

Permite abrir y analizar archivos locales dentro del entorno controlado.

## Generación de hashes SHA-256

Utiliza OpenSSL para generar hashes SHA-256 reales y verificar integridad de archivos.

## Enumeración de procesos

Obtiene procesos activos del sistema Linux leyendo información desde `/proc`.

## Packet sniffer ICMP

Captura tráfico ICMP en tiempo real utilizando libpcap e identifica:

- IP origen
- IP destino
- tamaño del paquete

---

# Alcance y límites

## Incluye

- simulación educativa de monitoreo del sistema
- análisis básico de tráfico de red
- generación de hashes criptográficos
- reversing y análisis estático de binarios ELF
- ejecución modular dentro de VM Ubuntu

## No incluye

- persistencia
- evasión
- comunicación remota
- exfiltración de datos
- modificaciones al sistema anfitrión
- comportamiento malicioso real

---

# Análisis realizado

El proyecto fue analizado utilizando:

- strings
- rabin2
- análisis ELF
- reversing básico
- comparación debug vs release

También se realizaron pruebas de tráfico ICMP y análisis dinámico dentro de la máquina virtual.

---

# Reporte técnico

El reporte técnico final se encuentra en:

```text
docs/report_final.pdf
```

---

# Evidencias y video

Las capturas y evidencias del proyecto se encuentran en:

```text
evidence/
```

## Video demo

```text
[Agregar enlace del video]
```

---

# Integrantes y responsabilidades técnicas

## Joustin Martinez

Diseño inicial de la arquitectura modular, implementación del módulo `file_reader` e integración del entorno Linux de compilación.

## Alejandra Ojeda 

Implementación y mejora del módulo `packet_sniffer` usando libpcap y validación experimental del tráfico ICMP dentro de la VM.

## Santiago Cantu

Implementación de `process_enum`, generación de hashes SHA-256, organización del análisis estático y soporte de reversing básico.
