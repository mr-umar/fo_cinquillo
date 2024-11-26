#include "carta.h"
#include "colores.h"
#include <stdio.h>

void imprimir_carta(int pal, int num) {
    printf_color_num(pal);
    char *palos[] = {"OR", "CO", "ES", "BA"};
    char *figuras[] = {"1", "2", "3", "4", "5", "6", "7", "10", "11", "12"};
    printf("[%s %s]", palos[pal], figuras[num]);
    printf_reset_color();
}
