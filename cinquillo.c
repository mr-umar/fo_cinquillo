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
    int jugador_actual, final = FALSE;
    int jugador_humano = -1;

    // Preguntar si hay un jugador humano
    char respuesta;
    do {
        printf("¿Hay algún jugador humano? [s/n]: ");
        scanf(" %c", &respuesta);
        if (respuesta == 's' || respuesta == 'S') {
            jugador_humano = NUM_JUGS - 1;  // Jugador humano será el jugador número 3 (último)
        } else if (respuesta == 'n' || respuesta == 'N') {
            jugador_humano = -1; // No hay jugador humano
        } else {
            printf("Por favor, responde 's' o 'n'.\n");
        }
    } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');

    // Inicializamos baraja y azar
    crear_baraja(&baraja);
    inicializar_azar();
    repartir_cartas(&baraja, jugadores);

    // Poner el 5 de oros en el mantel
    jugador_actual = poner_5_oros(jugadores, mantel);

    // Bucle del juego
    while (!final) {
        imprimir_jugadores(jugadores);
        imprimir_mantel(mantel);
        printf("\nTurno de JUG#%d:\n", jugador_actual);

        int puede_jugar = pedir_carta(jugador_actual, jugadores, mantel, &carta_seleccionada, jugador_actual == jugador_humano);

        if (puede_jugar) {
            final = poner_carta(carta_seleccionada, jugador_actual, jugadores, mantel);
        }

        // Avanzar al siguiente jugador de manera cíclica
        jugador_actual = (jugador_actual + 1) % NUM_JUGS;
    }

    int jugador_previo = jugador_actual == 0 ? NUM_JUGS - 1 : jugador_actual - 1;

    imprimir_jugadores(jugadores);
    imprimir_mantel(mantel);
    printf_color_negrita();
    printf("\nHA GANADO EL JUGADOR #%d.\n\n", jugador_previo);
    printf_reset_color();

    return 0;
}
