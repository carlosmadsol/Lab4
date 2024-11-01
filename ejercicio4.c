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

int main() {
    int size = 5;  // Define un tamaño para la matriz
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
    }

    // Rellenar la matriz con valores aleatorios para ejemplo como en el lab 3
    srand(time(NULL));
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
