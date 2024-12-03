#include "mesa.h"
#include <stdio.h>

void imprimir_mantel(int mantel[NUM_NUMS][NUM_PALS]) {
    printf("\n[ORO] [COP] [ESP] [BAS]\n");
    for (int i = 0; i < NUM_NUMS; i++) {
        for (int j = 0; j < NUM_PALS; j++) {
            if (mantel[i][j]) {
                printf("[ %.2d ]", i + 1);
            } else {
                printf("[- -] ");
            }
        }
        printf("\n");
    }
}