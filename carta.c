#include "carta.h"
#include "colores.h"
#include <stdio.h>

void imprimir_carta(int pal, int num) {
    switch (pal) {
        case 0:
            printf_color_num(3); // Oros en amarillo
            break;
        case 1:
            printf_color_num(1); // Copas en rojo
            break;
        case 2:
            printf_color_num(6); // Espadas en cyan
            break;
        case 3:
            printf_color_num(2); // Bastos en verde
            break;
    }

    char *palos[] = {"O", "C", "E", "B"};
    char *figuras[] = {"1", "2", "3", "4", "5", "6", "7", "10", "11", "12"};
    if (num < 7) {
        printf("[%s %s]", palos[pal], figuras[num]);
    } else {
        printf("[%s%s]", palos[pal], figuras[num]);
    }
    printf_reset_color();
}
