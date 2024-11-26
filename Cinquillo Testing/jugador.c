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
    for (int i = 0; i < NUM_JUGS; i++) {
        printf("\nJugador #%d: ", i);
        for (int j = 0; j < jugadores[i].num_cartas; j++) {
            imprimir_carta(jugadores[i].cartas[j].pal, jugadores[i].cartas[j].num);
            printf(" ");
        }
        printf("\n");
    }
}