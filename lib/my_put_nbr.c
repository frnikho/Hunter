/*
** EPITECH PROJECT, 2019
** put_my_nbr
** File description:
** show a number
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb > -2147483647 && nb < 2147483647) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_put_nbr(nb % 10);
        }
        if (nb < 10 && nb >= 0) {
            my_putchar('0' + nb);
        }
        if (nb < 0) {
            my_putchar('-');
            my_put_nbr(nb * -1);
        }
    }
}