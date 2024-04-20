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

# Verificamos la version del SDK de la Raspberry Pi Pico
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Inicializamos el SDK
pico_sdk_init()

# Incluimos cada biblioteca diciendo donde se encuentra dentro de lib
# add_subdirectory(lib/foo)

# Genero el ejecutable desde main.c
add_executable(${PROJECT_NAME} main.c)

# Habilito el stdio por USB (1) y deshabilito por UART (0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Aca se agregan las librerias adicionales de las que dependa nuestro main.c
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
	# Agregamos cada biblioteca con su nombre correspondiente abajo
)

# Crear los binarios
pico_add_extra_outputs(${PROJECT_NAME})
