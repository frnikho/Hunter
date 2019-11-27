/*
** EPITECH PROJECT, 2019
** duck.h
** File description:
** header file
*/

#ifndef DUCK_H
#define DUCK_H

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int alive;
    float x;
    float y;
    int speed;
    int sprite_stats;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int color;
} duck_s;

void create_duck(duck_s *duck, sfVector2f pos, int color, int speed);
void change_duck_sprites(duck_s *duck);
void draw_duck(sfRenderWindow *window, duck_s *duck);
void destroy_duck(duck_s *duck);
void change_duck_moves(duck_s *duck);
void move_duck(duck_s *duck, sfVector2f duck_p);
int is_clicked_duck(sfRenderWindow *window, duck_s *duck, sfEvent event);

#endif //DUCK_H
