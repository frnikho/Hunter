/*
** EPITECH PROJECT, 2019
** my_strlowercase
** File description:
** lowercase a string
*/

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strlowcase(char *str)
{
    int lentgh = my_strlen(str);
    int coef = 32;

    for (int i = 0; i < lentgh; i++) {
        if (str[i] > 64 && str[i] < 91) {
            str[i]=str[i] + coef;
        }
    }
    str[lentgh+1]='\0';
    return (str);
}