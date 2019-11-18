/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** convert a string into a number
*/

int my_convert_into_integer(char c)
{
    int index = 0;
    int rt_number = 0;

    if (c < '0' || c > '9') {
        return (-84);
    }
    for (int i = '0'; i < '9'; i++) {
        if (c == i){
            rt_number = index;
            break;
        }
        index++;
    }
    return (rt_number);
}
