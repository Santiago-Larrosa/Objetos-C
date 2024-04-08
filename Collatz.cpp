#include <stdio.h>
int main () {
	int a=0,b=1,c=2,d=0, op=0, e=0;
            printf ("Ingrese un numero");
            scanf ("%d",& a);	
            do {
            	if (a==1){
            		break;
				}
				else {
					
					if (a%2 != 0){
						a=(a*3)+1;
					}
					else {
						a=a/2;
					}
					printf ("%d \n",a);
				}
				
			}while(1>0);
}
