#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int fila_tes, col_tes;
//La matriz de tablero la hago un char
char **tablero;
int fila_pirata, col_pirata;
//Extencion de la matriz
int N;

//Funcion para crear el tablero
void inicializarTablero() {
    srand(time(NULL));
    //Recorro la matriz asignando el valor dependiendo de que sea:
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        
            if (i == 0 || i == N - 1 || j == N - 1) {
            	//X es el agua que no esta en el borde contra la pared
                tablero[i][j] = 'X';}
                //Y es el agua que esta pegada contra la pared
                else if (j==0){
        		tablero[i][j]='Y';
			}
			// ' ' es la arena
            else {
                tablero[i][j] = ' ';
            }
        }
    }
    //Creo la posicion del pirata
    fila_pirata = rand() % (N - 2) + 1;
    col_pirata = rand() % (N - 2) + 1;
    tablero[fila_pirata][col_pirata] = 'P';

    //Genero posiciones de tesoro hasta que no sean iguales a pirata
    do {
        fila_tes = rand() % (N - 2) + 1;
        col_tes = rand() % (N - 2) + 1;
    } while (fila_tes == fila_pirata && col_tes == col_pirata);
    tablero[fila_tes][col_tes] = 'T';
}
//Funcion para actualizar la posicion del pirata
void actualizarPirata(int nueva_fila, int nueva_col) {
    // La posicion vieja del pirata se convierte en arena
    tablero[fila_pirata][col_pirata] = ' ';
    //Se actualiza la nueva posicion del pirata
    tablero[nueva_fila][nueva_col] = 'P';
    //Se actualiza la nueva posicion del pirata
    fila_pirata = nueva_fila;
    col_pirata = nueva_col;
}

void test() {
	//Son los hacks para ubicar el tesoro
    printf("\n\n    Hacks fil: %d, col: %d\n", fila_tes, col_tes);
}
//Funcion para dibujar el tablero
void dibujarTablero() {
	//Recorro toda la matriz
	system("cls");
    for (int i = 0; i < N; i++) {
    
        
        for (int j = 0; j < N; j++) {
        		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	 
        	//Asigno lo que se imprime correspondientemente
        	if (tablero[i][j] == 'Y'){
        		printf ("                      ");
        		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				printf ("  ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
            else if (tablero[i][j] == 'P') {
            	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
                printf("  ");
            } else if (tablero[i][j] == 'T') {
            	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                printf("  ");
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } 
			
			else if (tablero[i][j] == 'X') {
				if (i==0 && j==0){
					printf ("                      ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					printf ("  ");
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else if (i==N-1 && j==0){
					printf ("                      ");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN);
					printf ("  ");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else{
					if (i==0 && j==N-1){
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN);
                printf("  ");
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					}
					else {
					
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                printf("  ");}
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
            } 
			else {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                printf("  ");
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        printf("\n");
    }
}
//Funcion del jeugo en si
void buscarTesoro() {
    int movimientos = 0;
    int encontrado = 0;
    int perdido = 0;

    printf("         \n\n    A BUSCAR!\n\n");
    //Un for con 50 movimientos maximos y comprueba si es que se encontro el tesoro o si perdio
    while (movimientos < 50 && !encontrado && !perdido) {
    	//Menciono la ubicacion del pirata
        printf("    Movimientos:%d.\n\n    Posicion actual del pirata: (%d, %d)\n\n", movimientos + 1, fila_pirata, col_pirata);
        //Me muevo
        printf("    Ingresa la direccion para mover al pirata (N/S/E/O): ");
        //Es un char para recibir letras
        char direccion;
        scanf(" %c", &direccion);
        //Se actualiza la posicion
        int nueva_fila = fila_pirata;
        int nueva_col = col_pirata;
        //Switch para el movimiento
        switch (direccion) {
            case 'N':
            	//compruebo que no se salga del mapa
                nueva_fila = (fila_pirata > 0) ? fila_pirata - 1 : fila_pirata;
                break;
            case 'S':
                nueva_fila = (fila_pirata < N - 1) ? fila_pirata + 1 : fila_pirata;
                break;
            case 'E':
                nueva_col = (col_pirata < N - 1) ? col_pirata + 1 : col_pirata;
                break;
            case 'O':
                nueva_col = (col_pirata > N-N) ? col_pirata - 1 : col_pirata;
                break;
            default:
                printf("    Dirección inválida. Ingresa N, S, E u O.\n");
        }
        //Me fijo si toco agua
       if (tablero[nueva_fila][nueva_col] == 'X' || tablero[nueva_fila][nueva_col] == 'Y') {
            perdido = 1;
            printf("    Te has hundido en el agua! Has perdido!\n");
            break;
        }
        //Llamo a la funcion para actualizar la poscion
        actualizarPirata(nueva_fila, nueva_col);
        //Dibujo el tablero actualizado
        dibujarTablero();

        //Compruebo si es que encontro el tesoro
        if (tablero[fila_pirata][col_pirata] == tablero[fila_tes][col_tes]) {
            printf("    Encontraste el tesoro! ¡Felicidades!\n");
            //Cambio el valor de encotrado así se termina
            encontrado = 1;
        }
        //Actualizo los movimientos
	        movimientos++;
	    }
	    //Aviso si pierde en el caso de haber llegado a 50 y no haber encontrado el tesoro
    if (!encontrado && !perdido)
        printf("    Se acabaron los movimientos.\n");
}

int main() {
    int opcion;
   
    //Pregunto el tamaño del tablero
    printf("    Ingresa el tamaño del tablero (N x N): ");
    scanf("%d", &N);


   //sirve para asignar el tamaño de tablero
    tablero = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        tablero[i] = (char *)malloc(N * sizeof(char));
    }
    //MENU
    do {
    	
    	
        printf("\n                        -MENU-\n");
        printf("      ------------Cree el tablero(1)------------\n");
        printf("      ------------Dibujar Tablero(2)------------\n");
        printf("      -------------Buscar Tesoro(3)-------------\n");
        printf("      -----------------Salir(4)-----------------\n");
        printf("\n\n Selecciona una opcion:\n ___________________\n ");
        scanf("%d", &opcion);
        //switch de MENU
        switch (opcion) {
            case 1:
            	//inicializo el tablero
                inicializarTablero();
                printf("    Tablero inicializado.\n");
                break;
            case 2:
            	//Lo dibujo
                printf("    Tablero actual:\n");
                dibujarTablero();
                break;
            case 3:
            	//Buscar
                buscarTesoro();
                break;
            case 4:
            	//Irse
                printf("    Hasta luego!\n");
                break;
            default:
                printf("    Opción inválida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 4);

   

    return 0;
}
