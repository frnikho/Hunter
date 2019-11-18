/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** return factor of a number with recursive
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 12) {
        return (0);
    }
    if (nb == 1) {
        return (1);
    }
    if (nb == 0) {
        return (1);
    }
    return (nb * my_compute_factorial_rec(nb - 1));
}