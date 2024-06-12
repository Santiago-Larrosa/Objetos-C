#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PERSONAS 50
#define MAX_CANCIONES 100
#define MAX_NOMBRE 100
#define MAX_DIRECCION 150

typedef struct {
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
    char telefono[15];
    int edad;
} Persona;

typedef struct {
    char nombre[MAX_NOMBRE];
    char archivo[150];
    int tamano;
} Cancion;

Persona personas[MAX_PERSONAS];
Cancion canciones[MAX_CANCIONES];
int total_personas = 0;
int total_canciones = 0;

void ingresar_personas();
void mostrar_nombres();
void mostrar_personas_por_edad(int edad);
void mostrar_personas_por_inicial(char inicial);
void gestionar_personas();

void ingresar_canciones();
void mostrar_canciones();
void buscar_cancion_parcial(char *parte_nombre);
void borrar_cancion(int index);
void modificar_cancion(int index);
void ordenar_canciones();
void gestionar_canciones();

void bubble_sort_reales(float arr[], int n);
void ordenar_array(int arr[], int n);

int main() {
    int opcion;
    while (1) {
        printf("Menu principal:\n");
        printf("1. Gestionar personas\n");
        printf("2. Gestionar canciones\n");
        printf("3. Ordenar 5 numeros reales\n");
        printf("4. Ordenar 7 numeros enteros\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                gestionar_personas();
                break;
            case 2:
                gestionar_canciones();
                break;
            case 3: {
                float numeros[5];
                printf("Ingrese 5 numeros reales:\n");
                for (int i = 0; i < 5; i++) {
                    scanf("%f", &numeros[i]);
                }
                bubble_sort_reales(numeros, 5);
                printf("Numeros ordenados:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%f ", numeros[i]);
                }
                printf("\n");
                break;
            }
            case 4: {
                int numeros[7];
                printf("Ingrese 7 numeros enteros:\n");
                for (int i = 0; i < 7; i++) {
                    scanf("%d", &numeros[i]);
                }
                ordenar_array(numeros, 7);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Opcion invalida.\n");
        }
    }
    return 0;
}

void ingresar_personas() {
    while (total_personas < MAX_PERSONAS) {
        printf("Ingrese nombre (o presione Enter para terminar): ");
        getchar();  // Limpiar buffer
        fgets(personas[total_personas].nombre, MAX_NOMBRE, stdin);
        if (personas[total_personas].nombre[0] == '\n') break;
        strtok(personas[total_personas].nombre, "\n");

        printf("Ingrese direccion: ");
        fgets(personas[total_personas].direccion, MAX_DIRECCION, stdin);
        strtok(personas[total_personas].direccion, "\n");

        printf("Ingrese telefono: ");
        fgets(personas[total_personas].telefono, 15, stdin);
        strtok(personas[total_personas].telefono, "\n");

        printf("Ingrese edad: ");
        scanf("%d", &personas[total_personas].edad);

        total_personas++;
    }
}

void mostrar_nombres() {
    for (int i = 0; i < total_personas; i++) {
        printf("%s\n", personas[i].nombre);
    }
}

void mostrar_personas_por_edad(int edad) {
    for (int i = 0; i < total_personas; i++) {
        if (personas[i].edad == edad) {
            printf("%s\n", personas[i].nombre);
        }
    }
}

void mostrar_personas_por_inicial(char inicial) {
    for (int i = 0; i < total_personas; i++) {
        if (personas[i].nombre[0] == inicial) {
            printf("%s\n", personas[i].nombre);
        }
    }
}

void gestionar_personas() {
    int opcion;
    while (1) {
        printf("Menu de gestion de personas:\n");
        printf("1. Ingresar personas\n");
        printf("2. Mostrar lista de nombres\n");
        printf("3. Mostrar personas por edad\n");
        printf("4. Mostrar personas por inicial\n");
        printf("5. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresar_personas();
                break;
            case 2:
                mostrar_nombres();
                break;
            case 3: {
                int edad;
                printf("Ingrese la edad: ");
                scanf("%d", &edad);
                mostrar_personas_por_edad(edad);
                break;
            }
            case 4: {
                char inicial;
                printf("Ingrese la inicial: ");
                scanf(" %c", &inicial);
                mostrar_personas_por_inicial(inicial);
                break;
            }
            case 5:
                return;
            default:
                printf("Opcion invalida.\n");
        }
    }
}

