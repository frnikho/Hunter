/*
** EPITECH PROJECT, 2019
** level_1.c
** File description:
** level 1 game loop
*/

#include "my.h"
#include "object/duck.h"
#include "effects/moving_background.h"
#include "levels/level_1.h"
#include "text/title_text.h"
#include "menu/pause_menu.h"
#include <stdlib.h>
#include <time.h>

static int is_ready;
static int is_pause;
static title_text *title;
static mv_bg_s *bg;
static duck_s **ducks;
int frame;
static sfVector2f duck_p = {-8.5, 0};

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

static void init(sfRenderWindow *window)
{
    frame = 0;
    is_pause = 0;
    is_ready = 0;
    generate(window);
    bg = malloc(sizeof(mv_bg_s));
    sfVector2u size = sfRenderWindow_getSize(window);
    title = malloc(sizeof(title_text));

    sfVector2f pos = {size.x / 2 - 100, size.y / 2 - 120};
    sfVector2f bg_pos = {-1600, -300};
    create_title_text(title, pos, 40, "Ready");
    create_mv_bg(bg, "assets/plains_night.jpg", bg_pos, 0);

    create_pause(window);
}

static void update(sfRenderWindow *window)
{
    if (is_ready) {
        if (is_pause){
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
        }
    } else {
        draw_mv_bg(window, bg);
        draw_title_text(window, title);
    }
    sfRenderWindow_display(window);
    frame++;
}

void level_1_loop(sfRenderWindow *window)
{
    sfEvent event;
    init(window);
    int running = 1;
    while (running) {
        while (sfRenderWindow_pollEvent(window, &event) && running) {
            if (event.type == sfEvtClosed)
                running = 0;
            if (!is_ready && (event.type == sfEvtKeyPressed
                || event.type == sfEvtMouseButtonPressed))
                is_ready = 1;
        }
        update(window);
    }
    sfRenderWindow_close(window);
}