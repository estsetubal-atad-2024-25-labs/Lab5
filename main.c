#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "arrays.h"

#define TEST_SIZE 1000000

int main() {

    int *randArr = arrGenerateRandom(TEST_SIZE, -500000, 500000);
    arrPrintWithLimit(randArr, TEST_SIZE, 15);
    
    arrSort(randArr, TEST_SIZE);
    arrPrintWithLimit(randArr, TEST_SIZE, 15);

    free(randArr);

    return EXIT_SUCCESS;
}


