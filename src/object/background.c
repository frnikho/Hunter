/*
** EPITECH PROJECT, 2019
** background.c
** File description:
** background function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "object/background.h"
#include "object/game.h"
#include "my.h"

void create_background(background *bg, char *filepath, float speed)
{
    bg->sprite = malloc(3);
    bg->speed = speed;
    bg->texture = sfTexture_createFromFile(filepath, NULL);
    for (int i = 0; i < 3; i++) {
        bg->sprite[i] = sfSprite_create();
        sfSprite_setTexture(bg->sprite[i], bg->texture, sfTrue);
        sfVector2f pos = {i * 960, -120};
        sfSprite_setPosition(bg->sprite[i], pos);
    }
}

void draw_background(background *bg, sfRenderWindow *window)
{
    for (int i = 0; i < 3; i++) {
        sfVector2f scale = {0.8, 0.8};
        sfSprite_setScale(bg->sprite[i], scale);
        sfRenderWindow_drawSprite(window, bg->sprite[i], NULL);
    }
}

void destroy_background(background *bg)
{
    sfTexture_destroy(bg->texture);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(bg->sprite[0]);
}

void animate_background(background *bg)
{
    for (int i = 0; i < 3; i++) {
        sfVector2f current_pos = sfSprite_getPosition(bg->sprite[i]);
        if (current_pos.x <= -200 - 960) {
            current_pos.x = 960 * 2;
        }
        sfVector2f next_pos = {current_pos.x - bg->speed, current_pos.y};
        sfSprite_setPosition(bg->sprite[i], next_pos);
    }
}