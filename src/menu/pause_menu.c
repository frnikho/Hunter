/*
** EPITECH PROJECT, 2019
** pause_menu.c
** File description:
** pause menu function
*/

#include "text/title_text.h"
#include "text/menu_text.h"
#include <stdlib.h>

static title_text *title;
static menu_text *resume;

void create_pause(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    title = malloc(sizeof(title_text));
    resume = malloc(sizeof(resume));

    sfVector2f title_pos = {size.x / 2 - 60, size.y / 2 - 80};
    sfVector2f resume_pos = {size.x / 2 - 30, size.y / 2 + 80};

    create_title_text(title, title_pos, 40, "Pause");
    create_menu_text(resume, "Resume", 20, resume_pos);
}

void draw_pause(sfRenderWindow *window)
{
    draw_menu_text(window, resume);
    draw_title_text(window, title);
}

void destroy_pause()
{

}