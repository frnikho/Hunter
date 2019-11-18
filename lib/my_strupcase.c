/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare two string
*/

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strupcase(char *str)
{
    int lentgh = my_strlen(str);
    int coef = 32;

    for (int i = 0; i < lentgh; i++) {
        if (str[i] > 96 && str[i] < 123) {
            str[i] = str[i] - coef;
        }
    }
    return (str);
}