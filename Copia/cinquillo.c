#include <stdio.h>
#include "colores.h"
#include "azar.h"
#include "duerme.h"
#include "carta.h"
#include "baraja.h"
#include "jugador.h"
#include "mesa.h"
#include "partida.h"

int main() {
    t_jugador jugadores[NUM_JUGS];
    t_baraja baraja;
    int mantel[NUM_NUMS][NUM_PALS] = {0}; // Matriz para representar el mantel (inicializado a FALSE)
    t_carta carta_seleccionada;
    int jugador_que_empieza, jugador_actual;
    int final = FALSE;

    // Inicializamos baraja y azar
    crear_baraja(&baraja);
    inicializar_azar();
    repartir_cartas(&baraja, jugadores);

    // Poner el 5 de oros en el mantel
    jugador_que_empieza = poner_5_oros(jugadores, mantel);



    // Bucle del juego
    do {
        for (int i = jugador_que_empieza; i < NUM_JUGS && !final; i++) {
            imprimir_jugadores(jugadores);
            imprimir_mantel(mantel);
            printf("\nTurno de JUG#%d:\n", i);
            jugador_actual = i;
            int puede_jugar = pedir_carta(i, jugadores, mantel, &carta_seleccionada);
            if (puede_jugar) {
                final = poner_carta(carta_seleccionada, i, jugadores, mantel);
            } else {
                printf("\nNinguna jugada posible. Paso.\n");
            }
            // duerme_un_rato();
        }
        jugador_que_empieza = 0; // Reiniciar al jugador 0 para el ciclo
    } while (!final);

    imprimir_jugadores(jugadores);
    imprimir_mantel(mantel);
    printf_color_negrita();
    printf("\nHA GANADO EL JUGADOR #%d.\n\n", jugador_actual);
    printf_reset_color();

    return 0;
}