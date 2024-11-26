// partida.h
#ifndef PARTIDA_H
#define PARTIDA_H
#include "carta.h"
#include "jugador.h"
#include "mesa.h"

#define MAX_CARTAS_POSIBLES 10  // Máximo número de cartas posibles en una jugada

typedef struct {
    t_carta cartas[MAX_CARTAS_POSIBLES];
    int num_cartas;
} t_cartas_posibles;

int poner_5_oros(t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]);
int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada);
int pedir_carta_humano(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada);
int es_posible(t_carta carta, int mantel[NUM_NUMS][NUM_PALS]);
int poner_carta(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]);
void eliminar_carta_jugador(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS]);
void cartas_posibles(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_cartas_posibles *posibles);

#endif
