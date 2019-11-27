/*
** EPITECH PROJECT, 2019
** score_menu.c
** File description:
** score menu function
*/

#include "my.h"
#include "menu/play_menu.h"
#include "input_manager.h"
#include "levels/level_1.h"

#include "text/menu_text.h"
#include "text/title_text.h"

#include "object/game.h"

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

static sfEvent event;
static title_text *title;
static menu_text **score;
static menu_text *back;

static void init(game *game_struct)
{
    title = malloc(sizeof(title_text));
    score = malloc(sizeof(menu_text) * 10);
    back = malloc(sizeof(menu_text));

    sfVector2f title_pos = {200, 400};
    sfVector2f back_pos = {50, 100};

    create_title_text(title, title_pos, 32, "Score:");
}

static void update(game *game_struct)
{

}

static void destroy()
{
    //destroy_title_text(title);
    free(score);
    my_putstr("[destroy] free score menu !\n");
}

void score_menu_loop(game *game_struct)
{
    if (game_struct->current_state != SCORE_MENU)
        return;
    if (!title)
        init(game_struct);
    while (sfRenderWindow_pollEvent(game_struct->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game_struct->window); destroy(); return;
        }
    }
    update(game_struct);
}