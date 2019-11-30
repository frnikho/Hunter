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
#include "menu/pause_menu.h"
#include <stdlib.h>
#include <time.h>

static int is_ready = 0;
static int is_pause = 0;
static background *bg;
static title_text *title;
static duck_s **ducks;
static int frame;
static sfEvent event;
static player *ninja;
static sfVector2f duck_p = {-3.5 , 0};

static void generate(sfRenderWindow *window)
{
    ducks = malloc(sizeof(duck_s) * 50);
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

static void init(sfRenderWindow *window)
{
    frame = 0;
    sfVector2u size = sfRenderWindow_getSize(window);
    generate(window);
    bg = malloc(sizeof(background));
    create_background(bg, "assets/plains_night.jpg", 3);
    ninja = malloc(sizeof(player));
    sfVector2f ninja_pos = {size.x / 20, size.y / 1.3};
    create_player(ninja, ninja_pos);
    title = malloc(sizeof(title_text));
    sfVector2f pos = {size.x / 2 - 100, size.y / 2 - 120};
    create_title_text(title, pos, 40, "Ready");
}

static void update(game *game_struct)
{
    draw_background(bg, game_struct->window);
    if (is_ready) {
        if (!ducks[0]->alive || ducks[0]->x <= -100) {

        }
        for (int i = 0; i < 50; i++) {
            frame % 4 == 0 ? change_duck_sprites(ducks[i]) : frame;
            move_duck(ducks[i], duck_p);
        }
        animate_background(bg);
    } else {
        draw_title_text(game_struct->window, title);
    }
    for (int i = 0; i < 50; i++)
        draw_duck(game_struct->window, ducks[i]);
    if (frame % 5 == 0)
        animate_player(ninja);
    draw_player(ninja, game_struct->window);
    sfRenderWindow_display(game_struct->window);
    frame++;
}

static void destroy(void)
{
    destroy_title_text(title);
    my_putstr("[destroy] free level 1 menu !\n");
}

void level_1_loop(game *game_struct)
{
    if (game_struct->current_state != LEVEL_1)
        return;
    if (!title)
        init(game_struct->window);
    while (sfRenderWindow_pollEvent(game_struct->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game_struct->window);
            destroy();
        } else if (!is_ready && event.type == sfEvtKeyPressed)
            is_ready = 1;
        else if (!is_ready && event.type == sfEvtMouseButtonPressed)
            is_ready = 1;
        for (int i = 0; i < 50; i++) {
            if (is_clicked_duck(game_struct->window, ducks[i], event))
                ducks[i]->alive = 0;
        }
    }
    sfRenderWindow_clear(game_struct->window, sfBlack);
    update(game_struct);
}