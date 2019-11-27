/*
** EPITECH PROJECT, 2019
** input_manager.c
** File description:
** input manager function
*/

#include "object/game.h"

void input_manager(sfEvent event, game *game_struct)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game_struct->window);
    }
}