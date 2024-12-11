#include <stdio.h>
#include "colores.h"
#include "azar.h"
#include "duerme.h"
#include "carta.h"
#include "baraja.h"
#include "jugador.h"
#include "mesa.h"
#include "partida.h"

// Función principal que gestiona la ejecución del juego
int main() {
    t_jugador jugadores[NUM_JUGS]; // Array de jugadores
    t_baraja baraja;              // Estructura de la baraja
    int mantel[NUM_NUMS][NUM_PALS] = {0}; // Matriz para representar el mantel (inicializado a FALSE)
    t_carta carta_seleccionada;   // Carta seleccionada por el jugador actual
    int jugador_actual, final = FALSE; // Control del jugador actual y estado del juego
    int jugador_humano = obtener_jugador_humano(); // Determina si hay un jugador humano
    int ocultar_cartas = preguntar_ocultar_cartas(); // Decide si ocultar las cartas

    // Inicialización de la baraja y sistema de azar
    crear_baraja(&baraja);
    inicializar_azar();
    repartir_cartas(&baraja, jugadores);

    // Poner el 5 de oros en el mantel para iniciar el juego
    jugador_actual = poner_5_oros(jugadores, mantel);

    // Bucle principal del juego
    while (!final) {
        imprimir_jugadores(jugadores, jugador_humano, ocultar_cartas); // Muestra las cartas de los jugadores
        imprimir_mantel(mantel); // Muestra el estado actual del mantel

        duerme_un_rato();

        printf("\nTurno de JUG#%d:\n", jugador_actual + 1);

        // Determina si el jugador actual puede realizar una jugada
        int puede_jugar = pedir_carta(jugador_actual, jugadores, mantel, &carta_seleccionada, jugador_actual == jugador_humano);

        // Si puede jugar, coloca la carta en el mantel
        if (puede_jugar) {
            final = poner_carta(carta_seleccionada, jugador_actual, jugadores, mantel);
        }

        // Avanza al siguiente jugador de manera cíclica
        jugador_actual = (jugador_actual + 1) % NUM_JUGS;
    }

    
    int jugador_previo = jugador_actual == 0 ? NUM_JUGS - 1 : jugador_actual - 1;

    imprimir_jugadores(jugadores, jugador_humano, 0); 
    imprimir_mantel(mantel); 
    printf_color_negrita();
    printf("\nHA GANADO EL JUGADOR #%d.\n\n", jugador_previo + 1);
    printf_reset_color();

    return 0;
}
