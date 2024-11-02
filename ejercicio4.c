#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función que encuentra la secuencia de 1s consecutivos más larga en una matriz y usamos el nombre dado por el documento
void findLargestLine(int **matrix, int size, int *result) {
    int contadorMax = 0, contador_act = 0;

    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {  // Aumenta el contador si encuentra un 1
                contador_act++;
            } else {  // Actualiza contadorMax si contador_act es mayor
                if (contador_act > contadorMax) {
                    contadorMax = contador_act;
                }
                contador_act = 0;  // Reinicia el contador actual
            }
        }
        // Al final de cada fila, verifica si la secuencia actual es la más larga
        if (contador_act > contadorMax) {
            contadorMax = contador_act;
        }
        contador_act = 0;  // Reinicia el contador para la siguiente fila
    }

    *result = contadorMax;  // Guarda el resultado en el puntero de 'result'
}

void allocateMatrix(int ***matrix, int size) { // Funcion que va a reservar la matriz en una memoria dinamica
    *matrix = (int **)malloc(size * sizeof(int *)); // Calculamos el size en filas de la matriz y lo asignamos a un bloque de puntero (int **) que van a redirigir a cada fila
    for (int i = 0; i < size; i++) { // Para guardar cada fila de la matriz
        (*matrix)[i] = (int *)malloc(size * sizeof(int *)); // Guardamos cada una de las filas en (int *) y su informacion para formar la matriz
    }
}

int main() {
    int size = 5;  // Define un tamaño para la matriz
    int **matrix;

    allocateMatrix(&matrix, size); // Llamamos la funcion de allocateMatrix
    
    srand(time(NULL)); // Rellenar la matriz con valores aleatorios para ejemplo como en el lab 3
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2;  // Rellenar con 0s y 1s
        }
    }

    int largestLine;
    findLargestLine(matrix, size, &largestLine);
    printf("La secuencia más larga de 1s consecutivos es: %d\n", largestLine);

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
