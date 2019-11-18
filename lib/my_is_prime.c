/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** return if a number is prime  
*/
int my_put_nbr(int nb);

int my_is_prime(int nb)
{
    int is_prime = 0;
    int index = 2;

    while (1) {
        if ((nb % index) == 0) {
            is_prime = 0;
            break;
        } else {
            index++;
        }
        if (index >= nb) {
            is_prime = 1;
            break;
        }
    }
    return (is_prime);
}
