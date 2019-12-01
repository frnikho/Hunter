/*
** EPITECH PROJECT, 2019
** background.h
** File description:
** header file
*/


#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.h>
#include "object/game.h"

typedef struct {
    char *filepath;
    float speed;
    sfTexture *texture;
    sfSprite **sprite;
    sfVector2f **position;
} background;

void create_background(background *bg, char *filepath, float speed);
void draw_background(background *bg, sfRenderWindow *window);
void destroy_background(background *bg);
void move_background(background *bg);
void animate_background(background *bg);

#endif
