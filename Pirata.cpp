#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int sudoku[9][9]; 

int validarMovimiento(int num, int fila, int columna) {
    // Verificar la fila y la columna
    for (int i = 0; i < 9; i++) {
        if (sudoku[fila][i] == num || sudoku[i][columna] == num) {
            return 0; // Número ya existe en la fila o columna
        }
    }
    
    // Calcular el inicio de la fila y columna del recuadro interno 3x3
    int comFila = (fila / 3) * 3;
    int comCol = (columna / 3) * 3;

    // Verificar el recuadro interno de 3x3
    for (int i = comFila; i < comFila + 3; i++) {
        for (int j = comCol; j < comCol + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0; // Número que ya existe en el recuadro 3x3
            }
        }
    }

    return 1; // Movimiento válido
}
//Imprime sudoku
void imprimirSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                printf("| |");
            } else {
                printf("|%d|", sudoku[i][j]);
            }
        }
        printf("\n");
    }
}
//Creao sudoku
void CrearSudoku(){
    srand(time(NULL));
    int num, fila, columna;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = 0; // Inicializar el tablero con cero
        }
    }

    // Llenar el tablero de Sudoku con números válidos
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int intentos = 0;
            do {
            	//entre 1 y 9
                num = rand() % 9 + 1;
                intentos++;
                if (intentos > 50) {
				//Si hay muchos errores vuelvo a empezar
				for (i = 0; i < 9; i++){
					for (j = 0; j < 9; j++){
						sudoku [i][j]=0;
					} 
				}
				i=0;
				j=0;
				intentos=0; }
				//Funciona hasta que se valida
            } while (!validarMovimiento(num, i, j));
            if (intentos <= 50) {
                sudoku[i][j] = num;
            }
        }
    }
}

void SudokuDificultad(int dificultad){
    srand(time(NULL));
    int dif = 0;
    int i = 0, j = 0;
    int Base[9][9] = {0}; // Inicializar el tablero a cero

    switch (dificultad) {
        case 1:
            dif = 80;
            break;
        case 2:
            dif = 32;
            break;
        case 3:
            dif = 17;
            break;
        default:
            dif = 32;
            break;
    }

    for (i = 0; i < dif; i++) {
        int fila_num, col_num;
        do {
            fila_num = rand() % 9;
            col_num = rand() % 9;
        } while (Base[fila_num][col_num] == 10); 
        Base[fila_num][col_num] = 10; 
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (Base[i][j] == 10) {
                Base[i][j] = sudoku[i][j]; // Copiar el valor del sudoku original
                
            } else {
               
            }
        }
        
    }
    for (i = 0; i < 9; i++) {
    	for (j = 0; j < 9; j++){
    		sudoku[i][j]=Base[i][j];
		}
	}
}
int Ganar (){
	int i=0;
	int j=0;
	int gano=0;
	for (i = 0; i < 9; i++){
					for (j = 0; j < 9; j++){
						if (sudoku[i][j]==0){
							gano++;
						}
	
}


}
if (gano==0){
	return 1;
	
}
else {
	return 0;
	
}
}

void jugarSudoku() {
    int numero, X, Y;
    int k=0;
    do {
    	system("cls");
        imprimirSudoku();
        printf("Ingrese el número: ");
        scanf("%d", &numero);
        printf("Ingrese la posición X: ");
        scanf("%d", &X);
        printf("Ingrese la posición Y: ");
        scanf("%d", &Y);
        if (X < 0 || X >= 9 || Y < 0 || Y >= 9|| sudoku [X][Y]!=0) {
            printf("Posición inválida.\n");
            k--; // Reintentar la misma iteración
            continue;
        }
        if (!validarMovimiento(numero, X, Y)) {
            printf("Movimiento inválido. El número ya existe en la fila, columna o subcuadro.\n");
            k--; // Reintentar la misma iteración
            continue;
        }
        sudoku[X][Y] = numero;
         int hola = Ganar ();
    if (hola==1){
    	printf ("GANASTE!!!!");
    	k=10;
		}
		if (k==9){
			 imprimirSudoku();
		}
	k++;
    }  while (k<9);
   
}


int main() {
    // Inicializar el sudoku con ceros
    int Sudoku2[9][9];
    int dificultad;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = 0;
        }
    }

    CrearSudoku();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            Sudoku2[i][j] = sudoku[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("|%d|", sudoku[i][j]);
        }
        printf("\n");
    }

    printf("Elija la dificultad (1=Facil; 2=Medio; 3=Dificil): ");
    scanf("%d", &dificultad);

    SudokuDificultad(dificultad);    
    jugarSudoku();

    return 0;
}
