/*
** EPITECH PROJECT, 2019
** duck.c
** File description:
** duck object
*/

#include "object/duck.h"

void create_duck(duck_s *duck, sfVector2f pos, int color, int speed)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 48;
    rect.height = 48;

    duck->x = pos.x;
    duck->y = pos.y;
    duck->color = color;
    duck->speed = 2;
    duck->sprite_stats = 0;
    duck->texture = sfTexture_createFromFile("assets/birds.png", NULL);
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    duck->rect = rect;
}

void change_duck_moves(duck_s *duck)
{
    if (duck->rect.top >= 48 * 3) {
        duck->rect.top = 0;
    } else {
        duck->rect.top += 48;
    }
}

void change_duck_sprites(duck_s *duck)
{
    if (duck->rect.left >= 48 * 2) {
        duck->rect.left = 0;
    } else {
        duck->rect.left += 48;
    }
}

void draw_duck(sfRenderWindow *window, duck_s *duck)
{
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    sfVector2f scale = {2, 2};
    sfVector2f position = {duck->x, duck->y};
    sfSprite_setScale(duck->sprite, scale);
    sfSprite_setPosition(duck->sprite, position);
    sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

void destroy_duck(duck_s *duck)
{
    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(duck->texture);
    free(duck);
}

void move_duck(duck_s *duck, sfVector2f duck_p)
{
    duck->x = duck->x + duck_p.x;
    duck->y = duck->y + duck_p.y;
}