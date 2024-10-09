#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};

// Función para agregar un nuevo estudiante
void agregarEstudiante(struct Estudiante *estudiantes, int *cantidad) {
    printf("Agregar nuevo estudiante:\n");
    printf("Nombre: ");
    scanf("%s", estudiantes[*cantidad].nombre);
    printf("Edad: ");
    scanf("%d", &estudiantes[*cantidad].edad);
    printf("Calificación: ");
    scanf("%f", &estudiantes[*cantidad].calificacion);
    (*cantidad)++;
    printf("Estudiante agregado exitosamente.\n");
}

// Función para mostrar todos los estudiantes registrados
void mostrarEstudiantes(struct Estudiante *estudiantes, int cantidad) {
	int i;
    printf("\nLista de estudiantes registrados:\n");
    for (i = 0; i < cantidad; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Calificación: %.2f\n", estudiantes[i].calificacion);
    }
}

// Función para actualizar la calificación de un estudiante
void actualizarCalificacion(struct Estudiante *estudiantes, int cantidad) {
	int i;
    char nombre[50];
    printf("Actualizar calificación de un estudiante\n");
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombre);

    for (i = 0; i < cantidad; i++) {
        if (strcmp(estudiantes[i].nombre, nombre) == 0) {
            printf("Estudiante encontrado.\n");
            printf("Calificación actual: %.2f\n", estudiantes[i].calificacion);
            printf("Nueva calificación: ");
            scanf("%f", &estudiantes[i].calificacion);
            printf("Calificación actualizada exitosamente.\n");
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

// Función para calcular el promedio de calificaciones
void calcularPromedio(struct Estudiante *estudiantes, int cantidad) {
	int i;
    float suma = 0;
    for (i = 0; i < cantidad; i++) {
        suma += estudiantes[i].calificacion;
    }
    float promedio = suma / cantidad;
    printf("\nEl promedio de las calificaciones es: %.2f\n", promedio);
}

void ordenarEstudiantesPorCalificacion(struct Estudiante *estudiantes, int cantidad) {
    int i, j;
	struct Estudiante temp;
    for (i = 0; i < cantidad - 1; i++) {
        for (j = i + 1; j < cantidad; j++) {
            if (estudiantes[i].calificacion < estudiantes[j].calificacion) {
                temp = estudiantes[i];
                estudiantes[i] = estudiantes[j];
                estudiantes[j] = temp;
            }
        }
    }
    printf("\nEstudiantes ordenados por calificación:\n");
    mostrarEstudiantes(estudiantes, cantidad);
}


int main() {
    struct Estudiante estudiantes[100];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Agregar nuevo estudiante\n");
        printf("2. Mostrar todos los estudiantes\n");
        printf("3. Actualizar calificación de un estudiante\n");
        printf("4. Calcular promedio de calificaciones\n");
        printf("5. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                actualizarCalificacion(estudiantes, cantidad);
                break;
            case 4:
                calcularPromedio(estudiantes, cantidad);
                break;
            case 5:
                ordenarEstudiantesPorCalificacion(estudiantes,cantidad);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}
