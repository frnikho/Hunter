/*
** EPITECH PROJECT, 2019
** menu_text.h
** File description:
** header file
*/

#ifndef MENU_TEXT_H
#define MENU_TEXT_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct {
    sfVector2f position;
    sfFont *font;
    sfText *text;
    char *title;
    int size;
} menu_text;

void create_menu_text(menu_text *txt, char *title, int size, sfVector2f pos);
void draw_menu_text(sfRenderWindow *window, menu_text *txt);
void destroy_menu_text(menu_text *txt);

#endif
