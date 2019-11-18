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
#include "effects/moving_background.h"
#include "input_manager.h"

#include <stdlib.h>

menu_text *play;
menu_text *score;
menu_text *settings;

title_text *title;

mv_bg_s *background;

unsigned long frame = 0;

static void init(sfRenderWindow *window)
{
    play = malloc(sizeof(menu_text));
    score = malloc(sizeof(menu_text));
    settings = malloc(sizeof(menu_text));
    title = malloc(sizeof(title_text));
    background = malloc(sizeof(mv_bg_s));
    sfVector2u size = sfRenderWindow_getSize(window);

    sfVector2f play_position = {size.x / 2 - 56, size.y / 2 +110};
    sfVector2f score_position = {size.x / 2 - 60, size.y / 2 +170};
    sfVector2f settings_position = {10, size.y - 20};
    sfVector2f title_position = {size.x / 2 - 240, size.y - 520};
    sfVector2f background_position = {-560, -350};

    create_menu_text(play, "Play", 30, play_position);
    create_menu_text(score, "Score", 25, score_position);
    create_menu_text(settings, "Settings", 14, settings_position);
    create_title_text(title, title_position, 60, "DuckHunt");
    create_mv_bg(background, "assets/background.jpg", background_position, 0);
}

void destroy()
{
    destroy_menu_text(play);
    destroy_menu_text(score);
    destroy_menu_text(settings);
    destroy_title_text(title);
}

static void update(sfRenderWindow *window, sfClock *clock)
{
    sfVector2f move = {1, 0};
    if (frame % 2 == 0)
        move_mv_bg(background, move);
    draw_mv_bg(window, background);
    draw_menu_text(window, play);
    draw_menu_text(window, score);
    draw_menu_text(window, settings);
    draw_title_text(window, title);
    sfRenderWindow_display(window);
    frame++;
}

void menu_loop(sfVideoMode mode, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfEvent event;

    init(window);
    while (sfRenderWindow_isOpen(window)) {
        input_manager(window, event);
        update(window, clock);
    }
    destroy();
}