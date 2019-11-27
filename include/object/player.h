/*
** EPITECH PROJECT, 2019
** player.h
** File description:
** header file
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int health;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    enum animation {RUNNING = 1, JUMPING = 2} current_anim;
} player;

void create_player(player *pl, sfVector2f pos);
void destroy_player(player *pl);
void draw_player(player *pl, sfRenderWindow *window);
void animate_player(player *pl);

#endif