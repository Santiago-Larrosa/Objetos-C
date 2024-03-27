#include <stdio.h>
int main () {
int a=0,b=0,c=0,d=0;
printf ("Ingrese un numero");
scanf ("%d",& a);
if (a<0){
	b=a*-1;
}
else {
	b=a;
}
printf ("El valor absoluto es %d",b);}
