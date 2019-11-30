/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** find a prime number
*/
int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int positive = 1;
    int negative = 0;
    if (my_is_prime(nb))
        return (nb);
    while (1) {
        if (my_is_prime(nb + positive)) {
            return (nb + positive);
        } else {
            positive++;
        }
        if (my_is_prime(nb + negative)) {
            return (nb + negative);
        } else {
            negative--;
        }
    }
}