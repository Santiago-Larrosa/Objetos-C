#include <stdio.h>
int main () {
	int a=0,b=1,c=2,d=0, op=0, e=0;
    float a2;
    float b2;
    float c2;
    float d2;
    float e2;
	printf ("Elija el ejercicio: (1,2,3,4,5,6,7,8,9,10)\n");
	scanf ("%d", & op);
	switch (op){
	
	case 1:
            do {
            d=a+b+c;
            if (d==87){
                break;
            }
            else {
                a++;
                b++;
                c++;
            }}
            while (1>0);
            printf ("%d,%d,%d",a,b,c);
            break;
	case 2:
            printf ("ingrese primer numero");
            scanf ("%f", & a2);
            printf ("ingrese el segundo numero");
            scanf ("%f", & b2);
            printf ("ingrese el tercer numero");
            scanf ("%f", & c2);
            d2=(a2+b2+c2)/3;
            printf ("promedio:%f",d2);
            break;
	case 3:
            printf ("Ingrese el numero");
            scanf ("%d",& a);
            if (a<=0){
            printf("mal");
            break;}
            if ((a%2)==0){
            printf ("El numero es par");
            }
            else {
            printf ("El numero es impar");
            }
            break;
	case 4:
            printf ("Ingrese la primer nota:");
            scanf ("%f",& a2);
            printf ("Ingrese la segunda nota:");
            scanf ("%f",& b2);
            printf ("Ingrese la tercer nota:");
            scanf ("%f",& c2);
            printf ("Ingrese la cuarta nota:");
            scanf ("%f",& e2);
            printf ("Ingrese la cuarta nota de las tareas:");
            scanf ("%f",& d2);
            if (((a2+b2+c2+d2+e2)/5)>=6){
            printf ("Aprobado!!");
            }
            else {
            printf ("Desaprobado");
            }
            break;
	case 5:
            printf ("Ingrese la nota:");
            scanf ("%d",& a);
            if (a>=6){
            if(a>=8){
            printf ("Felicitaciones!!");
            }
            else {
            printf ("Aprobado");
            }
            }
            else {
            if (a<=1){
            printf ("Debes esforzarte mas");
            }
            else {
            printf ("Desaprobado");
            }
            }
            break;
	case 6:
            printf ("Ingrese cuanto cobra:");
            scanf ("%d",& a);

            if (a<=202){
                b=0;
            }
            if (202<a && a<=607){
                b=5;
            }
            if (607<a && a<=1013){
                b=10;
            }
            if (1013<a && a<=1418){
                b=15;
            }
            if (1418<a){
                b=25;
            }
            c=(a*b)/100;
            printf ("Lo que pagas de impuestos es:%d",c);
            break;
	case 7:
            do{
            printf ("Ingrese la hora sin los minutos");
            scanf ("%d",& a);
            if (a>23){
            printf ("EScribi bien chistoso");
            break;
            }
            printf ("Ingrese los minutos");
            scanf ("%d",& b);
            if (b>59){
            printf ("Escribi bien chistoso");
            break;
            }
            if (a>12){
            printf ("%d:%d pm\n",a-12,b);
            }
            if (a<=12){
            printf ("%d:%d am\n",a,b);
            }
            }while (1>0);
            break;
	case 8:
            printf ("Ingrese su capital financiero");
            scanf ("%d",& a);
            printf ("ahorras %d",((a*2)/100));
            break;
	case 9:
            a=((50-20)*2)-50;
            printf ("sera dentro de %d años", a);
            break;
    case 10:
            printf ("Ingrese la cantidad de segundos");
            scanf ("%d",& a);
            b=a/3600;
            c=a%3600;
            d=a%60;
            printf("%d:%d:%d",b,c/60,d);
            break;
}
}
