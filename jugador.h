#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "baraja.h"

// Número de jugadores en el juego
#define NUM_JUGS 4

// Número de cartas que tiene cada jugador
#define NUM_CARTAS_JUG 10

// Estructura para representar un jugador con sus cartas
typedef struct {
    t_carta cartas[NUM_CARTAS_JUG]; // Cartas del jugador
    int num_cartas;                // Número de cartas actuales del jugador
} t_jugador;

// Reparte las cartas de la baraja entre los jugadores
void repartir_cartas(t_baraja *p_baraja, t_jugador jugadores[NUM_JUGS]);

// Imprime las cartas de todos los jugadores, con posibilidad de ocultar cartas de los demás jugadores
void imprimir_jugadores(t_jugador jugadores[NUM_JUGS], int jugador_humano, int ocultar_cartas);

// Pregunta al usuario si hay un jugador humano y retorna 0 si lo hay, -1 si no
int obtener_jugador_humano();

// Pregunta al usuario si desea ocultar las cartas de los demás jugadores
int preguntar_ocultar_cartas();

#endif
