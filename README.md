# fo_cinquillo
♠️ Proyecto de FO para el juego del cinquillo

El arbol de ficheros del proyecto es:

```
/cinquillo/
│
├── cinquillo.c               # Archivo principal del juego (contiene la lógica del main)
├── colores.c                 # Implementación de las funciones relacionadas con los colores
├── colores.h                 # Definición de las funciones de colores
├── azar.c                    # Implementación de funciones relacionadas con la generación de números aleatorios
├── azar.h                    # Definición de las funciones de azar
├── duerme.c                  # Implementación de funciones para pausas en el juego
├── duerme.h                  # Definición de las funciones de duerme
├── carta.c                   # Implementación de las funciones relacionadas con las cartas
├── carta.h                   # Definición de las constantes y funciones relacionadas con las cartas
├── baraja.c                  # Implementación de las funciones relacionadas con la baraja
├── baraja.h                  # Definición de la baraja y sus funciones
├── jugador.c                 # Implementación de las funciones relacionadas con los jugadores
├── jugador.h                 # Definición de los jugadores y sus funciones
├── mesa.c                    # Implementación de las funciones relacionadas con el mantel (mesa)
├── mesa.h                    # Definición de las funciones y constantes para la mesa
└── partida.c                 # Funciones relacionadas con la partida, como la inicialización y detección del final
└── partida.h                 # Definición de las funciones de la partida
```


Compilar:
```sh
gcc cinquillo.c carta.c baraja.c jugador.c mesa.c partida.c colores.c azar.c duerme.c -o cinquillo -Wall
```

 Wall: Para ver los warnings en pantalla. (Warning All)


--toDO: 
- No muestra correctamente el jugador que gana.
- El mantel no se muestra correctamente, solo muestra el número de la carta en cada columna.
- En las cartas no están en el formato que piden.

