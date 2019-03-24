/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

int select_key(sfEvent event, int nb)
{
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyUp))
        nb--;
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyDown))
        nb++;
    if (nb < 0)
        nb = 2;
    if (nb > 2)
        nb = 0;
    return (nb);
}

void menu_change(window_t *window, int a, sfEvent event)
{
    window->i = 0;
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyReturn)) {
        if (a == 0) {
            window->check = 1;
            sfRenderWindow_setMouseCursorVisible(window->w, sfFalse);
        }
        if (a == 1)
            window->check = 2;
        if (a == 2)
            sfRenderWindow_close(window->w);
        random_pos(window);
    }
}

void menu(window_t *window, button_t **button)
{
    static int a = 0;
    window->life = 3;
    window->time_value = 0.0600;
    window->direction = 0;
    while (sfRenderWindow_pollEvent(window->w, &window->event)) {
        a = select_key(window->event, a);
        menu_change(window, a, window->event);
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->w);
    }
    sfRenderWindow_clear(window->w, sfBlack);
    for (int i = 0; i != 3; i++)
        sfRectangleShape_setFillColor(button[i]->rect, sfTransparent);
    sfRectangleShape_setFillColor(button[a]->rect, sfWhite);
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawRectangleShape(window->w, button[i]->rect, NULL);
        sfRenderWindow_drawSprite(window->w, button[i]->click, NULL);
    }
    sfRenderWindow_display(window->w);
}
