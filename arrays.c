#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1

static void swap(int *e1, int *e2) {
    int aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}

void arrSort(int *arr, int arrLength) {
    if(!arr || arrLength <= 0) return;

    // Bubble sort
    int sweeps = 0;
    for(int i = 0; i < arrLength - 1; i++) {

        // TODO: optimize!

        for(int j = 0; j < arrLength - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }        

        sweeps++;
    }
    
    if(DEBUG) {
        printf("[DEBUG]: Required number of sweeps for bubble sort = %d\n", sweeps);
    }    
}

int* arrGenerateRandom(int size, int minValue, int maxValue) {
    if (size <= 0 || minValue > maxValue) {
        return NULL; // Invalid input
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) {
        return NULL; // Memory allocation failed
    }

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = minValue + rand() % (maxValue - minValue + 1);
    }

    return arr;
}

void arrPrintWithLimit(int *arr, int arrLength, int limit) {
    if (!arr || arrLength <= 0) {
        printf("Invalid array\n");
        return; // Invalid input, nothing to print
    }

    printf("array of %d = [", arrLength);

    if (arrLength <= limit || limit <= 0) { 
        // Print entire array if limit is too large or invalid
        for (int i = 0; i < arrLength; i++) {
            printf("%d", arr[i]);
            if (i < arrLength - 1) {
                printf(", ");
            }
        }
    } else {
        // Print first half
        int half = limit / 2;
        for (int i = 0; i < half; i++) {
            printf("%d, ", arr[i]);
        }

        // Indicate more elements exist
        printf("(...), ");

        // Print last half
        for (int i = arrLength - (limit - half); i < arrLength; i++) {
            printf("%d", arr[i]);
            if (i < arrLength - 1) {
                printf(", ");
            }
        }
    }

    printf("]\n");
}