#include <stdio.h>
#include "carta.h"
#include "colores.h"
#include "baraja.h"
#include "azar.h"  // Asegurarnos de incluir la librería de azar

#define NUM_JUGS 4       // Número de jugadores
#define NUM_CARTAS_JUG 10 // Número de cartas por jugador

typedef struct {
    t_carta cartas[NUM_CARTAS_JUG]; // Cartas del jugador
    int num_cartas;                 // Número de cartas que tiene el jugador
} t_jugador;

int main() {
    // Inicialización de la generación de números aleatorios
    inicializar_azar();

    // Declaración de jugadores
    t_jugador jugadores[NUM_JUGS];

    // Declaración del mantel (matriz booleana para las cartas jugadas)
    int mantel[12][4] = {0};  // 12 filas (cartas), 4 columnas (palos)

    // Declaración de la baraja
    t_baraja baraja;

    // Crear la baraja
    crear_baraja(&baraja);

    // Repartir cartas a los jugadores
    for (int i = 0; i < NUM_JUGS; i++) {
        for (int j = 0; j < NUM_CARTAS_JUG; j++) {
            jugadores[i].cartas[j] = sacar_carta_baraja(&baraja);  // Repartir una carta
        }
        jugadores[i].num_cartas = NUM_CARTAS_JUG;  // Asignar número de cartas al jugador
    }

    // Imprimir las cartas de los jugadores
    for (int i = 0; i < NUM_JUGS; i++) {
        printf("JUG #%d: ", i + 1);
        for (int j = 0; j < NUM_CARTAS_JUG; j++) {
            imprimir_carta(jugadores[i].cartas[j].pal, jugadores[i].cartas[j].num);
        }
        printf("\n");
    }

    // Imprimir el mantel vacío
    printf("\n[ORO] [COP] [ESP] [BAS]\n");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            if (mantel[i][j] == 0) {
                printf("[- -] ");
            } else {
                printf("[%c %d] ", (j == 0) ? 'O' : (j == 1) ? 'C' : (j == 2) ? 'E' : 'B', mantel[i][j]);
            }
        }
        printf("\n");
    }

    // Simular turno de un jugador
    printf("\nTurno de JUG#3:\n");
    printf("Tiradas posibles: 1: [C 5] 2: [E 5] 3: [B 5]\n");
    printf("¿Que tirada realizas? 3\n");

    // Actualizar mantel con la jugada seleccionada
    mantel[4][3] = 5;  // Se coloca el 5 de Bastos en la posición correspondiente

    // Imprimir el mantel actualizado
    printf("\n[ORO] [COP] [ESP] [BAS]\n");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            if (mantel[i][j] == 0) {
                printf("[- -] ");
            } else {
                printf("[%c %d] ", (j == 0) ? 'O' : (j == 1) ? 'C' : (j == 2) ? 'E' : 'B', mantel[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
