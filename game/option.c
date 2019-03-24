/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

int select_key2(sfEvent event, int nb)
{
    if (key_pressed(event) == 1)
        nb--;
    if (key_pressed(event) == 3)
        nb++;
    if (nb < 0)
        nb = 1;
    if (nb > 1)
        nb = 0;
    return (nb);
}

void change_fps(window_t *window)
{
    static int i = 0;
    if (i > 2)
        i = 0;
    if (i == 0)
        window->fps = 120;
    if (i == 1)
        window->fps = 30;
    if (i == 2)
        window->fps = 60;
    sfRenderWindow_setFramerateLimit(window->w, window->fps);
    i++;
}

void option_change(window_t *window, int a)
{
    if ((key_pressed(window->event) == 5)) {
        if (a == 1)
            change_fps(window);
        if (a == 0)
            window->check = 0;
    }
}

void check_fps(window_t *window, button_t **b)
{
    if (window->fps == 60)
        sfRenderWindow_drawSprite(window->w, b[1]->click, NULL);
    if (window->fps == 30)
        sfRenderWindow_drawSprite(window->w, b[2]->click, NULL);
    if (window->fps == 120)
        sfRenderWindow_drawSprite(window->w, b[3]->click, NULL);
}

void option(window_t *window, button_t **button)
{
    static int a = 0;
    while (sfRenderWindow_pollEvent(window->w, &window->event)) {
        a = select_key2(window->event, a);
        option_change(window, a);
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->w);
    }
    sfRenderWindow_clear(window->w, sfBlack);
    for (int i = 0; i != 2; i++)
        sfRectangleShape_setFillColor(button[i]->rect, sfTransparent);
    sfRectangleShape_setFillColor(button[a]->rect, sfWhite);
    for (int i = 0; i != 2; i++)
        sfRenderWindow_drawRectangleShape(window->w, button[i]->rect, NULL);
    sfRenderWindow_drawSprite(window->w, button[0]->click, NULL);
    check_fps(window, button);
    sfRenderWindow_display(window->w);
}
