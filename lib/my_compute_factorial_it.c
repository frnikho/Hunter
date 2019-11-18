/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** return factor of a number 
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12) {
        return (0);
    }
    for (nb; nb > 1; nb--) {
        result = result * nb;
    }
    if (result == 0 || nb == 0) {
        return (1);
    }
    if (result < 0) {
        return (0);
    }
    return (result);
}
