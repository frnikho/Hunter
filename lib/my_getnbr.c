/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** convert a string into a number
*/

void my_put_nbr(int nb);
int check_number(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_isnum(char c);
void my_putchar(char c);

int my_getnbr(char const *str)
{
    int result = 0;
    int length = my_strlen(str)-1;
    int coef = 1;
    int is_find = 0;
    int is_neg = 0;

    if (str[0] == '-')
        is_neg = 1;
    for (int i = length; i >= 0; i--) {
        if (!my_isnum(str[i]))
            is_find = 1;
        else if (my_isnum(str[i])) {
            result += (str[i]-48) * coef;
            coef *= 10;
        }
        if (my_isnum(str[i]) && is_find)
            break;
    }
    if (is_neg)
        result *= -1;
    return (result);
}