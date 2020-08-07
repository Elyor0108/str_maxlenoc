/*
**
** QWASAR.IO -- str_maxlenoc
**
** @param {string_array*} param_1
** @param {int} param_2
**
** @return {char*}
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

int main() {
    
    int index;
    char* arr[3] = {"one", "two", "three"};
    char* temp;

    string_array* cool;
    cool = malloc(sizeof(string_array));
    cool->array = malloc(sizeof(arr));
    cool->size = 3;

    for (index = 0; index < cool->size; index++) {
        temp = strdup(arr[index]);
        cool->array[index] = malloc(sizeof(char) * strlen(temp) + 1 );
        strcpy(cool->array[index], temp);
        free(temp);
    }

    // char **answer = permutationarray(cool->array[2]);

    for (index = 0; index < cool->size; index++) {
        free(cool->array[index]);
    }
    free(cool->array);
    free(cool);

    testing("cool");
    
}