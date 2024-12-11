#include "carta.h"
#include "colores.h"
#include <stdio.h>

// Imprime una carta con su palo, número y color correspondiente.
void imprimir_carta(int pal, int num) {
    switch (pal) {
        case 0: printf_color_num(3); break; // Oros en amarillo
        case 1: printf_color_num(1); break; // Copas en rojo
        case 2: printf_color_num(6); break; // Espadas en cyan
        case 3: printf_color_num(2); break; // Bastos en verde
    }

    char *palos[] = {"O", "C", "E", "B"};
    char *figuras[] = {"1", "2", "3", "4", "5", "6", "7", "10", "11", "12"};

    if (num < 7) { 
        printf("[%s %s]", palos[pal], figuras[num]); // Números 1 a 7
    } else {
        printf("[%s%s]", palos[pal], figuras[num]);  // Números 10 a 12
    }

    printf_reset_color(); 
}
