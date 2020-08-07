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

int permutation(char* word) {

    int count = 0;
    int len = strlen(word);

    while (len > 0) {
        count = len + count;
        len--;
    }
    return count; 
} 

void testing (char* word) {
    int counter = 0, index = 0, index2 = 0;
    int length = strlen(word), length2 = strlen(word);
    int num = permutation(word);
    char buffer[50];
    int bufferindex = 0;
    
    char* array[num];
    int arrayindex = 0;

    for (index2 = 0; index2 < length2 ; index2++) {      
        while (word[counter] != '\0') {
            for (index = index2 ; index < length; index++) {
                // printf("%c", word[index]);
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
    
    for (index = 0; index < num; index++) {
        printf("%s\n", array[index]); 
        free(array[index]);
    }
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
