#ifndef JUGADOR_H
#define JUGADOR_H
#include "carta.h"
#include "baraja.h"  

#define NUM_JUGS 4
#define NUM_CARTAS_JUG 10

typedef struct {
    t_carta cartas[NUM_CARTAS_JUG];
    int num_cartas;
} t_jugador;

void repartir_cartas(t_baraja *p_baraja, t_jugador jugadores[NUM_JUGS]);
void imprimir_jugadores(t_jugador jugadores[NUM_JUGS]);
int pedir_jugada_humana(t_jugador jugador, t_carta cartas_posibles[], int num_cartas_posibles);

#endif
