#include <stdio.h>

// Prototipos de las funciones utilizando las dimensiones fijas [5][3]
void ingresarNotas(float notas[5][3]);
void procesarEstudiantes(float notas[5][3], int *aprobados, int *reprobados);
void procesarAsignaturas(float notas[5][3]);
void buscarExtremos(float notas[5][3], float *max, float *min);

int main() {
    float notas[5][3]; // Matriz para 5 estudiantes y 3 asignaturas
    int totalAprobados = 0;
    int totalReprobados = 0;
    float notaMaxima = 0.0;
    float notaMinima = 10.0;

    // Llamadas a las funciones pasando las variables por referencia con el operador &
    ingresarNotas(notas);
    procesarEstudiantes(notas, &totalAprobados, &totalReprobados);
    procesarAsignaturas(notas);
    buscarExtremos(notas, &notaMaxima, &notaMinima);

    // Reporte final impreso desde el main
    printf("\n=========================================\n");
    printf("La nota maxima de todo el curso es: %.2f\n", notaMaxima);
    printf("La nota minima de todo el curso es: %.2f\n", notaMinima);
    printf("El total de aprobados fue: %d\n", totalAprobados);
    printf("El total de reprobados fue: %d\n", totalReprobados);
    printf("=========================================\n");

    return 0;
}

// 1. Función para ingresar y validar las notas del curso
void ingresarNotas(float notas[5][3]) {
    for (int i = 0; i < 5; i++) {
        printf("\nESTUDIANTE NO %d \n", i + 1);
        for (int j = 0; j < 3; j++) {
            do {
                printf("  Ingresa una nota de la asignatura %d: ", j + 1);
                scanf("%f", &notas[i][j]);

                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  ERROR: LA NOTA DEBE ESTAR EN EL RANGO DE 0 HASTA 10\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
}

// 2. Función para calcular el promedio de cada estudiante y contar aprobados/reprobados
// Usa punteros (*aprobados, *reprobados) para modificar directamente las variables de main
void procesarEstudiantes(float notas[5][3], int *aprobados, int *reprobados) {
    for (int i = 0; i < 5; i++) {
        float sumaEstudiante = 0;
        for (int j = 0; j < 3; j++) {
            sumaEstudiante += notas[i][j];
        }
        float promedio = sumaEstudiante / 3.0; // Dividido para las 3 asignaturas
        printf("\nEl promedio del estudiante %d es: %.2f", i + 1, promedio);

        if (promedio < 6) {
            printf(" -> Reprobado con %.2f\n", promedio);
            (*reprobados)++; // Modifica de forma directa totalReprobados en main
        } else {
            printf(" -> Aprobado con %.2f\n", promedio);
            (*aprobados)++;  // Modifica de forma directa totalAprobados en main
        }
    }
}

// 3. Función para obtener el promedio de cada una de las 3 asignaturas
void procesarAsignaturas(float notas[5][3]) {
    printf("\n-----------------------------------------");
    for (int j = 0; j < 3; j++) {
        float sumaAsignatura = 0;
        for (int i = 0; i < 5; i++) {
            sumaAsignatura += notas[i][j];
        }
        printf("\nEl promedio de la Asignatura %d es: %.2f", j + 1, sumaAsignatura / 5.0); // Dividido para 5 estudiantes
    }
    printf("\n-----------------------------------------\n");
}

// 4. Función para buscar la nota más alta y más baja de toda la matriz
// Modifica los valores en main usando los punteros (*max y *min)
void buscarExtremos(float notas[5][3], float *max, float *min) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (notas[i][j] > *max) {
                *max = notas[i][j]; // Guarda la nueva nota máxima
            }
            if (notas[i][j] < *min) {
                *min = notas[i][j]; // Guarda la nueva nota mínima
            }
        }
    }
}