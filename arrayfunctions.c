/*
** QWASAR PROJECT, 2020
** str_maxlenoc
** File description: This file contains the functions to manipulate arrays needed to
** solve the problem.
** 
** 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

int permutation(char* word) {

    int count = 0;
    int len = strlen(word);

    while (len > 0) {
        count = len + count;
        len--;
    }
    return count; 
} 

string_array* testing (char* word) {
    int counter = 0, index = 0, index2 = 0;
    int length = strlen(word), length2 = strlen(word);
    int num = permutation(word);
    char buffer[50];
    int bufferindex = 0;
    char* temp;
    char* array[num];
    int arrayindex = 0;
    
    for (index2 = 0; index2 < length2 ; index2++) {      
        while (word[counter] != '\0') {
            for (index = index2 ; index < length; index++) {
                buffer[bufferindex] = word[index];
                bufferindex++;
            }
            buffer[bufferindex] = '\0';
            array[arrayindex] = strdup(buffer);            
            bufferindex = 0;
            arrayindex++;
            counter++;
            length--;
        }
        counter = index2 + 1;
        length = length2;
    }
    string_array *cool = malloc(sizeof(string_array));
    cool -> array = malloc(sizeof (array));

    for (index = 0; index < num; index++) {
        temp = strdup(array[index]);
        cool->array[index] = malloc(sizeof(char) * strlen(temp) + 1);
        strcpy(cool->array[index], temp);
        free(temp);
        free(array[index]);
    }

    cool->size = num;
    return cool;    
}

void printstringarray(string_array* param_1, int num) {
    int index;
    
    printf("[");
    for (index = 0; index < num; index++) {
        if (index != (num - 1) ) {
            printf("%s, ", param_1->array[index]); 
            free(param_1->array[index]);
        }
        else if (index == (num - 1) ) {
            printf("%s", param_1->array[index]);
            free(param_1->array[index]);
        }
    }
    printf("]\n");
    free(param_1->array);
}

// char* str_maxlenoc(string_array* param_1, int param_2) {
    
//     int index;
//     int array[param_2];
//     char* answer;

//     for (index = 0; index < param_2; index++) {
//         array[index] = strlen(param_1->array[index]);
//     }

//     int key = largest(array, param_2);

//     for (index = 0; index < param_2; index++) {
//         if (array[index] == key) {
//             break;
//         }
//     }
//     int location = index;

//     answer = malloc(sizeof(char) * strlen(param_1->array[location]) + 1);
//     strcpy(answer, param_1->array[location]);
//     // printf("%s\n", answer);

//     return answer;
// }
