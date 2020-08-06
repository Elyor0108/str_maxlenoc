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

char** permutationarray(char* word) {
    //num is # of permutations's possible for char* word        
    int num = permutation(word), len = strlen(word); 
    char buffer[50]; char* temp;
    char** array;
    array = malloc(sizeof(char) * len * num + 1);
    
    int index = 0, index1 = 0, index2 = 1, index3 = 0;

    while (index < len) {
        for ( ; index1 < index2; index1++) {
            buffer[index1] = word[index3];
            index3++;
        }
        buffer[index1] = '\0';
        temp = strdup(&buffer[0]);
        array[index] = malloc(sizeof(char) * strlen(temp) + 1);
        strcpy(array[index], temp);
        free(temp);
        index++;
        index2++;
    }

    for (index = 0; index < num; index++) {
        if (array[index] == NULL) 
            break;
        printf("%s\n", array[index]);
    }

    return array;
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
    
    printf("%d\n", permutation(cool->array[2]));
    char **answer = permutationarray(cool->array[2]);

    for (index = 0; index < cool->size; index++) {
        free(cool->array[index]);
    }

    free(answer);
    free(cool->array);
    free(cool);
}