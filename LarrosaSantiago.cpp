#include <stdio.h>
int main () {
	int a=0,op=0,b=0,c=0,d=0,i=0,e=0,f=0,g=0;
	float ff,aa,bb,cc,dd,ee,gg;
	printf ("Ingrese el ejercicio (1,2,3,4,5)");
	scanf ("%d",&op);
	switch (op){
		case 1:
			printf ("Ingrese hora de entrada (Horario militar)");
			scanf ("%d",&a);
			printf ("Ingrese hora de salida (Horario militar)");
			scanf ("%d",&b);
			d=a%100;
			//redondeo para abajo para que pague la hora completa
			a=a-d;
			d=b%100;
			b=b-d;
			if (b<a){
				//En caso de que empiece en un día y termine en el siguiente comprobando que el numero sea menor que el anterior
				c=(24-(a/100))+((b/100)+1);
				c=(c*250)+250;
				printf ("Debe pagar: %d",c);
			}
			else{
				c=(b/100)-(a/100);
				c=(c*250)+250;
				printf ("Debe pagar: %d",c);
			}
			break;
		case 2:
			printf ("Ingrese el primer numero");
			scanf ("%d",&a);
			printf ("Ingrese el segundo numero");
			scanf ("%d",&b);
		for (i=0;i<b;i++){
			//Sumo tantas veces el numero como me sea indicado haciendo un bucle for
			c=c+a;
		}
		printf ("Producto: %d",c);
			break;
		case 3:
			printf ("Ingrese la cantidad de kilometros recorridos");
			scanf ("%f",&aa);
			printf ("Ingrese el precio de combustible por litro");
			scanf ("%f",&bb);
			printf ("Ingrese la cantidad de horas que demoro el viaje sin minutos");
			scanf ("%d",&c);
			printf ("Ingrese los minutos");
			scanf ("%f",&dd);
			if (dd>59){
				// En caso de que los minutos superen la hora
				printf ("mal");
				break;
			}
			printf ("Ingrese la cantidad de combustible gastado");
			scanf ("%f",&ee);
			//Litros por kilometros
			ff=ee/aa;
			printf ("Kilometros recorridos %f\n",aa);
			printf ("precio del viaje %f\n",ee*bb);
			printf ("tiempo total de viaje %d : %f hs\n",c,dd);
			//Hago la cantidad de horas en un numero con decimal y no minutos
			gg=c+(dd/60);
			printf ("La velocidad promedio fue de %f km/h\n",aa/gg);
			//Calculo para 100km
			printf ("La cantidad de combustible utilizado cada 100km es de %f y el costo fue de %f\n",ff*100,(ff*bb)*100);
			//Calculo para 1km
			printf ("La cantidad de combustible utilizado cada 1km es de %f y el costo fue de %f\n",ff,ff*bb);
			
			break;
		case 4:
			printf ("Cuantas entradas quiere? (maximo 4)");
			scanf ("%d",&a);
			printf ("Ingrese el precio de la entrada");
			scanf ("%d",&b);
		//Compruebo que no supero las 4 entradas
			if (a>4){
				printf ("mal");
				break;
			}
			//hago un switch para distinguir la cantidad de entradas
			switch (a){
				case 1:
					printf ("el precio es de %d",b);
		
					break;
				case 2:
					c=(b*2)-((b*2)*0.1);
				    printf ("El precio es de %d",c);
					break;
				case 3: 
				c=(b*3)-((b*3)*0.15);
				    printf ("El precio es de %d",c);
					break;
			    case 4: 
			    c=(b*4)-((b*4)*0.20);
				    printf ("El precio es de %d",c);
					break;
			}
			break;
		case 5:
			printf ("Ingrese la cantidad de personas que van a comer?");
			scanf ("%d",&a);
			//Hago un grupo de IF para sdcar el precio correspondiente en relacion a la cantidad de comensales
			if (a<=200){
				printf("El coste es de : %d",a*6500);
			}
			else if (a>200 && a<=300){
				printf("El coste es de : %d",a*5500);
			}
			else if (a>300){
				printf("El coste es de : %d",a*4500);
			}
			break;
	}
}
