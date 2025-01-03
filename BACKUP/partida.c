#include "partida.h"
#include "jugador.h"
#include "mesa.h"
#include "azar.h"
// #include "duerme.h"
#include <stdio.h>

int poner_5_oros(t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]) {
    for (int i = 0; i < NUM_JUGS; i++) {
        for (int j = 0; j < jugadores[i].num_cartas; j++) {
            if (jugadores[i].cartas[j].pal == PAL_OROS && jugadores[i].cartas[j].num == 4) {    // 5 de oros tiene identificador 4
                mantel[4][PAL_OROS] = TRUE;
                eliminar_carta_jugador(jugadores[i].cartas[j], i, jugadores);

                printf("\nTurno de JUG#%d:\n", i + 1);
                printf("Tiradas posibles: 1: ");
                imprimir_carta(PAL_OROS, 4);
                printf("\n¿Que tirada realizas? 1\n");

                return (i + 1) % NUM_JUGS;  // Pasar al siguiente jugador
            }
        }
    }
    return 0;
}


int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada, int es_humano) {
    t_cartas_posibles posibles;
    posibles.num_cartas = 0;

    // Determinar las cartas posibles
    for (int i = 0; i < jugadores[num_jugador].num_cartas; i++) {
        if (es_posible(jugadores[num_jugador].cartas[i], mantel)) {
            posibles.cartas[posibles.num_cartas] = jugadores[num_jugador].cartas[i];
            posibles.num_cartas++;
        }
    }

    if (posibles.num_cartas > 0) {
        // Mostrar las cartas posibles
        printf("Tiradas posibles:");
        for (int i = 0; i < posibles.num_cartas; i++) {
            printf(" %d: ", i + 1);
            imprimir_carta(posibles.cartas[i].pal, posibles.cartas[i].num);
        }
        printf("\n");

        if (es_humano && num_jugador == 0) {
            int opcion;
            do {
                printf("> Que tirada realizas? ");
                scanf("%d", &opcion);
                if (opcion < 1 || opcion > posibles.num_cartas) {
                    printf("Por favor, elige una tirada de las opciones disponibles.\n");
                }
            } while (opcion < 1 || opcion > posibles.num_cartas);
            *carta_seleccionada = posibles.cartas[opcion - 1];
        } else {
            // Seleccionar una carta al azar de las disponibles
            int indice_aleatorio = numero_al_azar(posibles.num_cartas);
            *carta_seleccionada = posibles.cartas[indice_aleatorio];

            // Mostrar la carta seleccionada por la IA
            printf("Que tirada realizas? %d\n", indice_aleatorio + 1);
        }

        return TRUE;
    }
    else{
        printf("Tiradas posibles:\nNinguna! :-/ Paso.");
    }

    return FALSE;
}

int es_posible(t_carta carta, int mantel[NUM_NUMS][NUM_PALS]) {
    int num = carta.num;
    int pal = carta.pal;
    if (num == 4) { // El 5 siempre se puede poner
        return TRUE;
    }
    if (num > 0 && mantel[num - 1][pal]) {
        return TRUE;
    }
    if (num < NUM_NUMS - 1 && mantel[num + 1][pal]) {
        return TRUE;
    }
    return FALSE;
}

int poner_carta(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]) {
    mantel[carta.num][carta.pal] = TRUE;
    eliminar_carta_jugador(carta, num_jugador, jugadores);
    return jugadores[num_jugador].num_cartas == 0;
}

void eliminar_carta_jugador(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS]) { // elimina la carta de la baraja del jugador despues de la jugada
    int index = -1;
    for (int i = 0; i < jugadores[num_jugador].num_cartas; i++) {
        if (jugadores[num_jugador].cartas[i].pal == carta.pal && jugadores[num_jugador].cartas[i].num == carta.num) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < jugadores[num_jugador].num_cartas - 1; i++) {
            jugadores[num_jugador].cartas[i] = jugadores[num_jugador].cartas[i + 1];
        }
        jugadores[num_jugador].num_cartas--;
    }
}
