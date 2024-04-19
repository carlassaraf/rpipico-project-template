#include <stdio.h>
#include "pico/stdlib.h"

/**
 * @brief Programa principal
 */
int main(void) {
	// Inicializacion de stdio (USB o UART)
	stdio_init_all();

	// Inicializaciones

	while(1) {
		// Bucle infinito

		// Mensaje de prueba
		printf("Hola desde Raspberry Pi Pico!\n");
		// Demora
		sleep_ms(1000);
	}
	return 0;
}
