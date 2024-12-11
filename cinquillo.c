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
    int jugador_humano = obtener_jugador_humano();
    int ocultar_cartas = preguntar_ocultar_cartas();

    // Inicializamos baraja y azar
    crear_baraja(&baraja);
    inicializar_azar();
    repartir_cartas(&baraja, jugadores);

    // Poner el 5 de oros en el mantel
    jugador_actual = poner_5_oros(jugadores, mantel);

    // Bucle del juego
    while (!final) {
        imprimir_jugadores(jugadores, jugador_humano, ocultar_cartas);
        imprimir_mantel(mantel);

        duerme_un_rato();

        printf("\nTurno de JUG#%d:\n", jugador_actual + 1);

        int puede_jugar = pedir_carta(jugador_actual, jugadores, mantel, &carta_seleccionada, jugador_actual == jugador_humano);

        if (puede_jugar) {
            final = poner_carta(carta_seleccionada, jugador_actual, jugadores, mantel);
        }

        // Avanzar al siguiente jugador
        jugador_actual = (jugador_actual + 1) % NUM_JUGS;
    }

    int jugador_previo = jugador_actual == 0 ? NUM_JUGS - 1 : jugador_actual - 1;

    imprimir_jugadores(jugadores, jugador_humano, 0); // Mostrar todo al final
    imprimir_mantel(mantel);
    printf_color_negrita();
    printf("\nHA GANADO EL JUGADOR #%d.\n\n", jugador_previo + 1);
    printf_reset_color();

    return 0;
}
