/*
** EPITECH PROJECT, 2019
** level_1.c
** File description:
** level 1 game loop
*/

#include "my.h"
#include "object/duck.h"
#include "object/game.h"
#include "object/player.h"
#include "object/background.h"

#include "levels/level_1.h"
#include "text/title_text.h"
#include "text/menu_text.h"
#include "menu/pause_menu.h"
#include "utils/string_utils.h"
#include <stdlib.h>
#include <time.h>

static int is_ready;
static int is_pause;
static int score;
static background *bg;
static title_text *title;
static menu_text *score_text;
static menu_text *time_text;
static duck_s **ducks;
static sfEvent ev;
static player *ninja;
static sfVector2f duck_p;

static void generate(sfRenderWindow *window)
{
    ducks = malloc(sizeof(duck_s) * 50);
    duck_p.x = -3.5;
    duck_p.y = 0;
    sfVector2u size = sfRenderWindow_getSize(window);
    int distance = 1000;
    for (int i = 0; i < 50; i++) {
        srand(time(NULL) + i);
        int speed = (rand() % 5) + 2;
        int y = (rand() % 400-150) + 150;
        int x = (rand() % 400) + 100 + distance;
        distance += 200;
        sfVector2f pos = {x, y};
        ducks[i] = malloc(sizeof(duck_s));
        create_duck(ducks[i], pos, 0, speed);
    }
}

static void init(game *game_struct)
{
    title = malloc(sizeof(title_text));
    bg = malloc(sizeof(background));
    ninja = malloc(sizeof(player));
    score_text = malloc(sizeof(menu_text));
    time_text = malloc(sizeof(menu_text));
    is_ready = 0;
    is_pause = 0;
    score = 0;
    sfVector2u size = sfRenderWindow_getSize(game_struct->window);
    sfVector2f ninja_pos = {size.x / 20, size.y / 1.3};
    sfVector2f title_pos = {size.x / 2 - 100, size.y / 2 - 120};
    sfVector2f score_pos = {size.x / 100.2, size.y / 1.05};
    sfVector2f time_pos = {size.x / 1.08, size.y / 1.05};
    sfClock_restart(game_struct->clock);
    generate(game_struct->window);
    create_background(bg, "assets/plains_night.jpg", 3);
    create_player(ninja, ninja_pos);
    create_title_text(title, title_pos, 40, "Ready");
    create_menu_text(score_text, "0", 20, score_pos);
    create_menu_text(time_text, "0 00", 20, time_pos);
}

static void update(game *game_struct)
{
    draw_background(bg, game_struct->window);
    draw_menu_text(game_struct->window, time_text);
    draw_menu_text(game_struct->window, score_text);
    if (is_ready) {
        for (int i = 0; i < 50; i++) {
            game_struct->time % 4 == 0 ? change_duck_sprites(ducks[i]) : i;
            move_duck(ducks[i], duck_p);
        }
        animate_background(bg);
    } else {
        draw_title_text(game_struct->window, title);
    }
    for (int i = 0; i < 50; i++)
        draw_duck(game_struct->window, ducks[i]);
    game_struct->time % 4 == 0 ? animate_player(ninja) : 0;
    draw_player(ninja, game_struct->window);
    sfRenderWindow_display(game_struct->window);
}

static void destroy(void)
{
    free(title);
    free(bg);
    free(ninja);
    free(score_text);
    free(time_text);
    my_putstr("[destroy] free level 1 menu !\n");
}

void level_1_loop(game *game_struct)
{
    if (game_struct->current_state != LEVEL_1)
        return;
    if (!title)
        init(game_struct);
    while (sfRenderWindow_pollEvent(game_struct->window, &ev)) {
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(game_struct->window);
            destroy();
            return;
        }
        !is_ready && ev.type == sfEvtKeyPressed ? is_ready = 1 : 0;
        !is_ready && ev.type == sfEvtMouseButtonPressed ? is_ready = 1 : 0;
        for (int i = 0; i < 50; i++)
            is_c_d(game_struct->window, ducks[i], ev)?ducks[i]->alive = 0:0;
    }
    sfRenderWindow_clear(game_struct->window, sfBlack);
    update(game_struct);
}