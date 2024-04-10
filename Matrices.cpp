#include <stdio.h>

main ()
{
    
    int i, j,a=0,b=0;
    printf ("Este programa te pide una matriz de 3x3 \n \n");
    printf ("Ingrese el ancho de la matris");
    scanf ("%d", &b);
    printf ("Ingrese el largo de la matris");
    scanf ("%d", &a);
    int A [a][b];

	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			printf ("Ingresa el valor A[%d][%d]: ", i, j);
			scanf ("%d", &A[i][j]);
		}
	}
    
  
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{

			printf ("%d\t", A[i][j]);
		}
		printf ("\n");
	}
      
}
