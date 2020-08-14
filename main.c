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
    // string array arr are the "given" strings
    char* arr[3] = {"xoxAoxo", "xoxAox", "oxAox"};
    char* temp;

    // struct string_array cool is the given struct
    string_array* cool;
    cool = malloc(sizeof(string_array));
    cool->array = malloc(sizeof(arr));
    cool->size = 3;
    // this for loop writes the strings from "arr" to "cool"
    for (index = 0; index < cool->size; index++) {
        temp = strdup(arr[index]);
        cool->array[index] = malloc(sizeof(char) * strlen(temp) + 1 );
        strcpy(cool->array[index], temp);
        free(temp);
    }

    temp = str_maxlenoc(cool, cool->size);

    printf("answer: %s\n", temp); 
    free(temp);

    for (index = 0; index < cool->size; index++) {
        free(cool->array[index]);
    }

    free(cool->array);
    free(cool);
}