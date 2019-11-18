/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return
*/
int my_isnum(char c);
int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!my_isnum(str[i])) {
            return (0);
        }
    }
    return (1);
}