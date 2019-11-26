/*
** EPITECH PROJECT, 2019
** game.h
** File description:
** header file
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfView *current_view;
};

#endif
