#ifndef PARTIDA_H
#define PARTIDA_H
#include "carta.h"
#include "jugador.h"
#include "mesa.h"

int poner_5_oros(t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]);
int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada);
int es_posible(t_carta carta, int mantel[NUM_NUMS][NUM_PALS]);
int poner_carta(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]);
void eliminar_carta_jugador(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS]);

#endif
