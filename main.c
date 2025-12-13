#include <stdio.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante estudiantes[3];
    struct Estudiante cargados[3];
    int i;
    float suma = 0;
    int mejorIndex = 0;
    char buffer[100];

    // Capturar datos
    for (i = 0; i < 3; i++) {
        printf("\nEstudiante %d\n", i + 1);

        printf("Nombre: ");
        while (getchar() != '\n'); 
        fgets(estudiantes[i].nombre, 50, stdin);

        printf("Edad: ");
        fgets(buffer, 100, stdin);
        sscanf(buffer, "%d", &estudiantes[i].edad);

        printf("Promedio: ");
        fgets(buffer, 100, stdin);
        sscanf(buffer, "%f", &estudiantes[i].promedio);
        
        suma += estudiantes[i].promedio;

        if (estudiantes[i].promedio > estudiantes[mejorIndex].promedio) {
            mejorIndex = i;
        }
    }

    // Guardar datos en archivo
    FILE *archivo = fopen("estudiantes.txt", "w");
    if (archivo != NULL) {
        for (i = 0; i < 3; i++) {
            fprintf(archivo, "%s %d %.2f\n",
                estudiantes[i].nombre,
                estudiantes[i].edad,
                estudiantes[i].promedio);
        }
        fclose(archivo);
    }

    // Cargar datos desde archivo
    archivo = fopen("estudiantes.txt", "r");
    if (archivo != NULL) {
        for (i = 0; i < 3; i++) {
            fgets(cargados[i].nombre, 50, archivo);
            fscanf(archivo, "%49s %d %f",
                &cargados[i].edad,
                &cargados[i].promedio);
        }
        fclose(archivo);
    }

    // Mostrar datos cargados
    printf("\n--- Datos desde archivo ---\n");
    for (i = 0; i < 3; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("Nombre: %s\n", cargados[i].nombre);
        printf("Edad: %d\n", cargados[i].edad);
        printf("Promedio: %.2f\n", cargados[i].promedio);
    }

    float promedioGrupo = suma / 3;

    printf("\n--- Resultados del grupo ---\n");
    printf("Promedio general del grupo: %.2f\n", promedioGrupo);

    printf("\nMejor estudiante:\n");
    printf("Nombre: %s", estudiantes[mejorIndex].nombre);
    printf("Edad: %d\n", estudiantes[mejorIndex].edad);
    printf("Promedio: %.2f\n", estudiantes[mejorIndex].promedio);

    return 0;
}
