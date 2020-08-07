/*
** QWASAR PROJECT, 2020
** str_maxlenoc
** File description: prototypes
** 
** 
*/

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

// arrayfunctions.c
int permutation(char* word);
char** permutationarray(char* word);
string_array* testing (char* word); 
void printstringarray(string_array* param_1, int num);

