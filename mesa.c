#include "mesa.h"
#include "colores.h"
#include <stdio.h>

void imprimir_mantel(int mantel[NUM_NUMS][NUM_PALS]) {
    // Encabezado de los palos
    printf("\n[ORO] [COP] [ESP] [BAS]\n");

    // Array con los números de las cartas que deben imprimirse
    int numeros_cartas[10] = {12, 11, 10, 7, 6, 5, 4, 3, 2, 1};
    int total_cartas = sizeof(numeros_cartas) / sizeof(numeros_cartas[0]);

    for (int i = 0; i < total_cartas; i++) {
        int num = numeros_cartas[i] - 1;
        for (int pal = 0; pal < NUM_PALS; pal++) {
            if (mantel[num][pal]) {
                // Aplicar el color según el palo usando funciones disponibles en colores.h
                switch (pal) {
                    case 0: 
                        printf_color_num(3); // Oros en amarillo (código ANSI 3)
                        printf("[O%2d] ", numeros_cartas[i]); 
                        break;
                    case 1: 
                        printf_color_num(1); // Copas en rojo (código ANSI 1)
                        printf("[C%2d] ", numeros_cartas[i]); 
                        break;
                    case 2: 
                        printf_color_num(6); // Espadas en cyan (código ANSI 6)
                        printf("[E%2d] ", numeros_cartas[i]); 
                        break;
                    case 3: 
                        printf_color_num(2); // Bastos en verde (código ANSI 2)
                        printf("[B%2d] ", numeros_cartas[i]); 
                        break;
                }
                printf_reset_color(); // Reiniciar color
            } else {
                printf("[- -] ");
            }
        }
        printf("\n");
    }
}
