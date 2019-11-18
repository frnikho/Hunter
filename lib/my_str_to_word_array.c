/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** cat two string together
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_isalpha(char c);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
int my_put_nbr(int nb);

char *my_str_to_word_array_check(char const *str, int start_i, int end_i)
{
    char *result = malloc(end_i - start_i);
    int array_index = 0;

    for (int i = start_i; i < end_i; i++) {
        if (my_isalpha(str[i])) {
            result[array_index]=str[i];
            array_index++;
        }
    }

    return result;
}

int my_str_to_word_array_count_size(char const *array)
{
    int index = 0;

    for (int i = 0; array[i] != 0; i++) {
        index++;
    }
    return index;
}

char **my_str_to_word_array(char const *str)
{
    int str_length = my_str_to_word_array_count_size(str);
    char **array = malloc(str_length*2);
    int index = 0;
    int array_index = 0;

    for (int i = 0; i <= str_length; i++) {
        if (i != 0 && i == str_length) {
            array[array_index]=my_str_to_word_array_check(str, index, i);
            index=i;
            array_index++; continue;
        }
        if (!my_isalpha(str[i]) && !my_isalpha(str[i+1])) {
            index++; continue;
        }
        if (!my_isalpha(str[i])){
            array[array_index]=my_str_to_word_array_check(str, index, i);
            index=i;
            array_index++;
        }
    }
    return (array);
}