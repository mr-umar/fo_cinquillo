#include "baraja.h"
#include "azar.h"

// Función para crear la baraja con todas las cartas posibles
void crear_baraja(t_baraja *p_baraja) {
    int index = 0;
    for (int pal = 0; pal < 4; pal++) {  // Los 4 palos (Oros, Copas, Espadas, Bastos)
        for (int num = 0; num < 12; num++) {  // Números de 1 a 12
            p_baraja->cartas[index].pal = pal;
            p_baraja->cartas[index].num = num + 1;  // Los números van de 1 a 12
            index++;
        }
    }
    p_baraja->num_cartas = 48; // Total de cartas en la baraja (4 palos * 12 cartas)
}

// Función para sacar una carta aleatoria de la baraja
t_carta sacar_carta_baraja(t_baraja *p_baraja) {
    int index = numero_al_azar(p_baraja->num_cartas);  // Obtiene un índice aleatorio de la baraja
    t_carta carta = p_baraja->cartas[index];

    // Reemplazar la carta sacada con la última carta disponible
    p_baraja->cartas[index] = p_baraja->cartas[p_baraja->num_cartas - 1];
    p_baraja->num_cartas--;  // Reducir el número de cartas disponibles

    return carta;
}
