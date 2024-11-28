#include "baraja.h"
#include "azar.h"

void crear_baraja(t_baraja *p_baraja) {
    int index = 0;
    for (int p = 0; p < NUM_PALS; p++) {
        for (int n = 0; n < NUM_NUMS; n++) {
            p_baraja->cartas[index].pal = p;
            p_baraja->cartas[index].num = n;
            index++;
        }
    }
    p_baraja->num_cartas = 40;
}

t_carta sacar_carta_baraja(t_baraja *p_baraja) {
    int indice = numero_al_azar(p_baraja->num_cartas);
    t_carta carta = p_baraja->cartas[indice];
    p_baraja->cartas[indice] = p_baraja->cartas[--(p_baraja->num_cartas)];
    return carta;
}
