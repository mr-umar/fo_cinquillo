#include "mesa.h"
#include "colores.h"
#include <stdio.h>

void imprimir_mantel(int mantel[NUM_NUMS][NUM_PALS]) {
    // Encabezado de los palos
    printf("\n[ORO] [COP] [ESP] [BAS]\n");

    for (int num = 0; num < NUM_NUMS; num++) {
        for (int pal = 0; pal < NUM_PALS; pal++) {
            if (mantel[num][pal]) {
                // Aplicar el color según el palo usando funciones disponibles en colores.h
                switch (pal) {
                    case 0: 
                        printf_color_num(3); // Oros en amarillo (código ANSI 3)
                        printf("[O%2d] ", num + 1); 
                        break;
                    case 1: 
                        printf_color_num(1); // Copas en rojo (código ANSI 1)
                        printf("[C%2d] ", num + 1); 
                        break;
                    case 2: 
                        printf_color_num(6); // Espadas en cyan (código ANSI 6)
                        printf("[E%2d] ", num + 1); 
                        break;
                    case 3: 
                        printf_color_num(2); // Bastos en verde (código ANSI 2)
                        printf("[B%2d] ", num + 1); 
                        break;
                }
                printf_reset_color(); // Reiniciar el color
            } else {
                printf("[- -] ");
            }
        }
        printf("\n");
    }
}
