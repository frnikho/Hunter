/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** return point of sub chain
*/
int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int str_lentgh = my_strlen(str);
    int to_find_lentgh = my_strlen(to_find);
    int index = 0;

    for (int i = 0; i < str_lentgh; i++) {
        if (str[i] == to_find[index] && str[i+1] == to_find[index+1]) {
            index++;
        }
        if (index+1 == to_find_lentgh){
            return (&str[i - index + 1]);
        }
    }
    return (0);
}