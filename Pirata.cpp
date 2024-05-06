#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8 
int fila_tes, col_tes;
char tablero[N][N];
int fila_pirata, col_pirata; 


void inicializarTablero() {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                tablero[i][j] = 'X'; 
            } else {
                tablero[i][j] = ' '; 
            }
        }
    }

    fila_pirata = rand() % (N - 2) + 1; 
    col_pirata = rand() % (N - 2) + 1;
    tablero[fila_pirata][col_pirata] = 'P'; 

  
    do {
        fila_tes = rand() % (N - 2) + 1;
        col_tes = rand() % (N - 2) + 1;
    } while (fila_tes == fila_pirata && col_tes == col_pirata);
    tablero[fila_tes][col_tes] = 'T'; 
}


void actualizarPirata(int nueva_fila, int nueva_col) {
    
    tablero[fila_pirata][col_pirata] = ' ';
    
    tablero[nueva_fila][nueva_col] = 'P';
    
    fila_pirata = nueva_fila;
    col_pirata = nueva_col;
}


void test() {
    printf("fila_tes: %d, col_tes: %d\n", fila_tes, col_tes);
}


void dibujarTablero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == 'P') {
                printf("o ");
            } else if (tablero[i][j] == 'T') {
                printf("T ");
            } else if (tablero[i][j] == 'X') {
                printf("~ ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}


void buscarTesoro() {
    int movimientos = 0;
    int encontrado = 0;
    int perdido = 0;

    printf("¡Comienza la búsqueda!\n");

    
    while (movimientos < 50 && !encontrado && !perdido) {
        printf("Movimiento %d. Posición actual del pirata: (%d, %d)\n", movimientos + 1, fila_pirata, col_pirata);
        printf("Ingresa la dirección para mover al pirata (N/S/E/O): ");
        char direccion;
        scanf(" %c", &direccion);

       
        int nueva_fila = fila_pirata;
        int nueva_col = col_pirata;
        switch (direccion) {
            case 'N':
                nueva_fila = (fila_pirata > 0) ? fila_pirata - 1 : fila_pirata;
                break;
            case 'S':
                nueva_fila = (fila_pirata < N - 1) ? fila_pirata + 1 : fila_pirata;
                break;
            case 'E':
                nueva_col = (col_pirata < N - 1) ? col_pirata + 1 : col_pirata;
                break;
            case 'O':
                nueva_col = (col_pirata > 0) ? col_pirata - 1 : col_pirata;
                break;
            default:
                printf("Dirección inválida. Ingresa N, S, E u O.\n");
                
        }


        if (tablero[nueva_fila][nueva_col] == 'X') {
            perdido = 1;
            printf("¡Te has hundido en el agua! ¡Has perdido!\n");
            break;
        }

        
        actualizarPirata(nueva_fila, nueva_col);

        
        dibujarTablero();

        test();
        if (tablero[fila_pirata][col_pirata] == tablero[fila_tes][col_tes]) {
            printf("¡Encontraste el tesoro! ¡Felicidades!\n");
            encontrado = 1;
        }

        movimientos++;
    }

   
    if (!encontrado && !perdido)
        printf("Se acabaron los movimientos. ¡El tesoro sigue escondido!\n");
}

int main() {
    int opcion;

    do {
        printf("\nMENU\n");
        printf("1. Inicializar Tablero\n");
        printf("2. Dibujar Tablero\n");
        printf("3. Buscar Tesoro\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                inicializarTablero();
                printf("Tablero inicializado.\n");
                break;
            case 2:
                printf("Tablero actual:\n");
                dibujarTablero();
                break;
            case 3:
                buscarTesoro();
                break;
            case 4:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
