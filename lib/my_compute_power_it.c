/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** return the first argument raised to the power
*/

void my_put_nbr(int nb);

int my_compute_power_it(int nb, int p)
{
    int power = 1;

    if (nb == 0 && p > 1) {
        return (0);
    }
    if (nb < 0 || p < 0) {
        return (0);
    }
    if (p == 0 || nb == 0) {
        return (1);
    }
    if (p == 1) {
        return (nb);
    }
    while (p != 0) {
        power = power * nb;
        p--;
    }
    return (power);
}