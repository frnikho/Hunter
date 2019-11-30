/*
** EPITECH PROJECT, 2019
** string_utils.c
** File description:
** string function
*/

#include <stdlib.h>
#include "my.h"

char *transform_str(int nbr)
{
    int length = get_int_length(nbr);
    int coef = my_compute_power_it(10, length-1);
    char *result = malloc(nbr * sizeof(char));
    int index = 0;
    for (int i = 0; i < length; i++) {
        nbr = nbr / coef;
        result[index]=nbr/(coef*10)+48;
        coef /= 10;
        index++;
    }
    my_putstr(result);

    return (result);
}