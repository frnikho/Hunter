/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** strdup function
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_isalpha(char c);

int my_strlastword_start_index(char const *str, int length)
{
    while (my_isalpha(str[length])) {
        length--;
    }
    return length+1;
}

int my_strlastword_end_index(char const *str, int length)
{
    for (int i = length; i != 0; i--) {
        if (my_isalpha(str[i])) {
            return i;
        } else {
            continue;
        }
    }
}

char *my_strlastword(char const *str)
{
    int length = my_strlen(str);
    char *lastword = malloc(length + sizeof(char));
    int end_index = my_strlastword_end_index(str, length);
    int start_index = my_strlastword_start_index(str, end_index);
    int char_index = 0;

    for (int i = start_index; i <= end_index; i++) {
        lastword[char_index] = str[i];
        char_index++;
    }
    return lastword;
}