#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20000 // Cambia este valor según tu necesidad

double A[MAX][MAX], x[MAX], y[MAX];

int main() {
    printf("%d \n",MAX);
    srand(time(0));
    double time_spent = 0.0;

    /*double A[4][4]= {{4, 3, 5, 7},
            {6, 2, 1, 8},
            {3, 7, 9, 3},
            {9, 7, 13, 12}};
    double x[4] = {5, 2, 1, 6};*/

    //Agrega valores aleatorios a la matriz A
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            A[i][j] = rand() % 10+1;
        }
    }

    //Agrega valores aleatorios al vector x
    for (int i = 0; i < MAX; i++){
        x[i] = rand() % 10+1;
    }

    /* Primer par de bucles */
    clock_t begin = clock();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    clock_t end = clock();
    time_spent += (double)(end-begin)/CLOCKS_PER_SEC;
    printf("PRIEMER time is %f seconds", time_spent);

    time_spent = 0.0;
    /* Asigna y = 0 */
    for (int i = 0; i < MAX; i++) {
        //printf("%f ", y[i]);
        y[i] = 0;
    }

    /* Segundo par de bucles*/
    begin = clock();
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    end = clock();
    time_spent += (double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nSEGUNDO time is %f seconds", time_spent);

    //for (int i = 0; i < MAX; i++) {
        //printf("%f ", y[i]);
    //}

    /* El resto de tu código aquí */

    return 0;
}