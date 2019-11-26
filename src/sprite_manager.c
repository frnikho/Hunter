/*
** EPITECH PROJECT, 2019
** sprite_manager.c
** File description:
** sprite function
*/

int text_is_clicked(sfRenderWindow *window, sfText *txt, sfEvent event)
{
    sfVector2f pos = sfText_getPosition(txt);
    sfFloatRect rect = sfText_getLocalBounds(txt->text);
    int mx = rect.width + pos.x;
    int my = rect.height + pos.y;
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x <= mx && event.mouseButton.x >= pos.x
            && event.mouseButton.y <= my && event.mouseButton.y >= pos.y)
            return (1);
        else
            return (0);
    } else {
        return (0);
    }
}