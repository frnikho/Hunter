/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my.h"
#include "menu/play_menu.h"
#include "menu/score_menu.h"
#include "levels/level_1.h"

#include "object/game.h"

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

static game *game_struct;

int init(float width, float height)
{
    game_struct = malloc(sizeof(game));
    sfVideoMode mode = {width, height, 32};
    game_struct->mode = mode;
    game_struct->window = sfRenderWindow_create(game_struct->mode, "Duck Hunt", sfClose, 0);
    sfRenderWindow_setFramerateLimit(game_struct->window, 60);
    game_struct->current_state = MAIN_MENU;
}

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
    init(width, height);
    while (sfRenderWindow_isOpen(game_struct->window)) {
        play_menu_loop(game_struct);
        level_1_loop(game_struct);
        score_menu_loop(game_struct);
    }
}