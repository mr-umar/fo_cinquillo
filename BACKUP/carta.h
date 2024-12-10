#ifndef CARTA_H
#define CARTA_H

#define PAL_OROS 0
#define PAL_COPAS 1
#define PAL_ESPADAS 2
#define PAL_BASTOS 3

#define NUM_NUMS 10
#define NUM_PALS 4

typedef struct {
    int pal;
    int num;
} t_carta;

void imprimir_carta(int pal, int num);

#endif