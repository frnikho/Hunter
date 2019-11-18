/*
** EPITECH PROJECT, 2019
** input_manager.h
** File description:
** manage user input
*/

#include "my.h"
#include "input_manager.h"

void input_manager(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}