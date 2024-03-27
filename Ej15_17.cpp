#include <stdio.h>
int main () {
int a=0,b=0,c=0,d=0;
do{

printf ("Total de estudiantes");
scanf ("%d",& a);
printf ("Total de hombres");
scanf ("%d",& b);
printf ("Total de mujeres");
scanf ("%d",& c);
if (b>a){
	printf ("Esta mal");
	break;
}
if (c>a){
	printf ("Esta mal");
	break;
}
if (c+b>a){
	printf ("Esta mal");
	break;
}
printf ("Porcentaje de hombres: %d",(b*100)/a);
printf ("Porcentaje de mujeres: %d",(c*100)/a);
break;
}while(1>0);}
