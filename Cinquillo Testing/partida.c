// partida.c
#include "partida.h"
#include "jugador.h"
#include "mesa.h"
#include <stdio.h>

int poner_5_oros(t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]) {
    for (int i = 0; i < NUM_JUGS; i++) {
        for (int j = 0; j < jugadores[i].num_cartas; j++) {
            if (jugadores[i].cartas[j].pal == PAL_OROS && jugadores[i].cartas[j].num == 4) { // 5 de oros tiene identificador 4
                mantel[4][PAL_OROS] = TRUE;
                eliminar_carta_jugador(jugadores[i].cartas[j], i, jugadores);
                return (i + 1) % NUM_JUGS; // El siguiente jugador
            }
        }
    }
    return 0;
}

void cartas_posibles(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_cartas_posibles *posibles) {
    posibles->num_cartas = 0;

    for (int i = 0; i < jugadores[num_jugador].num_cartas; i++) {
        if (es_posible(jugadores[num_jugador].cartas[i], mantel)) {
            posibles->cartas[posibles->num_cartas] = jugadores[num_jugador].cartas[i];
            posibles->num_cartas++;
        }
    }
}

int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada) {
    t_cartas_posibles posibles;
    cartas_posibles(num_jugador, jugadores, mantel, &posibles);

    if (posibles.num_cartas == 0) {
        return FALSE;
    }

    // Seleccionar automáticamente la primera carta posible para los jugadores controlados por la IA
    *carta_seleccionada = posibles.cartas[0];
    return TRUE;
}

int pedir_carta_humano(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada) {
    t_cartas_posibles posibles;
    cartas_posibles(num_jugador, jugadores, mantel, &posibles);

    if (posibles.num_cartas == 0) {
        return FALSE;
    }

    // Mostrar las posibles cartas
    printf("Tiradas posibles: ");
    for (int i = 0; i < posibles.num_cartas; i++) {
        printf("%d: [", i + 1);
        imprimir_carta(posibles.cartas[i].pal, posibles.cartas[i].num);
        printf("] ");
    }
    printf("\n");

    // Pedir al jugador humano que seleccione una opción válida
    int opcion;
    do {
        printf("¿Qué tirada realizas? ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > posibles.num_cartas);

    // Asignar la carta seleccionada
    *carta_seleccionada = posibles.cartas[opcion - 1];
    return TRUE;
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

void eliminar_carta_jugador(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS]) {
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
