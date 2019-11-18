#include "object/duck.h"
#include "my.h"
#include "stdlib.h"

duck_s **ducks;

static void init()
{
    sfVector2f pos = {0, 0};
    createDuck(ducks[0], pos, 0, 3);
}

void level_1(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    init();
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
    }
}