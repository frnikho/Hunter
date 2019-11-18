#include "my.h"
#include "menu/play_menu.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

int main(int argc, char **argv)
{
    int width = 800;
    int height = 600;
    if (argc == 3) {
        height = my_getnbr(argv[2]);
        width = my_getnbr(argv[1]);
    }
    if (height < 600)
        height = 600;
    if (width < 800)
        width = 800;
    double coef = width / height;
    my_put_nbr(height);
    my_putchar('\n');
    my_put_nbr(width);
    sfVideoMode mode = {width, height, 32};
    char *title = "Hello World !";
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    menu_loop(mode, window);
}
/*
int game(sfRenderWindow *window, int width, int height)
{
    sfEvent event;

    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;
    sfVector2f pos = {0, 0};
    duck_s *duck = malloc(sizeof(duck_s));
    createDuck(duck, pos, 0, 3);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.2) {
            sfRenderWindow_clear(window, sfBlack);
            changeDuckSprites(duck);
            drawDuck(duck, window);
            sfClock_restart(clock);
            sfRenderWindow_display(window);
            input_manager(window, event);
        }
    }
    //destroyDuck(duck);
}
 */