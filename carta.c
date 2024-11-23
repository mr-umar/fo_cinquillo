#include <stdio.h>
#include "carta.h"
#include "colores.h"

// Función para imprimir una carta en el formato "[Oros 3]" o "[Oros Rey]"
void imprimir_carta(int pal, int num) {
    // Definir los palos y figuras
    char *palos[] = {"Oros", "Bastos", "Copas", "Espadas"};
    char *figuras[] = {"As", "2", "3", "4", "5", "6", "7", "Sota", "Caballo", "Rey"};

    // Si el número es menor que 7, es un número regular (1-7)
    if (num <= 6) {
        printf("[%s %d] ", palos[pal], num + 1);  // El +1 es para mapear los números de 0-6 a 1-7
    }
    // Si el número es mayor que 6, es una figura (Sota, Caballo, Rey)
    else {
        printf("[%s %s] ", palos[pal], figuras[num - 7]);  // Los números mayores se mapean a figuras
    }
}
