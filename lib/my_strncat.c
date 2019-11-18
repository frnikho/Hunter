/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** cat two string together with a custom size
*/

int my_strlen(char const *str);
void my_putchar(char c);
void my_put_nbr(int nb);

char *my_strncat(char *dest, char const *src, int nb)
{
    int length_dest = my_strlen(dest);
    int length_src = my_strlen(src);
    int length_total = length_dest + length_src;

    for (int i = 0; i < nb; i++) {
        dest[length_dest + i]=src[i];
    }
    dest[nb] = '\0';
    return (dest);
}