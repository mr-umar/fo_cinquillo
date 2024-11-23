#ifndef BARAJA_H
#define BARAJA_H

#include "carta.h"

// Definición de la estructura para la baraja
typedef struct {
    t_carta cartas[NUM_PALS * NUM_NUMS]; // 48 cartas en total
    int num_cartas;  // Número total de cartas en la baraja
} t_baraja;

// Prototipo de funciones
void crear_baraja(t_baraja *p_baraja);
t_carta sacar_carta_baraja(t_baraja *p_baraja);

#endif
