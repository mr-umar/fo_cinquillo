#include "partida.h"
#include "jugador.h"
#include "mesa.h"

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

int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada) {
    for (int i = 0; i < jugadores[num_jugador].num_cartas; i++) {
        if (es_posible(jugadores[num_jugador].cartas[i], mantel)) {
            *carta_seleccionada = jugadores[num_jugador].cartas[i];
            return TRUE;
        }
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
