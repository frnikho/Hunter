/*
** EPITECH PROJECT, 2019
** menu/play_menu.c
** File description:
** play menu function & loop game
*/
#include "my.h"
#include "menu/play_menu.h"
#include "text/menu_text.h"
#include "text/title_text.h"
#include "object/game.h"
#include "levels/level_1.h"
#include <stdlib.h>

static menu_text *play;
static menu_text *score;
static menu_text *settings;
static title_text *title;
static int running = 1;
static sfEvent event;
static unsigned long frame = 0;

static void init(sfRenderWindow *window)
{
    play = malloc(sizeof(menu_text));
    score = malloc(sizeof(menu_text));
    settings = malloc(sizeof(menu_text));
    title = malloc(sizeof(title_text));
    sfVector2u size = sfRenderWindow_getSize(window);

    sfVector2f play_position = {size.x / 2 - 70, size.y / 2 + 80};
    sfVector2f score_position = {size.x / 2 - 70, size.y / 2 + 120};
    sfVector2f settings_position = {10, size.y - 20};
    sfVector2f title_position = {size.x / 3.5, size.y / 3.5};

    create_menu_text(play, "Play", 30, play_position);
    create_menu_text(score, "Score", 25, score_position);
    create_menu_text(settings, "Settings", 14, settings_position);
    create_title_text(title, title_position, 60, "DuckHunt");
}

static void destroy(void)
{
    destroy_menu_text(play);
    destroy_menu_text(score);
    destroy_menu_text(settings);
    destroy_title_text(title);
    my_putstr("[destroy] free play menu !\n");
}

static void update(sfRenderWindow *window)
{
    sfVector2f move = {1, 0};
    draw_menu_text(window, play);
    draw_menu_text(window, score);
    draw_title_text(window, title);
    sfRenderWindow_display(window);
    frame++;
}

void play_menu_loop(game *game_struct)
{
    if (game_struct->current_state != MAIN_MENU)
        return;
    if (!title)
        init(game_struct->window);
    while (sfRenderWindow_pollEvent(game_struct->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game_struct->window);
            destroy();
            return;
        } else if (is_clicked_menu(game_struct->window, play, event)) {
            game_struct->current_state = LEVEL_1;
            destroy();
            return;
        } else if (is_clicked_menu(game_struct->window, score, event)) {
            game_struct->current_state = SCORE_MENU;
            destroy();
            return;
        }
    }
    update(game_struct->window);
}