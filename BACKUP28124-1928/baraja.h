#ifndef BARAJA_H
#define BARAJA_H
#include "carta.h"

typedef struct {
    t_carta cartas[40];
    int num_cartas;
} t_baraja;

void crear_baraja(t_baraja *p_baraja);
t_carta sacar_carta_baraja(t_baraja *p_baraja);

#endif
