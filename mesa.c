#include "mesa.h"
#include "colores.h"
#include <stdio.h>

// Imprime la cabecera del mantel con los colores correspondientes a cada palo
void imprimir_cabecera_mantel() {
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

// Imprime el mantel (estado de las cartas en la mesa)
void imprimir_mantel(int mantel[NUM_NUMS][NUM_PALS]) {
    imprimir_cabecera_mantel(); // Imprime la cabecera con los palos

    // Array con los números de las cartas que deben imprimirse
    int numeros_cartas[10] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
    int total_cartas = sizeof(numeros_cartas) / sizeof(numeros_cartas[0]);

    // Recorre las cartas en orden inverso para imprimir desde 12 hasta 1
    for (int i = total_cartas - 1; i >= 0; i--) {
        for (int pal = 0; pal < NUM_PALS; pal++) {
            if (mantel[i][pal]) {
                // Aplica el color correspondiente al palo y muestra la carta
                switch (pal) {
                    case 0:
                        printf_color_num(3); // Oros en amarillo
                        printf("[O%2d] ", numeros_cartas[i]);
                        break;
                    case 1:
                        printf_color_num(1); // Copas en rojo
                        printf("[C%2d] ", numeros_cartas[i]);
                        break;
                    case 2:
                        printf_color_num(6); // Espadas en cyan
                        printf("[E%2d] ", numeros_cartas[i]);
                        break;
                    case 3:
                        printf_color_num(2); // Bastos en verde
                        printf("[B%2d] ", numeros_cartas[i]);
                        break;
                }
                printf_reset_color();
            } else {
                printf("[- -] ");
            }
        }
        printf("\n"); 
    }
}
