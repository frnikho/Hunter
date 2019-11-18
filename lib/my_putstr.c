/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** show string
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        my_putchar(str[index]);
        index++;
    }
}
