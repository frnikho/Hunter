/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return
*/
int my_isalpha(char c);
int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int length = my_strlen(str);

    if (length == 0) {
        return (1);
    }
    for (int i = 0; i < length; i++) {
        if (!my_isalpha(str[i])) {
            return (0);
        }
    }
    return (1);
}