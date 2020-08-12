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

    string_array* structarray[cool->size];

    for (index = 0; index < cool->size; index++) {
        structarray[index] = testing(cool->array[index]);
        printstringarray(structarray[index], permutation(cool->array[index]));
        free(structarray[index]);
    }

    for (index = 0; index < cool->size; index++) {
        free(cool->array[index]);
    }
    
    free(cool->array);
    free(cool);



    // structarray[0] = testing("one");
    // structarray[1] = testing("two");
    // structarray[2] = testing("three");

    // printstringarray(structarray[0], permutation("one") );
    // printstringarray(structarray[1], permutation("two") );
    // printstringarray(structarray[2], permutation("three") );
    
    // free(structarray[0]);
    // free(structarray[1]);
    // free(structarray[2]);
    
}