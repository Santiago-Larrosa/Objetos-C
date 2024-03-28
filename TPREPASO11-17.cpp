    #include <stdio.h>
    int main () {
    int a=0,b=0,c=0,d=0,op=0,e=0,f=0,g=0;
    float a2,b2,c2,d2,e2,f2,g2;
    printf ("Ingrese el numero de el ejercicio (11,12,13,14,15,16,17)");
    scanf ("%d",& op);
    switch (op){
        case 11:
                printf("Ingrese la calificación del primer parcial: ");
                scanf("%f", &a2);

                printf("Ingrese la calificación del segundo parcial: ");
                scanf("%f", &b2);

                printf("Ingrese la calificación del tercer parcial: ");
                scanf("%f", &c2);

            
                printf("Ingrese la calificación del examen final: ");
                scanf("%f", &d2);

                
                printf("Ingrese la calificación del trabajo final: ");
                scanf("%f", &e2);

            
                f2 = (a2 + b2 + c2) / 3.0;

                    g2 = 0.55 * f2 + 0.30 * d2 + 0.15 * e2;

                    printf("La calificación final en la materia de Algoritmos es: %f\n", g2);
        break;
        case 12:
                printf ("Ingrese su sueldo");
                scanf ("%d", & a);
                b=a;
                for (d=0;d<3;d++){    
                b=b+((b*10)/100);}
                c=b;
                printf ("Ganancia de comiciones %d\n", c-a);
                printf ("El sueldo final %d", c);
        break;
        case 13:
                printf ("Ingrese cuanto pago");
                scanf ("%d",& a);
                b=a-((a*15)/100);
                printf ("A pagar: %d ", b);
        break;
        case 14:
                printf ("Ingrese un numero");
                scanf ("%d",& a);
                if (a<0){
                    b=a*-1;
                }
                else {
                    b=a;
                }
                printf ("El valor absoluto es %d",b);
        break;
        case 15:
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
                }while(1>0);
        break;
        case 16:
                printf ("Ingrese la cantidad de pesos argentinos");
                scanf ("%d",& a);
                printf ("Convercion a dolar actual");
                scanf ("%d",& b);
                printf ("Su cantidad de dolares es de: %d",(a/b));
        break;
        case 17:
                printf ("Ingrese su genero: (Hombre=1; Mujer=2)");
                scanf ("%d",& a);
                printf ("Ingrese su peso en kg");
                scanf ("%d",& b);
                printf ("Ingrese su edad actual");
                scanf ("%d",& c);
                if (a==1){
                    d=((210-(0.5*c))-b*0.01)+4;
                }
                else {
                d=((210-(0.5*c))-b*0.01);
                }
                printf ("Su FCmax es de: %d",d);
        break;
  
    
    }}
