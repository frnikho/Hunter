/*
** EPITECH PROJECT, 2019
** moving_background.h
** File description:
** header file
*/

#ifndef MOVING_BACKGROUND_H
#define MOVING_BACKGROUND_H

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct{

    char *filepath;
    int start_x;
    int end_x;

    sfVector2f pos1;
    sfTexture *text1;
    sfSprite *spr1;

    sfVector2f pos2;
    sfTexture *text2;
    sfSprite *spr2;

} mv_bg_s;

void create_mv_bg(mv_bg_s *bg, char *filepath, sfVector2f pos, int end_index);
void draw_mv_bg(sfRenderWindow *window, mv_bg_s *background);
void destroy_mv_bg(mv_bg_s *background);
void move_mv_bg(mv_bg_s *background, sfVector2f plus_position);

#endif
