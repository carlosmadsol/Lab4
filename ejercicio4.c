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

void fillMatrix (int **matrix, int size){ //Este es el mismo codigo usado en el laboratorio 3 por lo que no me extendere en detalles
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2; 
        }
    }
}

// Esta funcion viene en el documento y muestra la matriz
void printMatrix (int **matrix, int size){
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size ; i++){
        for (int j = 0; j < size ; j++){
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}
// Esta funcion viene en el documento y libera espacio en la memoria
void freeMatrix (int **matrix, int size) {
    for (int i = 0; i < size ; i++){
        free (matrix [i]);
    }
    free(matrix);
}
// En los codigos pasados del ejercicio4 ya estaba esta funcion solo que en el main

int main() {
    int size;  // Define un tamaño para la matriz
    int **matrix = NULL;
    
    printf("Ingresa el tamaño de la matriz: ");
    scanf("%d", &size);
 
    allocateMatrix(&matrix, size); // Llamamos la funcion de allocateMatrix
    fillMatrix(matrix, size);
    printMatrix(matrix, size);

    int largestLine;
    findLargestLine(matrix, size, &largestLine);
    printf("La secuencia más larga de 1s consecutivos es: %d\n", largestLine);

    freeMatrix(matrix, size);

    return 0;

}
