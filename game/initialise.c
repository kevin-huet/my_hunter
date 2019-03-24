/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void buttonInitialise(button_t *button, sfVector2f p, sfVector2f s)
{
    sfVector2f hover = p;

    hover.x -= 5;
    hover.y -= 5;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, hover);
    sfRectangleShape_setSize(button->rect, s);
}

void graphicInitialise(button_t *b, sfColor col, sfVector2f p, sfTexture *t)
{
    sfRectangleShape_setFillColor(b->rect, col);
    sfSprite_setPosition(b->click, p);
    sfSprite_setTexture(b->click, t, sfTrue);
}
