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

// this function counts the number of possible string combinations. If char* word = "one", permutation would return 6. 
int permutation(char* word) {

    int count = 0;
    int len = strlen(word);

    while (len > 0) {
        count = len + count;
        len--;
    }
    return count; 
} 

// this function returns a string array of possible combinations of a word. For instance, if char* word = "one", this 
// function will return [one, on, o, ne, n, e] 
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
    
    // printf("[");
    for (index = 0; index < num; index++) {
        if (index != (num - 1) ) {
            // printf("%s, ", param_1->array[index]); 
            free(param_1->array[index]);
        }
        else if (index == (num - 1) ) {
            // printf("%s", param_1->array[index]);
            free(param_1->array[index]);
        }
    }
    // printf("]\n");
    free(param_1->array);
}

int countmatches(string_array* param_1[], int param_2) {
    
    int index, index2 = 0; 
    int stringarrayindex=1;
    int counter = 0;

    for (index = 0; index < param_1[0]->size; index++) {
        for (index2 = 0; index2 < param_1[stringarrayindex]->size; index2++) {
            int ret;
            ret = strcmp(param_1[0]->array[index], param_1[stringarrayindex]->array[index2]);    
            if (ret == 0) {
                // printf("param_1[0]->array[%d] = %s;     param_1[%d]->array[%d] = %s\n", 
                // index, param_1[0]->array[index], stringarrayindex, index2, param_1[stringarrayindex]->array[index2]);
                counter++;
                if (stringarrayindex + 1 < param_2) {
                    stringarrayindex++;
                    index2 = 0;   
                }
            }            
        }
        stringarrayindex = 1;
    }
    // printf("Possible matches: %d\n", counter);
    return counter;
}

void arraymatches(string_array* param_1[], int param_2, char param_3[][50]) {

    int index, index2 = 0, index3 = 0; 
    int stringarrayindex=1;

    for (index = 0; index < param_1[0]->size; index++) {
        for (index2 = 0; index2 < param_1[stringarrayindex]->size; index2++) {
            int ret;
            ret = strcmp(param_1[0]->array[index], param_1[stringarrayindex]->array[index2]);    
            if (ret == 0) {
                strcpy(param_3[index3], param_1[stringarrayindex]->array[index2]);
                index3++;
                if (stringarrayindex + 1 < param_2) {
                    stringarrayindex++;
                    index2 = 0;   
                }
            }       
        }
        stringarrayindex = 1;
    }
}

char* str_maxlenoc(string_array* param_1, int param_2) {
    
    int index;
    string_array* structarray[param_2];   
    for (index = 0; index < param_2; index++) {
        structarray[index] = testing(param_1->array[index]);
    }
    int arraysize = countmatches(structarray, param_2);
    char possiblematches[arraysize][50];
    arraymatches(structarray, param_2, possiblematches);

    for (index = 0; index < arraysize; index++) {
        printf("%s\n", possiblematches[index]);
    }

    int index2 = 0;
    int counter =0, ret;
    char* buffer;
    char* answer;

    while (index2 < arraysize) {
        buffer = strdup(possiblematches[index2]);

        for (index = 1; index < arraysize; index++) {
            ret = strcmp(buffer, possiblematches[index]);
            if (ret == 0)
                counter++;
        }
        // printf("Word: %s Counter: %d\n", buffer, counter);
        
        if (counter == (param_2 - 1)) {
            answer = strdup(buffer);
            free(buffer);
            break;
        }
        index2++;
        counter = 0;
        free(buffer);
    }
    for (index = 0; index < param_2; index++) {
        printstringarray(structarray[index], permutation(param_1->array[index]));
        free(structarray[index]);
    }
    return answer;
}


