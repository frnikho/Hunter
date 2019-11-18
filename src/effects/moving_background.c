
#include "my.h"
#include "effects/moving_background.h"

void create_mv_bg(mv_bg_s *bg, char *filepath, sfVector2f pos, int end_index)
{
    bg->filepath = filepath;

    bg->start_x = pos.x;
    bg->end_x = end_index;
    bg->pos1 = pos;
    sfVector2f pos2 = {pos.x / 2, pos.y};
    bg->pos2 = pos2;

    bg->text1 = sfTexture_createFromFile(filepath, NULL);
    bg->text2 = sfTexture_createFromFile(filepath, NULL);
    bg->spr1 = sfSprite_create();
    bg->spr2 = sfSprite_create();
    sfSprite_setTexture(bg->spr1, bg->text1, sfTrue);
    sfSprite_setTexture(bg->spr2, bg->text2, sfTrue);
}

void move_mv_bg(mv_bg_s *bg, sfVector2f plus_position)
{
    sfVector2f pos1 = {bg->pos1.x + 1, bg->pos1.y};
    sfVector2f pos2 = {bg->pos2.x + 1, bg->pos2.y};
    if (pos1.x >= bg->end_x) {
        pos1.x = -580;
        pos2.x = -280;
    }
    bg->pos1 = pos1;
    bg->pos2 = pos2;
}

void draw_mv_bg(sfRenderWindow *window, mv_bg_s *bg)
{
    //sfVector2f scale = {0.80, 0.80};
    sfSprite_setPosition(bg->spr1, bg->pos1);
    sfSprite_setPosition(bg->spr2, bg->pos2);
    //sfSprite_setScale(bg->spr1, scale);
    //sfSprite_setScale(bg->spr2, scale);
    sfRenderWindow_drawSprite(window, bg->spr1, NULL);
    sfRenderWindow_drawSprite(window, bg->spr2, NULL);
}

void destroy_mv_bg(mv_bg_s *background)
{
    free(background);
}