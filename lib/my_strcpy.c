/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy string
*/

void my_putchar(char c);

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i]='\0';
    return (dest);
}