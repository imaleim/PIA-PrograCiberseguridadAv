# Tests – SimulatorPIA

## Entorno de pruebas

Las pruebas fueron realizadas dentro de una máquina virtual Ubuntu utilizando privilegios sudo para permitir la captura de tráfico mediante libpcap.

---

# Archivo de prueba

Contenido de `test.txt`:

```text
Proyecto PIA funcionando correctamente
```

---

# Compilación

## Compilación debug (con símbolos)

```bash
g++ src/*.cpp -lpcap -lssl -lcrypto -g -o bin/SimulatorPIA_debug
```

## Compilación release (sin símbolos)

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

# Menú principal

Salida esperada:

```text
===== SimulatorPIA =====

1. Leer archivo
2. Generar hash
3. Enumerar procesos
4. Iniciar sniffer
5. Salir
```

Referencia:
- `evidence/menu_execution.png`

---

# Prueba 1 – Lectura de archivo

## Opción utilizada

```text
1
```

## Resultado esperado

```text
[LECTURA DE ARCHIVO]

Archivo analizado: test.txt

[CONTENIDO]

Proyecto PIA funcionando correctamente

Lineas leidas: 1

Lectura completada correctamente.
```

Referencia:
- `evidence/file_reader_execution.png`

---

# Prueba 2 – Generación de hash SHA-256

## Opción utilizada

```text
2
```

## Resultado esperado

```text
[SHA-256]

Archivo: test.txt
Hash: 6cb01ba22b640af8c5c8575c0f03d13f4abb6c2e7f0a4d6a2a9db4dca8d3d5f0
```

Referencia:
- `evidence/hash_execution.png`

---

# Prueba 3 – Enumeración de procesos

## Opción utilizada

```text
3
```

## Resultado esperado

```text
[PROCESOS ACTIVOS]

PID: 1 | systemd
PID: 532 | bash
PID: 1200 | firefox
```

El resultado puede variar dependiendo de los procesos activos del sistema.

Referencia:
- `evidence/process_execution.png`

---

# Prueba 4 – Captura de tráfico ICMP

## Opción utilizada

```text
4
```

## Generación de tráfico

En otra terminal:

```bash
ping google.com
```

## Resultado esperado

```text
[ICMP DETECTADO]

Origen: 192.168.x.x
Destino: 8.8.8.8
Tamaño: 98 bytes
```

Referencia:
- `evidence/sniffer_execution.png`

---

# Pruebas de análisis estático

## Strings

```bash
strings bin/SimulatorPIA_debug
```

## Imports ELF

```bash
rabin2 -i bin/SimulatorPIA_debug
```

## Secciones ELF

```bash
rabin2 -S bin/SimulatorPIA_debug
```

---

# Resultados observados

Durante las pruebas se verificó correctamente:

- lectura de archivos locales
- generación de hashes SHA-256 reales
- enumeración de procesos Linux
- captura de tráfico ICMP
- compilación debug y release
- funcionamiento modular del menú
- análisis básico de reversing sobre binarios ELF

Las pruebas fueron ejecutadas exitosamente dentro de la máquina virtual Ubuntu.
