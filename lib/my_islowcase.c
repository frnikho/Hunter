/*
** EPITECH PROJECT, 2019
** my_islowcase
** File description:
** return is lowcase character
*/

int my_islowcase(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    } else {
        return (0);
    }
}