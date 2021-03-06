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

int is_clicked_menu(sfRenderWindow *window, menu_text *txt, sfEvent event)
{
    sfVector2f pos = txt->position;
    sfFloatRect rect = sfText_getLocalBounds(txt->text);
    int mx = rect.width + pos.x;
    int my = rect.height + pos.y;
    if (event.type != sfEvtMouseButtonPressed)
        return (0);
    else if (event.mouseButton.button != sfMouseLeft)
        return (0);
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    if (x <= mx && x >= pos.x && y <= my && y >= pos.y)
        return (1);
    else
        return (0);
}