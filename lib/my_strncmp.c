/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare two string
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] > s2[i] || s2[i] != '\0' && s2[i] == '\0') {
            return (1);
        } else if (s1[i] < s2[i] || s1[i] == '\0' && s2[i] != '\0') {
            return (-1);
        } else {
            continue;
        }
    }
    return (0);
}