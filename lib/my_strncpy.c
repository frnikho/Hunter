/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i < n; i++) {
        dest[i]=src[i];
    }
    dest[i+1]='\0';
    return (dest);
}