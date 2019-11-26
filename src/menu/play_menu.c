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
#include "levels/level_1.h"
#include <stdlib.h>

static menu_text *play;
static menu_text *score;
static menu_text *settings;
static title_text *title;
static mv_bg_s *background;
static unsigned long frame = 0;

static void init(sfRenderWindow *window)
{
    play = malloc(sizeof(menu_text));
    score = malloc(sizeof(menu_text));
    settings = malloc(sizeof(menu_text));
    title = malloc(sizeof(title_text));
    background = malloc(sizeof(mv_bg_s));
    sfVector2u size = sfRenderWindow_getSize(window);

    my_put_nbr(size.y);
    sfVector2f play_position = {size.x / 2 - 70, size.y / 2 + 80};
    sfVector2f score_position = {size.x / 2 - 70, size.y / 2 + 120};
    sfVector2f settings_position = {10, size.y - 20};
    sfVector2f title_position = {size.x / 3.5, size.y / 3.5};
    sfVector2f background_position = {-560, -350};

    create_menu_text(play, "Play", 30, play_position);
    create_menu_text(score, "Score", 25, score_position);
    create_menu_text(settings, "Settings", 14, settings_position);
    create_title_text(title, title_position, 60, "DuckHunt");
    create_mv_bg(background, "assets/background.jpg", background_position, 0);
}

static void destroy(void)
{
    destroy_menu_text(play);
    destroy_menu_text(score);
    destroy_menu_text(settings);
    destroy_title_text(title);
}

static void update(sfRenderWindow *window)
{
    sfVector2f move = {1, 0};
    if (frame % 2 == 0)
        move_mv_bg(background, move);
    draw_mv_bg(window, background);
    draw_menu_text(window, play);
    draw_menu_text(window, score);
    draw_title_text(window, title);
    sfRenderWindow_display(window);
    frame++;
}

void play_menu_loop(sfVideoMode mode, sfRenderWindow *window)
{
    sfEvent event;
    init(window);
    int running = 1;
    while (running) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                running = 0;
                sfRenderWindow_close(window);
            }
            if (is_clicked(window, play, event)) {
                running = 0;
                level_1_loop(window);
            }
        }
        update(window);
    }
    destroy();
}