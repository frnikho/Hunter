/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** return square of a number
*/
int my_compute_power_it(int nb, int p);

int my_compute_square_root(int nb)
{
    int is_found = 0;
    int index = 2;

    while (!is_found) {
        int power = my_compute_power_it(index, 2);
        if (nb == 1) {
            return (1);
        }
        if (power > nb) {
            return (0);
        }
        if (power == nb) {
            return (index);
        }
        index++;
    }
}