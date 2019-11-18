/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalize a string
*/

int my_isnum(char c);
int my_isalpha(char c);
int my_islowcase(char c);
int my_isupcase(char c);

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && my_islowcase(str[i])) {
            str[i] -= 32;
            continue;
        }
        if (!my_isalpha(str[i - 1]) && my_islowcase(str[i])) {
            str[i] -= 32;
            continue;
        }
        if (my_isnum(str[i - 1]) && my_isupcase(str[i])) {
            str[i] += 32;
        }
        if (my_islowcase(str[i - 1]) && my_isupcase(str[i])) {
            str[i] += 32;
        }
    }
    return (str);
}