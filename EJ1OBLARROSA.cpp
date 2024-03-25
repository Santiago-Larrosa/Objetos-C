#include <stdio.h>

int main () {
	int eleccion=0;
	int num=0, R=0, R1=0, a=0, b=0, c=0;
	printf ("Que ejercicio desea realizar (1,2,3,4)");
	scanf ("%d",& eleccion);
	switch (eleccion) {
		case 1:
			
			printf ("Ingrese un numero:");
			scanf ("%d", & num);
			if (num==0){
				printf ("El numero es 0");

			}
			else if (num<0){
				printf ("El numero es negativo");

			}
			else {
			printf ("El numero es positivo");

			}
			break;
			case 2:
            printf ("Ingrese un numero:");
			scanf ("%d", & num); 
			R=num%2;
			if (R==0) {
				printf ("El numero es par");
				
			}			
			else {
				printf ("El numero es impar");
			}
				break;
			case 3:
				printf ("Ingrese un numero:");
			scanf ("%d", & num);
			R=num%2;
			R1=num%3; 
			if (R==0) {
				if (R1==0){
					printf ("Es multiplo de 2 y de 3");
					break;
				}
				else {
					printf ("Es multiplo de 2");
					break;
				}
			};
			if (R1==0){
				printf ("Es multiplo de 3");
				break;
			}
			else {
				printf ("No es multiplo ni de 2 ni de 3");
			}
				break;
			case 4:
				printf ("Ingrese el numero a");
				scanf ("%d", & a);
				printf ("Ingrese el numero b");
				scanf ("%d", & b);
				printf ("Ingrese el numero c");
				scanf ("%d", & c);
				if (a==b){
					if (a==c){
						printf ("Son todos iguales");
						break;
					}
					if (a<c){
						printf("El C es el mas grande");
						break; 
					}
					else {
						printf ("El a y el b son los mas grandes");
						break;
					}
				}
				else {
					if (a<b){
						if (b==c){
							printf ("B y C son los mas grandes");
							break;
						}
						else {
							if (b>c){
								printf ("El B es el mas grande");
								break;
							}
							else {
								printf ("El C es el mas grande");
								break;
							}
						}
					}
					else {
						if (c==a){
							printf ("El A y el C son los mas grandes");
							break;
						}
						else {
							if (a<c){
								printf ("El A es el mas grande");
								break;
							}
							else {
								printf("El C es el mas grande");
								break;
							}
						}
					}
				}
				break;
	}
	
}
