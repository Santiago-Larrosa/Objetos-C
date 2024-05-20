#include <stdio.h>

void calcularMediaYMostrarMayores(double numeros[], int tamanio) {
    double suma = 0.0;
    for (int i = 0; i < tamanio; i++) {
        suma += numeros[i];
    }
    double media = suma / tamanio;
    printf("La media es: %.2f\n", media);
    printf("Números por encima de la media: ");
    for (int i = 0; i < tamanio; i++) {
        if (numeros[i] > media) {
            printf("%.2f ", numeros[i]);
        }
    }
    printf("\n");
}

void encontrarMayor(int numeros[], int tamanio) {
    int mayor = numeros[0];
    for (int i = 1; i < tamanio; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }
    printf("El número mayor es: %d\n", mayor);
}

void diferenciaVectores2D(double v1[], double v2[]) {
    double diferencia[2];
    for (int i = 0; i < 2; i++) {
        diferencia[i] = v1[i] - v2[i];
    }
    printf("La diferencia de los vectores es: (%.2f, %.2f)\n", diferencia[0], diferencia[1]);
}

double productoEscalar3D(double v1[], double v2[]) {
    double productoEscalar = 0;
    for (int i = 0; i < 3; i++) {
        productoEscalar += v1[i] * v2[i];
    }
    return productoEscalar;
}

void productoVectorial3D(double v1[], double v2[], double resultado[]) {
    resultado[0] = v1[1] * v2[2] - v1[2] * v2[1];
    resultado[1] = v1[2] * v2[0] - v1[0] * v2[2];
    resultado[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

int sonLinealmenteDependientes2D(double v1[], double v2[]) {
    double proporciones[2];
    for (int i = 0; i < 2; i++) {
        if (v2[i] != 0) {
            proporciones[i] = v1[i] / v2[i];
        } else if (v1[i] == 0) {
            proporciones[i] = 1; // Caso especial cuando ambos son cero
        } else {
            return 0; // Si uno es cero y el otro no, no son proporcionales
        }
    }
    return (proporciones[0] == proporciones[1]);
}

int main() {
    int opcion;
    
    do {
        printf("Seleccione una opción:\n");
        printf("1. Calcular media y mostrar números por encima de la media\n");
        printf("2. Calcular y mostrar el número mayor\n");
        printf("3. Calcular la diferencia de dos vectores en el plano\n");
        printf("4. Calcular el producto escalar de dos vectores en el espacio\n");
        printf("5. Calcular el producto vectorial de dos vectores en el espacio\n");
        printf("6. Verificar si dos vectores en el plano son linealmente dependientes\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                double numeros[10];
                printf("Ingrese 10 números reales:\n");
                for (int i = 0; i < 10; i++) {
                    scanf("%lf", &numeros[i]);
                }
                calcularMediaYMostrarMayores(numeros, 10);
                break;
            }
            case 2: {
                int numeros[10];
                printf("Ingrese 10 números enteros:\n");
                for (int i = 0; i < 10; i++) {
                    scanf("%d", &numeros[i]);
                }
                encontrarMayor(numeros, 10);
                break;
            }
            case 3: {
                double v1[2], v2[2];
                printf("Ingrese las coordenadas del primer vector (x1 y1):\n");
                scanf("%lf %lf", &v1[0], &v1[1]);
                printf("Ingrese las coordenadas del segundo vector (x2 y2):\n");
                scanf("%lf %lf", &v2[0], &v2[1]);
                diferenciaVectores2D(v1, v2);
                break;
            }
            case 4: {
                double v1[3], v2[3];
                printf("Ingrese las coordenadas del primer vector (x1 y1 z1):\n");
                scanf("%lf %lf %lf", &v1[0], &v1[1], &v1[2]);
                printf("Ingrese las coordenadas del segundo vector (x2 y2 z2):\n");
                scanf("%lf %lf %lf", &v2[0], &v2[1], &v2[2]);
                double productoEscalar = productoEscalar3D(v1, v2);
                printf("El producto escalar de los vectores es: %.2f\n", productoEscalar);
                break;
            }
            case 5: {
                double v1[3], v2[3], resultado[3];
                printf("Ingrese las coordenadas del primer vector (x1 y1 z1):\n");
                scanf("%lf %lf %lf", &v1[0], &v1[1], &v1[2]);
                printf("Ingrese las coordenadas del segundo vector (x2 y2 z2):\n");
                scanf("%lf %lf %lf", &v2[0], &v2[1], &v2[2]);
                productoVectorial3D(v1, v2, resultado);
                printf("El producto vectorial de los vectores es: (%.2f, %.2f, %.2f)\n", resultado[0], resultado[1], resultado[2]);
                break;
            }
            case 6: {
                double v1[2], v2[2];
                printf("Ingrese las coordenadas del primer vector (x1 y1):\n");
                scanf("%lf %lf", &v1[0], &v1[1]);
                printf("Ingrese las coordenadas del segundo vector (x2 y2):\n");
                scanf("%lf %lf", &v2[0], &v2[1]);
                if (sonLinealmenteDependientes2D(v1, v2)) {
                    printf("Los vectores son linealmente dependientes.\n");
                } else {
                    printf("Los vectores no son linealmente dependientes.\n");
                }
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
