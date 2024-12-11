# fo_cinquillo
♠️ Proyecto de FO para el juego del cinquillo

Compilar:
```sh
gcc cinquillo.c carta.c baraja.c jugador.c mesa.c partida.c colores.c azar.c duerme.c -o cinquillo 
```

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
├── carta.c                   # Implementación de las funciones relacionadas con las cartas, como impresión y validación
├── carta.h                   # Definición de las constantes y funciones relacionadas con las cartas
├── baraja.c                  # Implementación de las funciones relacionadas con la baraja (crear y gestionar)
├── baraja.h                  # Definición de la baraja y sus funciones
├── jugador.c                 # Implementación de las funciones relacionadas con los jugadores, incluyendo interacción del humano
├── jugador.h                 # Definición de los jugadores y sus funciones, como ocultar cartas y obtener jugadas
├── mesa.c                    # Implementación de las funciones relacionadas con la mesa (mantel y su impresión)
├── mesa.h                    # Definición de las funciones y constantes para la mesa
├── partida.c                 # Funciones relacionadas con la partida, como turnos, jugadas y detección del ganador
└── partida.h                 # Definición de las funciones de la partida, como inicialización y lógica del juego
```





