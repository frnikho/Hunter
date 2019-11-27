/*
** EPITECH PROJECT, 2019
** player.c
** File description:
** player function
*/

#include "object/game.h"
#include "object/player.h"

void create_player(player *pl, sfVector2f pos)
{
    pl->health = 20;
    pl->position = pos;
    pl->current_anim = RUNNING;
    sfIntRect rect;
    if (pl->current_anim == RUNNING)
        rect.top = 529;
    if (pl->current_anim == JUMPING)
        rect.top = 791;
    rect.left = 10;
    rect.width = 70;
    rect.height = 50;

    pl->texture = sfTexture_createFromFile("assets/ninja.png", NULL);
    pl->sprite = sfSprite_create();
    sfSprite_setTexture(pl->sprite, pl->texture, sfTrue);
    pl->rect = rect;
}

void destroy_player(player *pl)
{
    free(pl->texture);
    free(pl->sprite);
    free(pl);
}

void draw_player(player *pl, sfRenderWindow *window)
{
    sfSprite_setTextureRect(pl->sprite, pl->rect);
    sfVector2f scale = {1.5, 1.5};
    sfSprite_setScale(pl->sprite, scale);
    sfSprite_setPosition(pl->sprite, pl->position);
    sfRenderWindow_drawSprite(window, pl->sprite, NULL);
}

void set_player_position(player *pl, float x, float y)
{
    sfVector2f pos = {x, y};
    pl->position = pos;
}

void animate_player(player *pl)
{
    if (pl->current_anim == RUNNING)
        if (pl->rect.left + 60 > (7*60)+10) pl->rect.left = 10; else pl->rect.left += 82;
    if (pl->current_anim == JUMPING) {
        if (pl->rect.left >= 60)
            pl->rect.left = 0;
        else
            pl->rect.left += 66;
        pl->rect.top = 791;
        pl->rect.height = 80;
        pl->rect.width = 65;
    }
}