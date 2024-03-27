#include <stdio.h>
int main () {
    int can_alum=0,pago_final=0, pago_alum=0;
    printf ("ingrese cantidad de alumnos");
    scanf ("%d", & can_alum);
    if (can_alum >= 100) {
        pago_final = can_alum*400;
        pago_alum=400;
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
}