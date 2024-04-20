## Estructura de directorios

En este directorio deberian ir todas las bibliotecas adicionales de nuestro proyecto. Para estandarizar, podemos usar esta estructura:

```
|-- lib
|   |   foo
|   |   |-- foo.c
|   |   |-- CMakeLists.txt
|   |   |-- inc
|   |   |   |-- foo.h
|   |   bar
|   |   |-- bar.c
|   |   |-- CMakeLists.txt
|   |   |-- inc
|   |   |   |-- bar.h
```

Donde _foo_ y _bar_ son nuestras bibliotecas particulares. Para que estas puedan ser compiladas correctamente y resuelvan las dependencias, tenemos que agregar un _CMakeLists.txt_ en cada directorio con una biblioteca. El contenido debe ser el siguiente, reemplazando foo por el nombre de nuestra biblioteca:

```cmake
# Definimos los .c de la biblioteca
add_library(foo
	# Agregamos todos los archivos de codigo fuente (.c) de nuestra biblioteca
	foo.c
)

# Incluimos los archivos de cabecera (.h)
target_include_directories(foo PUBLIC
     inc
)

# Creamos las dependencias de la bibliotecas con el SDK si fuese necesario
target_link_libraries(foo
	# Por ejemplo, si lib depende del I2C agregamos hardware_i2c abajo
	hardware_i2c
)
```

En el [CMakeLists.txt](../CMakeLists.txt) de nuestro proyecto, tenemos que agregar:

```cmake
add_subdirectory(lib/foo)
```
