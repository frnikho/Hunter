/*
** EPITECH PROJECT, 2019
** my_isstrempty
** File description:
** return
*/

int my_isstrempty(char const *str)
{
    if (str[0] != 0) {
        return (0);
    } else {
        return (1);
    }
}