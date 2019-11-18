/*
** EPITECH PROJECT, 2019
** my_isalpha
** File description:
** return character is alpha
*/

int my_isalpha(char c)
{
    if (c >= 65 && c<= 90) {
        return (1);
    } else if (c >= 97 && c <= 122) {
        return (1);
    } else {
        return (0);
    }
}