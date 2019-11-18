/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** revert a string
*/
int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int index = my_strlen(str) - 1;
    int save;

    for (int i = 0; i < index; i++) {
        save = str[i];
        str[i] = str[index];
        str[index] = save;
        index--;
    }
    return (str);
}