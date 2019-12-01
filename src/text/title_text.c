/*
** EPITECH PROJECT, 2019
** title_text.c
** File description:
** manage title text function
*/

#include "text/title_text.h"
#include "my.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void create_title_text(title_text *txt, sfVector2f pos, int size, char *title)
{
    txt->position = pos;
    txt->size = size;
    txt->title = title;
    txt->font = sfFont_createFromFile("assets/8_bit_wonder.ttf");
    txt->text = sfText_create();
    txt->shadow_text = sfText_create();
}

void draw_title_text(sfRenderWindow *window, title_text *txt)
{
    sfVector2f shadow_position = {txt->position.x+4, txt->position.y+4};
    sfText_setString(txt->shadow_text, txt->title);
    sfText_setFont(txt->shadow_text, txt->font);
    sfText_setPosition(txt->shadow_text, shadow_position);
    sfText_setCharacterSize(txt->shadow_text, txt->size + 3);
    sfText_setStyle(txt->shadow_text, sfTextBold | sfTextItalic);
    sfText_setColor(txt->shadow_text, sfBlack);
    sfText_setString(txt->text, txt->title);
    sfText_setFont(txt->text, txt->font);
    sfText_setPosition(txt->text, txt->position);
    sfText_setCharacterSize(txt->text, txt->size);
    sfText_setStyle(txt->text, sfTextBold | sfTextItalic);
    sfRenderWindow_drawText(window, txt->shadow_text, NULL);
    sfRenderWindow_drawText(window, txt->text, NULL);
}

void destroy_title_text(title_text *txt)
{
    sfText_destroy(txt->text);
    sfText_destroy(txt->shadow_text);
    sfFont_destroy(txt->font);
    free(txt);
}