#ifndef CARTA_H
#define CARTA_H

// Definición de palos de la baraja
#define PAL_OROS 0
#define PAL_COPAS 1
#define PAL_ESPADAS 2
#define PAL_BASTOS 3

// Definición de las dimensiones de la baraja
#define NUM_NUMS 10 // Números disponibles por palo
#define NUM_PALS 4  // Número de palos

// Estructura que representa una carta con su palo y número
typedef struct {
    int pal; // Palo de la carta
    int num; // Número de la carta
} t_carta;

// Imprime una carta con su palo y número
void imprimir_carta(int pal, int num);

#endif
