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

    
}
