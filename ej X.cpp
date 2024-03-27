#include <stdio.h>
int main () {

    int can_alum=0,pago_final=0, pago_alum=0, eleccion=0, sueldo=0;
    int total_comiciones=0, sueldo_fin=0;
    float calificacion_parcial1, calificacion_parcial2, calificacion_parcial3;
    float calificacion_examen_final, calificacion_trabajo_final;
    float promedio_parciales, calificacion_final;
    int numero_inicial, numero_final;
    int km, k_E;
    printf ("Ingrese ejercicio (1,2,3,4,5)");
    scanf ("%d", & eleccion);
    switch (eleccion){
        case 1:
    printf ("ingrese cantidad de alumnos"); 
    scanf ("%d", & can_alum);
    if (can_alum >= 100) {
        pago_final = can_alum*500;
        pago_alum=500;
    }
    else if (can_alum >= 50 && can_alum <= 99) {
        pago_final = can_alum*400;
        pago_alum=400;
    }
    else if (can_alum >= 30 && can_alum <= 49) {
        pago_final = can_alum*300;
        pago_alum=300;
    }
    else if (can_alum < 30) {
        pago_final=6000;
        pago_alum=6000/can_alum;
    }
    printf ("pago final:%d pago alumno:%d",pago_final,pago_alum);
    break;
    case 2:
    printf ("Ingrese su sueldo");
    scanf ("%d", & sueldo);
    total_comiciones=((sueldo*30)/100);
    sueldo_fin=total_comiciones+sueldo;
    printf ("El sueldo final %d", sueldo_fin);
    break;
    case 3:
    printf("Ingrese la calificación del primer parcial: ");
    scanf("%f", &calificacion_parcial1);

    printf("Ingrese la calificación del segundo parcial: ");
    scanf("%f", &calificacion_parcial2);

    printf("Ingrese la calificación del tercer parcial: ");
    scanf("%f", &calificacion_parcial3);

   
    printf("Ingrese la calificación del examen final: ");
    scanf("%f", &calificacion_examen_final);

    
    printf("Ingrese la calificación del trabajo final: ");
    scanf("%f", &calificacion_trabajo_final);

   
    promedio_parciales = (calificacion_parcial1 + calificacion_parcial2 + calificacion_parcial3) / 3.0;

        calificacion_final = 0.55 * promedio_parciales + 0.30 * calificacion_examen_final + 0.15 * calificacion_trabajo_final;

        printf("La calificación final en la materia de Algoritmos es: %.2f\n", calificacion_final);

    break;
    case 4:
      
    printf("Ingrese el primer número: ");
    scanf("%d", &numero_inicial);

    printf("Ingrese el segundo número: ");
    scanf("%d", &numero_final);

   
    printf("Números pares entre %d y %d:\n", numero_inicial, numero_final);
    for (int i = numero_inicial; i <= numero_final; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    break;
    case 5:
    km=150-70;
    k_E=km/2+70;
    printf ("%d",k_E);
    break;
    }

}
