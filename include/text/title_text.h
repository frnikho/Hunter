/*
** EPITECH PROJECT, 2019
** title_text.h
** File description:
** header file
*/

#ifndef TITLE_TEXT_H
#define TITLE_TEXT_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct {
    sfVector2f position;
    sfFont *font;
    sfText *text;

    sfText *shadow_text;

    char *title;
    int size;
} title_text;

void create_title_text(title_text *txt, sfVector2f pos, int size, char *title);
void draw_title_text(sfRenderWindow *window, title_text *txt);
void destroy_title_text(title_text *txt);

#endif
