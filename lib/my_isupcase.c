/*
** EPITECH PROJECT, 2019
** my_isupcase
** File description:
** is uper case character
*/

int my_isupcase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return (1);
    } else {
        return (0);
    }
}