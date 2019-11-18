/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return
*/
int my_islowcase(char c);
int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!my_islowcase(str[i])) {
            return (0);
        }
    }
    return (1);
}