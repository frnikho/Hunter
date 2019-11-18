/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return
*/
int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            continue;
        } else {
            return (0);
        }
    }
    return (1);
}