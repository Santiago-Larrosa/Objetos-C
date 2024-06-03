#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

char tablero[FILAS][COLUMNAS];

// Inicializa el tablero con espacios en blanco
void inicializarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }
}

// Imprime el tablero actual
void imprimirTablero() {
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        printf(" %c | %c | %c \n", tablero[i][0], tablero[i][1], tablero[i][2]);
        if (i != FILAS - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Verifica si un jugador ganó
char ganador() {
    // Verifica filas y columnas
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2] && tablero[i][0] != ' ') {
            return tablero[i][0];
        }
        if (tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i] && tablero[0][i] != ' ') {
            return tablero[0][i];
        }
    }
    // Verifica diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2] && tablero[0][0] != ' ') {
        return tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0] && tablero[0][2] != ' ') {
        return tablero[0][2];
    }
    // Si no hay ganador
    return ' ';
}

// Verifica si el tablero está lleno
int tableroLLeno() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == ' ') {
                return 0; // Todavía hay espacio en el tablero
            }
        }
    }
    return 1; // El tablero está lleno
}

// Realiza el movimiento del jugador
void realizarMovimiento(char jugador, int fila, int columna) {
    tablero[fila][columna] = jugador;
}

int main() {
    char jugadorActual = 'X';
    int fila, columna;
    
    inicializarTablero();
    
    printf("Bienvenido al Ta-Te-Ti\n");
    
    while (1) {
        imprimirTablero();
        
        // Pedir movimiento al jugador
        printf("Jugador %c, ingrese la fila y columna  (ejemplo: 1 1): ", jugadorActual);
        scanf("%d %d", &fila, &columna);
        
        // Verificar si la posición está ocupada
        if (tablero[fila][columna] != ' ') {
            printf("Esa posición ya está ocupada\n");
            continue;
        }
        
        // Realizar el movimiento
        realizarMovimiento(jugadorActual, fila, columna);
        
        // Verificar si hay un ganador o si el tablero está lleno
        if (ganador() == 'X') {
            imprimirTablero();
            printf("¡El jugador X ha ganado!\n");
            break;
        } else if (ganador() == 'O') {
            imprimirTablero();
            printf("¡El jugador O ha ganado!\n");
            break;
        } else if (tableroLLeno()) {
            imprimirTablero();
            printf("¡El juego ha terminado en empate!\n");
            break;
        }
        
        // Cambiar el turno del jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
