#ifndef DUCK_H
#define DUCK_H

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    int speed;
    int sprite_stats;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int color;
} duck_s;

void createDuck(duck_s *duck, sfVector2f pos, int color, int speed);
void changeDuckSprites(duck_s *duck);
void drawDuck(duck_s *duck, sfRenderWindow *window);
void destroyDuck(duck_s *duck);
void changeDuckMoves(duck_s *duck);

#endif //DUCK_H
