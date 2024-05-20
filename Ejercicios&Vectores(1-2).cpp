#include <stdio.h>

double calcularMedia(int numeros[], int tamanio) {
    int suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += numeros[i];
    }
    return (double)suma / tamanio;
}

void invertirVector(int numeros[], int tamanio) {
    printf("Los números en orden inverso son: ");
    for (int i = tamanio - 1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

int diasDelMes(int mes) {
    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return diasPorMes[mes - 1];
}

int diaDelAno(int mes, int dia) {
    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int diaAno = 0;
    for (int i = 0; i < mes - 1; i++) {
        diaAno += diasPorMes[i];
    }
    diaAno += dia;
    return diaAno;
}

int diasRestantes(int mes, int dia) {
    int diaActual = diaDelAno(mes, dia);
    return 365 - diaActual;
}

int main() {
    int opcion;
    
    do {
        printf("Seleccione una opción:\n");
        printf("1. Calcular media aritmética de 4 números\n");
        printf("2. Mostrar 5 números en orden inverso\n");
        printf("3. Mostrar días de un mes\n");
        printf("4. Día del año para una fecha específica\n");
        printf("5. Días restantes hasta fin de año\n");
        printf("6. Mostrar 10 números en orden inverso usando for\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int numeros[4];
                printf("Ingrese 4 números:\n");
                for (int i = 0; i < 4; i++) {
                    scanf("%d", &numeros[i]);
                }
                double media = calcularMedia(numeros, 4);
                printf("La media aritmética es: %.2f\n", media);
                printf("Los números ingresados son: ");
                for (int i = 0; i < 4; i++) {
                    printf("%d ", numeros[i]);
                }
                printf("\n");
                break;
            }
            case 2: {
                int numeros[5];
                printf("Ingrese 5 números:\n");
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &numeros[i]);
                }
                invertirVector(numeros, 5);
                break;
            }
            case 3: {
                int mes;
                printf("Ingrese el número del mes (1=enero, 12=diciembre):\n");
                scanf("%d", &mes);
                printf("El mes %d tiene %d días.\n", mes, diasDelMes(mes));
                break;
            }
            case 4: {
                int mes, dia;
                printf("Ingrese el número del mes (1=enero, 12=diciembre):\n");
                scanf("%d", &mes);
                printf("Ingrese el día del mes:\n");
                scanf("%d", &dia);
                int diaAno = diaDelAno(mes, dia);
                printf("El %d de %d es el día número %d del año.\n", dia, mes, diaAno);
                break;
            }
            case 5: {
                int mes, dia;
                printf("Ingrese el número del mes (1=enero, 12=diciembre):\n");
                scanf("%d", &mes);
                printf("Ingrese el día del mes:\n");
                scanf("%d", &dia);
                int restantes = diasRestantes(mes, dia);
                printf("Quedan %d días hasta el final del año.\n", restantes);
                break;
            }
            case 6: {
                int numeros[10];
                printf("Ingrese 10 números:\n");
                for (int i = 0; i < 10; i++) {
                    scanf("%d", &numeros[i]);
                }
                printf("Los números en orden inverso son: ");
                for (int i = 9; i >= 0; i--) {
                    printf("%d ", numeros[i]);
                }
                printf("\n");
                break;
            }
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
