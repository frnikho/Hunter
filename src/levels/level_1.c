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
static sfVector2f duck_p = {-8.5, 0};
static sfEvent event;
static player *ninja;
/*
static void generate(sfRenderWindow *window)
{

    ducks = malloc(sizeof(duck_s) * 25);
    sfVector2u size = sfRenderWindow_getSize(window);
    int distance = 0;
    for (int i = 0; i < 25; i++) {
        srand(time(NULL));
        if (i != 0)
            distance = (rand() % i * 100);
        else
            distance = 20;
        float x = (rand() % (size.x / 2 + distance));
        float y = (rand() % (size.y / 2 + rand() % 400));
        int speed = (rand() % 5 + 1);
        sfVector2f pos = {x + 1080, y};
        ducks[i] = malloc(sizeof(duck_s));
        create_duck(ducks[i], pos, 0, speed);
    }
}
*/
static void init(sfRenderWindow *window)
{
    frame = 0;
    sfVector2u size = sfRenderWindow_getSize(window);

    ninja = malloc(sizeof(player));
    sfVector2f ninja_pos = {size.x / 20, size.y / 1.2};
    create_player(ninja, ninja_pos);

    title = malloc(sizeof(title_text));

    sfVector2f pos = {size.x / 2 - 100, size.y / 2 - 120};
    create_title_text(title, pos, 40, "Ready");
}

static void update(game *game_struct)
{

    if (is_pause) {

    }
    if (is_ready) {
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
        if (ninja->current_anim != JUMPING && event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyUp)
            ninja->current_anim = JUMPING;
    }
    sfRenderWindow_clear(game_struct->window, sfBlack);
    update(game_struct);
}

//sfRenderWindow_close(game_struct->window);
//destroy();