#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define FILAS 10
#define COLUMNAS 10
#define VIDAS_INICIALES 3

int tablero[FILAS][COLUMNAS];
int vidas = VIDAS_INICIALES;
int fila_actual=0;
int columna_actual=0;

// Función para inicializar el tablero con unos (1) y colocar aleatoriamente algunos ceros (0) para representar los pozos
void inicializarTablero() {
    // Inicializar con unos
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = 1;
        }
    }

    // Colocar aleatoriamente algunos ceros (pozos)
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;
        if ( tablero[fila][columna] == 0){
        	i--;
        	continue;
		}
        tablero[fila][columna] = 0;
    }

    // Asegurarse de que no haya un pozo en la posición inicial (0, 0)
    tablero[0][0] = 1;
}

// Función para imprimir el tablero
void imprimirTablero() {
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
        	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	
            if (i == fila_actual && j == columna_actual) {
            	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("   "); // S para la posición inicial
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else if (tablero[i][j] == 1) {
            	SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("   "); // Espacio vacío
             SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			} else {
				 SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("   "); // Pozo
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Función para mover al jugador
int mover(int fila, int columna) {
    // Verificar si la nueva posición está dentro de los límites del tablero
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
        printf("Movimiento fuera de los límites del tablero.\n");
        return 0;
    }

    // Verificar si hay un pozo en la nueva posición
    if (tablero[fila][columna] == 0) {
        printf("¡Caíste en un pozo! Pierdes una vida.\n");
        vidas--;
        if (vidas == 0) {
            printf("¡Te quedaste sin vidas! Has perdido el juego.\n");
            return -1; // El jugador ha perdido
        }
        printf("Vidas restantes: %d\n", vidas);
        return 0;
    }

    printf("Movimiento válido.\n");
    return 1;
}

int main() {
    
    char direccion;

    // Inicializar el tablero
    inicializarTablero();

    printf("Bienvenido al juego. Encuentra el camino seguro hacia la posición [9][9].\n");
    printf("Tienes %d vidas.\n", vidas);

    while (1) {
    	system("cls");
        imprimirTablero();

        // Pedir al jugador que elija una dirección
        printf("Elige una dirección (W para arriba, S para abajo, A para izquierda, D para derecha): ");
        scanf(" %c", &direccion);

        // Actualizar la posición del jugador según la dirección elegida
        switch (direccion) {
            case 'W':
            case 'w':
                if (mover(fila_actual - 1, columna_actual) == 1) {
                    fila_actual--;
                }
                break;
            case 'S':
            case 's':
                if (mover(fila_actual + 1, columna_actual) == 1) {
                    fila_actual++;
                    
                }
                break;
            case 'A':
            case 'a':
                if (mover(fila_actual, columna_actual - 1) == 1) {
                    columna_actual--;
                }
                break;
            case 'D':
            case 'd':
                if (mover(fila_actual, columna_actual + 1) == 1) {
                    columna_actual++;
                }
                break;
            default:
                printf("Dirección no válida. Por favor, elige una dirección válida.\n");
                break;
        }
         
        // Verificar si el jugador ha llegado a la posición final
        if (fila_actual == FILAS - 1 && columna_actual == COLUMNAS - 1) {
        		system("cls");
        	 imprimirTablero();
            printf("¡Felicidades! llegaste a la posición 9 9 y ganaste.\n");
           
            break;
        }
    }

    return 0;
}
