#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sudoku[9][9]; 



int validarMovimiento(int num, int fila, int columna) {
    
    for (int i = 0; i < 9; i++) {
        if (sudoku[fila][i] == num || sudoku[i][columna] == num) {
            return 0; // Número ya existe en la fila o columna
        }
    }
    
    // Calcular el inicio de la fila y columna del recuadro interno
    int startFila = (fila / 3) * 3;
    int startCol = (columna / 3) * 3;

    // Verificar el recuadro interno de 3x3
    for (int i = startFila; i < startFila + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }

    return 1; // Movimiento válido
}



void imprimirSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("|%d|", sudoku[i][j]);
        }
        printf("\n");
    }
}


void jugarSudoku() {
    int numero, X, Y;
    for (int k = 0; k < 9; k++) {
        imprimirSudoku();
        printf("Ingrese el número: ");
        scanf("%d", &numero);
        printf("Ingrese la posición X: ");
        scanf("%d", &X);
        printf("Ingrese la posición Y: ");
        scanf("%d", &Y);
        if (X < 0 || X >= 9 || Y < 0 || Y >= 9) {
            printf("Posición inválida. Debe estar entre 0 y 8.\n");
            k--; // Reintentar la misma iteración
            continue;
        }
        if (!validarMovimiento(numero, X, Y)) {
            printf("Movimiento inválido. El número ya existe en la fila o columna.\n");
            k--; // Reintentar la misma iteración
            continue;
        }
        sudoku[X][Y] = numero;
    }
     imprimirSudoku();
}

int main() {
    // Inicializar el sudoku con ceros
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = 0;
        }
    }
    	srand(time(NULL));
	for (int i=0; i<9; i++){
for (int j=0; j<9; j++){
	int fila_num = rand() % (8) + 0;
	 int Col_num = rand() % (8) + 0;
	  int num = rand() % (9) + 1;
	  validarMovimiento (num, fila_num, Col_num);
	if (validarMovimiento){
		 j--;
            continue;
	}
	else {
		sudoku[i][j]=num;
		printf ("|%d|",sudoku[i][j]);
	}
	  }
	  printf ("\n");
}

    // Jugar Sudoku
    jugarSudoku();

    return 0;
}
