/*
** EPITECH PROJECT, 2019
** texture_manager.h
** File description:
** header file
*/

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <SFML/Graphics.h>
#include <stddef.h>

sfTexture *create_texture_from_file(char const *filepath, const sfIntRect *area);

#endif //TEXTURE_MANAGER_H