void ingresar_canciones() {
    while (total_canciones < MAX_CANCIONES) {
        printf("Ingrese nombre de la cancion (o presione Enter para terminar): ");
        getchar();  // Limpiar buffer
        fgets(canciones[total_canciones].nombre, MAX_NOMBRE, stdin);
        if (canciones[total_canciones].nombre[0] == '\n') break;
        strtok(canciones[total_canciones].nombre, "\n");

        printf("Ingrese nombre del archivo: ");
        fgets(canciones[total_canciones].archivo, 150, stdin);
        strtok(canciones[total_canciones].archivo, "\n");
        if (strlen(canciones[total_canciones].archivo) == 0) {
            printf("Nombre de archivo invalido.\n");
            continue;
        }

        printf("Ingrese tamano del archivo: ");
        scanf("%d", &canciones[total_canciones].tamano);
        if (canciones[total_canciones].tamano < 0) {
            printf("Tamano de archivo invalido.\n");
            continue;
        }

        total_canciones++;
    }
}

void mostrar_canciones() {
    for (int i = 0; i < total_canciones; i++) {
        printf("%s (%s, %d KB)\n", canciones[i].nombre, canciones[i].archivo, canciones[i].tamano);
    }
}

void buscar_cancion_parcial(char *parte_nombre) {
    for (int i = 0; i < total_canciones; i++) {
        if (strstr(canciones[i].nombre, parte_nombre) != NULL) {
            printf("%s (%s, %d KB)\n", canciones[i].nombre, canciones[i].archivo, canciones[i].tamano);
        }
    }
}

void borrar_cancion(int index) {
    if (index < 0 || index >= total_canciones) {
        printf("Indice invalido.\n");
        return;
    }
    for (int i = index; i < total_canciones - 1; i++) {
        canciones[i] = canciones[i + 1];
    }
    total_canciones--;
}

void modificar_cancion(int index) {
    if (index < 0 || index >= total_canciones) {
        printf("Indice invalido.\n");
        return;
    }
    Cancion *c = &canciones[index];

    printf("Modificar nombre (%s): ", c->nombre);
    getchar();  // Limpiar buffer
    char nuevo_nombre[MAX_NOMBRE];
    fgets(nuevo_nombre, MAX_NOMBRE, stdin);
    strtok(nuevo_nombre, "\n");
    if (nuevo_nombre[0] != '\0') {
        strcpy(c->nombre, nuevo_nombre);
    }

    printf("Modificar archivo (%s): ", c->archivo);
    char nuevo_archivo[150];
    fgets(nuevo_archivo, 150, stdin);
    strtok(nuevo_archivo, "\n");
    if (nuevo_archivo[0] != '\0') {
        strcpy(c->archivo, nuevo_archivo);
    }

    printf("Modificar tamano (%d): ", c->tamano);
    int nuevo_tamano;
    scanf("%d", &nuevo_tamano);
    if (nuevo_tamano >= 0) {
        c->tamano = nuevo_tamano;
    }
}

void ordenar_canciones() {
    for (int i = 0; i < total_canciones - 1; i++) {
        for (int j = 0; j < total_canciones - i - 1; j++) {
            if (strcmp(canciones[j].nombre, canciones[j + 1].nombre) > 0) {
                Cancion temp = canciones[j];
                canciones[j] = canciones[j + 1];
                canciones[j + 1] = temp;
            }
        }
    }
}

void gestionar_canciones() {
    int opcion;
    while (1) {
               printf("Menu de gestion de canciones:\n");
        printf("1. Ingresar canciones\n");
        printf("2. Mostrar todas las canciones\n");
        printf("3. Buscar cancion por parte del nombre\n");
        printf("4. Borrar una cancion\n");
        printf("5. Modificar una cancion\n");
        printf("6. Ordenar canciones por nombre\n");
        printf("7. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresar_canciones();
                break;
            case 2:
                mostrar_canciones();
                break;
            case 3: {
                char parte_nombre[MAX_NOMBRE];
                printf("Ingrese parte del nombre de la cancion: ");
                getchar();  // Limpiar buffer
                fgets(parte_nombre, MAX_NOMBRE, stdin);
                strtok(parte_nombre, "\n");
                buscar_cancion_parcial(parte_nombre);
                break;
            }
            case 4: {
                int index;
                printf("Ingrese el indice de la cancion a borrar: ");
                scanf("%d", &index);
                borrar_cancion(index);
                break;
            }
            case 5: {
                int index;
                printf("Ingrese el indice de la cancion a modificar: ");
                scanf("%d", &index);
                modificar_cancion(index);
                break;
            }
            case 6:
                ordenar_canciones();
                break;
            case 7:
                return;
            default:
                printf("Opcion invalida.\n");
        }
    }
}

void bubble_sort_reales(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ordenar_array(int arr[], int n) {
    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble Sort
    printf("Ordenando con Bubble Sort...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Paso %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}


