# Version minima de CMake
cmake_minimum_required(VERSION 3.13)

# Incluir el SDK (tiene que haberse instalado el SDK de la Raspberry Pi Pico y agregado al PATH)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Definimos el nombre de nuestro proyecto
set(PROJECT_NAME pico_template)

# Definimos los lenguajes para nuestro proyecto (C/C++/Assmebly)
project(${PROJECT_NAME} C CXX ASM)

# Configuramos el estandar de C y C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Definimos el directorio lib donde se encuentran las bibliotecas adicionales
set(LIBS lib)

# Verificamos la version del SDK de la Raspberry Pi Pico
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Inicializamos el SDK
pico_sdk_init()

# Bibliotecas adicionales
add_library(lib
	# Las bibliotecas se agregan como ${LIBS}/NOMBRE.c o ${LIBS}/DIR/NOMBRE.c
	# Reemplazando DIR por el nombre del directorio donde se encuentre y
	# NOMBRE por el nombre del archivo de codigo fuente (.c) de la biblioteca
)

# Incluimos los archivos de cabecera
target_include_directories(lib PUBLIC
     include
     # Si tenemos bibliotecas para agregar, incluimos sus archivos de cabecera (.h)
     # como ${LIBS}/DIR reemplazando DIR por el directorio de la biblioteca
)

# Creo las dependencias de las bibliotecas con el SDK si fuese necesario
target_link_libraries(lib
	# Por ejemplo, si lib depende del I2C agregamos hardware_i2c abajo
)

# Genero el ejecutable desde main.c
add_executable(${PROJECT_NAME}
	main.c
)

# Habilito el stdio por USB (1) y deshabilito por UART (0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Aca se agregan las librerias adicionales de las que dependa nuestro main.c
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    # Si hubiesemos agregado bibliotecas adicionales en lib, lo descomentamos
    lib
	# Agregar abajo cualquier otra biblioteca
)

# Crear los binarios
pico_add_extra_outputs(${PROJECT_NAME})
