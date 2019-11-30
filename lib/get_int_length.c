/*
** EPITECH PROJECT, 2019
** get_int_length.c
** File description:
** get int length
*/

int get_int_length(int nbr)
{
    int length = 1;

    for (; nbr > 0; nbr--) {
        length++;
        nbr /= 10;
    }
    return (length);
}
