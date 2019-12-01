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
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

static game *game_s;

int check_argv(char **argv)
{
    if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Duck Hunt:\n your goal -> shoot all the ducks\n");
        my_putstr(" user input -> only mouse left click\n");
        my_putstr(" default window size -> 1080 x 720\n");
    } else
        my_putstr("invalid arguments !");
    return (0);
}

int init(float width, float height)
{
    game_s = malloc(sizeof(game));
    sfVideoMode mode = {width, height, 32};
    game_s->clock = sfClock_create();
    char *title = "Duck Hunt";
    game_s->mode = mode;
    game_s->window = sfRenderWindow_create(game_s->mode, title, sfClose, 0);
    sfRenderWindow_setFramerateLimit(game_s->window, 60);
    game_s->current_state = MAIN_MENU;
}

int main(int argc, char **argv)
{
    if (argc > 1)
        return (check_argv(argv));
    init(1080, 720);
    const int ratio = 16666.6;
    while (sfRenderWindow_isOpen(game_s->window)) {
        game_s->time = sfClock_getElapsedTime(game_s->clock).microseconds/ratio;
        play_menu_loop(game_s);
        level_1_loop(game_s);
        score_menu_loop(game_s);
    }
    return (0);
}