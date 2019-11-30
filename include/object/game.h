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

enum game_state {MAIN_MENU = 0, SCORE_MENU = 1, LEVEL_1 = 101, LEVEL_2 = 201 };

typedef struct {
    sfRenderWindow *window;
    sfVideoMode mode;
    enum game_state current_state;
} game;

#endif
