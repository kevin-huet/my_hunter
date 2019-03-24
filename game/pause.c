/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

int select_key3(sfEvent event, int nb)
{
    if (key_pressed(event) == 1)
        nb--;
    if (key_pressed(event) == 3)
        nb++;
    if (nb < 0)
        nb = 1;
    if (nb > 0)
        nb = 0;
    return (nb);
}

void pause_change(window_t *window, int a)
{
    if (key_pressed(window->event) == 6)
        window->check = 1;
    if (key_pressed(window->event) == 5) {
        if (a == 0)
            window->check = 0;
    }
}

void pause_menu(window_t *window, button_t **button)
{
    static int a = 0;
    while (sfRenderWindow_pollEvent(window->w, &window->event)) {
        a = select_key3(window->event, a);
        pause_change(window, a);
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->w);
    }
    sfRenderWindow_clear(window->w, sfBlack);
    for (int i = 0; i != 1; i++)
        sfRectangleShape_setFillColor(button[i]->rect, sfTransparent);
    sfRectangleShape_setFillColor(button[a]->rect, sfWhite);
    for (int i = 0; i != 1; i++) {
        sfRenderWindow_drawRectangleShape(window->w, button[i]->rect, NULL);
        sfRenderWindow_drawSprite(window->w, button[i]->click, NULL);
    }
    sfRenderWindow_display(window->w);
}
