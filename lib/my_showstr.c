/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** my_showstr
*/

void my_putchar(char c);
int my_isalpha(char c);

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            continue;
        } else {
            return (1);
        }
    }
    return (0);
}