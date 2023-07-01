#include <stdio.h>
#include <string.h>

struct jugador {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    struct jugador jugadores[5];

    for (int i = 0; i < 5; i++) {
        printf("Introduce el nombre del jugador %d\n", i + 1);
        fgets(jugadores[i].nombre, 50, stdin);
        jugadores[i].nombre[strcspn(jugadores[i].nombre, "\n")] = '\0';  // Eliminar el salto de línea

        printf("Introduce la edad del jugador %d\n", i + 1);
        scanf("%d", &jugadores[i].edad);

        printf("Introduce la altura del jugador %d\n", i + 1);
        scanf("%f", &jugadores[i].altura);

        fflush(stdin);
    }

    int opcion = -1;
    while (opcion != 0) {
        printf("Introduce la opción que deseas realizar:\n");
        printf("1- Listar jugadores\n");
        printf("2- Buscar jugador por nombre\n");
        printf("3- Jugador más alto\n");
        printf("0- Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Lista de jugadores:\n");
                for (int i = 0; i < 5; i++) {
                    printf("Nombre: %s\n", jugadores[i].nombre);
                    printf("Altura: %.2f\n", jugadores[i].altura);
                    printf("\n");
                }
                break;
            case 2: {
                char nombreBusqueda[50];
                printf("Introduce el nombre del jugador a buscar:\n");
                getchar(); // Consumir el salto de línea anterior
                fgets(nombreBusqueda, 50, stdin);
                nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';  // Eliminar el salto de línea

                int encontrado = 0;
                for (int i = 0; i < 5; i++) {
                    if (strcmp(jugadores[i].nombre, nombreBusqueda) == 0) {
                        printf("Jugador encontrado:\n");
                        printf("Nombre: %s\n", jugadores[i].nombre);
                        printf("Altura: %.2f\n", jugadores[i].altura);
                        printf("Edad: %d\n", jugadores[i].edad);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Jugador no encontrado.\n");
                }
                break;
            }
            case 3: {
                float mayorAltura = jugadores[0].altura;
                char nombreMayorAltura[50];
                int edadMayorAltura = jugadores[0].edad;
                strcpy(nombreMayorAltura, jugadores[0].nombre);

                for (int i = 1; i < 5; i++) {
                    if (jugadores[i].altura > mayorAltura) {
                        strcpy(nombreMayorAltura, jugadores[i].nombre);
                        edadMayorAltura = jugadores[i].edad;
                        mayorAltura = jugadores[i].altura;
                    }
                }

                printf("El nombre del jugador de mayor altura es %s y su edad es %d\n", nombreMayorAltura, edadMayorAltura);
                break;
            }
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción incorrecta. Por favor, elige una opción válida.\n");
                break;
        }
    }

    
}
