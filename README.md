# rpipico-project-template
Repositorio de template para poder armar un proyecto genérico para la Raspberry Pi Pico en C/C++

Este directorio puede ser clonado y es compatible con proyectos que se creen desde cero solo con las herramientas de compilacion basicas o con proyectos creados en PlatformIO.

Algunos archivos importantes en el repositorio son:

- `main.c` que es el codigo principal del proyecto.
- `lib` que es un directorio donde iran todas las bibliotecas adicionales.
- `CMakeLists.txt` que contiene la lista de dependencias de nuestro proyecto.
- `Makefile` que tiene una lista de comandos para facilitar la compilacion y flasheo de nuestro proyecto.
- `platformio.ini` que solo es valido para proyectos con PlatformIO pero contiene la configuracion basica.

## Uso de Makefile

El Makefile tiene una lista de comandos para automatizar la compilacion y flasheo. Para usarlo, podemos escribir:

```bash
make help
```

Lo que nos va a dar una lista de opciones de como usar el Makefile.
