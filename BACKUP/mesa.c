#include "mesa.h"
#include "colores.h"
#include <stdio.h>

void imprimir_cabecera_mantel() {
    // imprime la cabecera con los colores correspondientes a cada palo
    printf_color_num(3); // Oros en amarillo (código ANSI 3)
    printf("\n[ORO] ");
    printf_color_num(1); // Copas en rojo (código ANSI 1)
    printf("[COP] ");
    printf_color_num(6); // Espadas en cyan (código ANSI 6)
    printf("[ESP] ");
    printf_color_num(2); // Bastos en verde (código ANSI 2)
    printf("[BAS] ");
    printf_reset_color(); // Reiniciar color
    printf("\n");
}

void imprimir_mantel(int mantel[NUM_NUMS][NUM_PALS]) {
    // Encabezado de los palos
    imprimir_cabecera_mantel();

    // Array con los números de las cartas que deben imprimirse
    int numeros_cartas[10] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
    int total_cartas = sizeof(numeros_cartas) / sizeof(numeros_cartas[0]);

    for (int i = total_cartas - 1; i >= 0; i--) {  // Recorrer el índice de los números en sentido inverso
        for (int pal = 0; pal < NUM_PALS; pal++) {
            if (mantel[i][pal]) {
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
