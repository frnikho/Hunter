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

#include "levels/level_1.h"
#include "text/title_text.h"
#include "menu/pause_menu.h"
#include <stdlib.h>
#include <time.h>

static int is_ready = 0;
static int is_pause = 0;
static title_text *title;
static duck_s **ducks;
static int frame;
static sfEvent event;
static player *ninja;

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
    ninja = malloc(sizeof(player));
    sfVector2f ninja_pos = {size.x / 20, size.y / 1.2};
    create_player(ninja, ninja_pos);

    title = malloc(sizeof(title_text));

    sfVector2f pos = {size.x / 2 - 100, size.y / 2 - 120};
    create_title_text(title, pos, 40, "Ready");
}

static sfVector2f duck_p = {-3.5 , 0};

static void update(game *game_struct)
{

    if (is_pause) {

    }
    if (is_ready) {
        for (int i = 0; i < 50; i++) {
            if (frame % 4 == 0) {
                change_duck_sprites(ducks[i]);
            }
            move_duck(ducks[i], duck_p);
        }
       /* if (is_pause){
            draw_pause(window);
        } else {
            sfVector2f plus = {6.5, 0};
            move_mv_bg(bg, plus);
            draw_mv_bg(window, bg);
            for (int i = 0; i < 25; i++)
                draw_duck(window, ducks[i]);
            if (frame % 4 == 0) {
                for (int i = 0; i < 25; i++) {
                    change_duck_sprites(ducks[i]);
                    move_duck(ducks[i], duck_p);
                }
            }
        } */
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

void destroy(void)
{
    destroy_title_text(title);
    free(ducks);
    my_putstr("[destroy] free level 1 menu !\n");
}

static void check_clicked(game *game_struct)
{
    for (int i = 0; i < 50; i++) {
        if (is_clicked_duck(game_struct->window, ducks[i], event)) {
            ducks[i]->alive = 0;
        }
    }
}

void level_1_loop(game *game_struct)
{
    if (game_struct->current_state != LEVEL_1)
        return;
    if (!title)
        init(game_struct->window);
    while (sfRenderWindow_pollEvent(game_struct->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game_struct->window); destroy();
        } else if (!is_ready && (event.type == sfEvtKeyPressed
        || event.type == sfEvtMouseButtonPressed))
            is_ready = 1;
        if (is_ready && !is_pause && event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            is_pause = 1;
        check_clicked(game_struct);

    }
    sfRenderWindow_clear(game_struct->window, sfBlack);
    update(game_struct);
}

//sfRenderWindow_close(game_struct->window);
//destroy();