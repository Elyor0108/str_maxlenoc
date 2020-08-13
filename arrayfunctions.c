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

char* str_maxlenoc(string_array* param_1, int param_2) {
    
    int index, index2 = 0, index3 = 0;
    char* buffer;
    char* buffer2;
    // char* answer;

    string_array* structarray[param_2];
    
    for (index = 0; index < param_2; index++) {
        structarray[index] = testing(param_1->array[index]);
    }

    for (index3 = 0 ; index3 < param_2 - 1; index3++) {

        while (index2 < structarray[index3+1]->size) {
            
            for (index = 0; index < permutation(param_1->array[0]); index++)  {

                buffer = strdup(structarray[index3]->array[index]);
                buffer2 = strdup(structarray[index3+1]->array[index2]);

                int ret = strcmp(buffer, buffer2);

                if(ret == 0) {

                    printf("string1: %s   string2: %s\n", buffer, buffer2);
                    printf("str1 is equal to str2\n");
                    printf("string1 location -> structarray[%d]->array[%d]\n", index3, index);
                    printf("string2 location -> structarray[%d]->array[%d]\n\n", index3+1, index2);
                }

                free(buffer);
                free(buffer2);     
            }
            index2++;
        }
    }


    for (index = 0; index < param_2; index++) {
        // structarray[index] = testing(param_1->array[index]);
    
        printstringarray(structarray[index], permutation(param_1->array[index]));
        free(structarray[index]);
    }

    return "works";
}
