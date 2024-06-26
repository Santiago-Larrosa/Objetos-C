#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int Maquina() {
    return rand() % 3 + 1; // Genero un numero entre 1 y 3
}

int Ganador(int jugador, int maquina) {
    //empate si ambos son iguales
   
    if (jugador == maquina)
        return 0;
    
    // Jugador gana
    if ((jugador == 1 && maquina == 3) || (jugador == 2 && maquina == 1) || (jugador == 3 && maquina == 2))
        return 1;
    
    if ((maquina == 1 && jugador == 3) || (maquina == 2 && jugador == 1) || (maquina == 3 && jugador == 2))
        return 2;
    // Si no es un empate ni gana el jugador entonces gana la máquina, esto incluye que el jugador ingrese algo que no deba
    return -1;
}

void mostrarResultado(int resultado) {
     
    if (resultado == 0)
        printf("\n*------*\n Empate\n*------*\n");
    else if (resultado == 1)
        printf("\n*--------*\n ¡Ganaste!\n*--------*\n");
    else if (resultado == 2)
        printf("\n*-----------*\n Perdiste :( \n*-----------*\n");
        else {
            printf ("\n*---------------------------*\n PERDISTE POR NO SABER JUGAR\n*---------------------------*\n");
        }
}


int main() {
    srand(time(NULL)); // Inicializar números aleatorios
int JugadorRonda;
     int  MaquinaRonda=0;

    for (int ronda = 1; ronda <= 5; ronda++) {
    	int puntajeJugador = 0;
    int puntajeMaquina = 0;
        printf("\n Ronda:%d\n\n Maquina | Vos  \n   %d     :  %d  \n\n",ronda,MaquinaRonda,JugadorRonda);
        for (int vuelta = 1; vuelta <= 3; vuelta++) {
            int jugadaJugador, JugadaMaquina;
            char MaquinaOp[7];
              // Generar la jugada de la máquina
            JugadaMaquina = Maquina();
            // Solicitar el movimiento del jugador
            printf("Elige tu movimiento (1 = piedra, 2 = papel, 3 = tijera): \n__________________________\n");
            scanf("%d", &jugadaJugador);

            switch (JugadaMaquina){
                   case 1:
                    strcpy(MaquinaOp, "piedra");
                   break;
                   case 2:
                    strcpy(MaquinaOp, "papel");
                   break;
                   case 3:
                    strcpy(MaquinaOp, "tijera");
                   break;
            }
          
            
            printf("\n\nLa máquina elige: %s\n", MaquinaOp);
            
            // Determinar el ganador de esta vuelta
            int resultado = Ganador(jugadaJugador, JugadaMaquina);
            mostrarResultado(resultado);

            // Actualizar puntajes
            if (resultado == 1){
                puntajeJugador++;
                
            }
            else if (resultado == 2 || resultado == -1){
                puntajeMaquina++;
             
              }
            
           
        }
 if (puntajeJugador > puntajeMaquina){
 
         JugadorRonda++;}
    else if (puntajeJugador < puntajeMaquina)
       {
	   
         MaquinaRonda++;}
    }

    // Determinar el ganador del campeonato
    if (JugadorRonda > MaquinaRonda){
        printf("¡Felicidades, sos el ganador del campeonato!\n");
       }
    else if (JugadorRonda < MaquinaRonda){
        printf("La máquina te gano  :( \n");
       }
        else{
		
        printf ("Empate");}
        printf("\n\n Maquina | Vos  \n   %d     :  %d  ",MaquinaRonda,JugadorRonda);
       
        
    return 0;
}
