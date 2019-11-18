/*
** EPITECH PROJECT, 2019
** is_digits
** File description:
** return is a ditif
*/

int my_isnum(char c)
{
    if (c >= '0' && c <= '9') {
        return (1);
    } else {
        return (0);
    }
}