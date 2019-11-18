/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** strdup function
*/

void my_putstr(char const *str);
void my_putchar(char c);

int my_show_word_array(char * const *words)
{
    for (int i = 0; words[i] != 0; i++) {
        my_putstr(words[i]);
        my_putchar('\n');
    }
}