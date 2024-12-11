#ifndef PARTIDA_H
#define PARTIDA_H

#include "carta.h"
#include "jugador.h"
#include "mesa.h"

// Estructura para almacenar las posibles cartas que se pueden jugar
typedef struct {
    t_carta cartas[NUM_CARTAS_JUG]; // Arreglo de cartas posibles
    int num_cartas;                // Número de cartas posibles
} t_cartas_posibles;

// Coloca el 5 de oros en el mantel y determina quién será el siguiente jugador
int poner_5_oros(t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]);

// Permite que un jugador realice una tirada (humano o IA)
int pedir_carta(int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS], t_carta *carta_seleccionada, int es_humano);

// Verifica si una carta puede ser jugada en el mantel
int es_posible(t_carta carta, int mantel[NUM_NUMS][NUM_PALS]);

// Coloca una carta en el mantel y verifica si el jugador ha ganado
int poner_carta(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS], int mantel[NUM_NUMS][NUM_PALS]);

// Elimina una carta de la mano del jugador después de jugarla
void eliminar_carta_jugador(t_carta carta, int num_jugador, t_jugador jugadores[NUM_JUGS]);

#endif
