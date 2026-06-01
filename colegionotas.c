/*Integrantes: Jair Granizo y Martin Espinosa
Fecha: 31-5-2026
Descripcion: Una escuela desea implementar un programa en C que le permita
gestionar las calificaciones de un grupo de estudiantes en varias asignaturas.Además de gestionar
las calificaciones, el programa debe calcular y mostrar información relevante como el promedio
de calificaciones por estudiante y por asignatura, la calificación más alta y baja, y cuántos
estudiantes aprobaron cada asignatura.*/
#include <stdio.h>

void ingresarNotas(float notas[5][3]);
void procesarEstudiantes(float notas[5][3], int *aprobados, int *reprobados);
void procesarAsignaturas(float notas[5][3]);
void buscarExtremos(float notas[5][3], float *max, float *min);

int main (int argc, char *argv[]) {
    float notas[5][3]; 
    int totalAprobados = 0;
    int totalReprobados = 0;
    float notaMaxima = 0.0;
    float notaMinima = 10.0;
    return 0;

    ingresarNotas(notas);
    procesarEstudiantes(notas, &totalAprobados, &totalReprobados);
    procesarAsignaturas(notas);
    buscarExtremos(notas, &notaMaxima, &notaMinima);
    printf("\n=========================================\n");
    printf("La nota maxima de todo el curso es: %.2f\n", notaMaxima);
    printf("La nota minima de todo el curso es: %.2f\n", notaMinima);
    printf("El total de aprobados fue: %d\n", totalAprobados);
    printf("El total de reprobados fue: %d\n", totalReprobados);
    printf("=========================================\n");
}
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
void procesarEstudiantes(float notas[5][3], int *aprobados, int *reprobados) {
    for (int i = 0; i < 5; i++) {
        float sumaEstudiante = 0;
        for (int j = 0; j < 3; j++) {
            sumaEstudiante += notas[i][j];
        }
        float promedio = sumaEstudiante / 3.0;
        printf("\nEl promedio del estudiante %d es: %.2f", i + 1, promedio);

        if (promedio < 6) {
            printf(" -> Reprobado con %.2f\n", promedio);
            (*reprobados)++; 
        } else {
            printf(" -> Aprobado con %.2f\n", promedio);
            (*aprobados)++;  
        }
    }
}
void procesarAsignaturas(float notas[5][3]) {
    printf("\n-----------------------------------------");
    for (int j = 0; j < 3; j++) {
        float sumaAsignatura = 0;
        for (int i = 0; i < 5; i++) {
            sumaAsignatura += notas[i][j];
        }
        printf("\nEl promedio de la Asignatura %d es: %.2f", j + 1, sumaAsignatura / 5.0);
    }
    printf("\n-----------------------------------------\n");
}

void buscarExtremos(float notas[5][3], float *max, float *min) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (notas[i][j] > *max) {
                *max = notas[i][j];
            }
            if (notas[i][j] < *min) {
                *min = notas[i][j];
            }
        }
    }
}