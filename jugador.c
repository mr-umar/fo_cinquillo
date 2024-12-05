#include "jugador.h"
#include "baraja.h"
#include <stdio.h>

void repartir_cartas(t_baraja *p_baraja, t_jugador jugadores[NUM_JUGS]) {
    for (int i = 0; i < NUM_JUGS; i++) {
        for (int j = 0; j < NUM_CARTAS_JUG; j++) {
            jugadores[i].cartas[j] = sacar_carta_baraja(p_baraja);
        }
        jugadores[i].num_cartas = NUM_CARTAS_JUG;
    }
}

void imprimir_jugadores(t_jugador jugadores[NUM_JUGS]) {
    printf("\n\t[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [10 ]");
    for (int i = 0; i < NUM_JUGS; i++) {
        printf("\nJUG #%d: ", i + 1);
        for (int j = 0; j < jugadores[i].num_cartas; j++) {
            imprimir_carta(jugadores[i].cartas[j].pal, jugadores[i].cartas[j].num);
            printf(" ");
        }
    }
    printf("\n");
}

int pedir_jugada_humana(t_jugador jugador, t_carta cartas_posibles[], int num_cartas_posibles) {
    int opcion;
    do {
        printf("> Que tirada realizas? ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > num_cartas_posibles) {
            printf("> Por favor, elige una tirada de las opciones disponibles.\n");
        }
    } while (opcion < 1 || opcion > num_cartas_posibles);
    return opcion - 1;
}
