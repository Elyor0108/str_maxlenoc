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
    char* arr[3] = {"ab", "ab", "cab"};
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

    // the struct "structarray" stores multiple string arrays. Each string array within "structarray" contains the different possible string combinations for each given string.
    // string_array* structarray[cool->size];

    // // structarray[0] contains [one, on, o, ne, n, e] and so forth
    // for (index = 0; index < cool->size; index++) {
    //     structarray[index] = testing(cool->array[index]);
    //     printstringarray(structarray[index], permutation(cool->array[index]));
    //     free(structarray[index]);
    // }

    str_maxlenoc(cool, cool->size);

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