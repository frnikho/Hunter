/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my.h"
#include "menu/play_menu.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

int test(sfRenderWindow *window);

int main(int argc, char **argv)
{
    int width = 1080;
    int height = 720;
    if (argc == 3) {
        height = my_getnbr(argv[2]);
        width = my_getnbr(argv[1]);
    }
    height = height < 600 ? 1080 : height;
    width = width < 800 ? 720 : width;
    sfVideoMode mode = {width, height, 32};
    char *title = "Hello World !";
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    play_menu_loop(mode, window);
}