#ifndef CARTA_H
#define CARTA_H

// Definición de constantes
#define NUM_NUMS 12   // Número de identificadores (cartas por palo)
#define NUM_PALS 4    // Número de palos
#define PAL_OROS 0
#define PAL_BASTOS 1
#define PAL_COPAS 2
#define PAL_ESPADAS 3

// Definición de tipos
typedef struct {
    int num; // Número o figura de la carta (0-11)
    int pal; // Palo de la carta (0-3)
} t_carta;

// Prototipo de funciones
void imprimir_carta(int pal, int num);

#endif
