/*
** EPITECH PROJECT, 2019
** text_manager.c
** File description:
** manage text function
*/
#include <stdlib.h>

#include "my.h"
#include "text/menu_text.h"

void create_menu_text(menu_text *txt, char *title, int size, sfVector2f pos)
{
    txt->position = pos;
    txt->size = size;
    txt->title = title;
    txt->font = sfFont_createFromFile("assets/8_bit_wonder.ttf");
    txt->text = sfText_create();
}

void draw_menu_text(sfRenderWindow *window, menu_text *txt)
{
    sfText_setString(txt->text, txt->title);
    sfText_setFont(txt->text, txt->font);
    sfText_setPosition(txt->text, txt->position);
    sfText_setCharacterSize(txt->text, txt->size);
    sfRenderWindow_drawText(window, txt->text, NULL);
}

void destroy_menu_text(menu_text *txt)
{
    free(txt->text);
    free(txt);
}