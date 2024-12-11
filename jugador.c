#include "jugador.h"
#include "baraja.h"
#include <stdio.h>

// Obtiene si hay un jugador humano en el juego (retorna 0 si hay, -1 si no).
int obtener_jugador_humano() {
    char respuesta;
    do {
        printf("> Hay algun jugador humano? [s/n]: ");
        scanf(" %c%*[^\n]", &respuesta);
        if (respuesta == 's' || respuesta == 'S') {
            return 0;  // Jugador humano será el jugador número 0 (primero)
        } else if (respuesta == 'n' || respuesta == 'N') {
            return -1; // No hay jugador humano
        } else {
            printf("> Por favor, responde 's' o 'n'.\n");
        }
    } while (1);
}

// Pregunta al jugador si desea ocultar las cartas de los demás jugadores.
int preguntar_ocultar_cartas() {
    char respuesta;
    do {
        printf("> Quieres ver todas las cartas? [s/n]: ");
        scanf(" %c%*[^\n]", &respuesta);
        if (respuesta == 's' || respuesta == 'S') {
            return 0; // No ocultar cartas
        } else if (respuesta == 'n' || respuesta == 'N') {
            return 1; // Ocultar cartas
        } else {
            printf("> Por favor, responde 's' o 'n'.\n");
        }
    } while (1);
}

// Imprime las cartas de los jugadores, ocultando las cartas de los demás si es necesario.
void imprimir_jugadores(t_jugador jugadores[NUM_JUGS], int jugador_humano, int ocultar_cartas) {
    printf("\n\t[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [10 ]");
    for (int i = 0; i < NUM_JUGS; i++) {
        printf("\nJUG #%d: ", i + 1);
        for (int j = 0; j < jugadores[i].num_cartas; j++) {
            if (ocultar_cartas && i != jugador_humano) {
                printf("[? ?] "); // Muestra cartas ocultas
            } else {
                imprimir_carta(jugadores[i].cartas[j].pal, jugadores[i].cartas[j].num); // Muestra cartas reales
                printf(" ");
            }
        }
    }
    printf("\n");
}

// Reparte las cartas a los jugadores desde la baraja.
void repartir_cartas(t_baraja *p_baraja, t_jugador jugadores[NUM_JUGS]) {
    for (int i = 0; i < NUM_JUGS; i++) {
        for (int j = 0; j < NUM_CARTAS_JUG; j++) {
            jugadores[i].cartas[j] = sacar_carta_baraja(p_baraja);
        }
        jugadores[i].num_cartas = NUM_CARTAS_JUG; // Inicializa el número de cartas de cada jugador
    }
}
