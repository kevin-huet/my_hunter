/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void button_event(window_t *window)
{
    if (key_pressed(window->event) == 6) {
        window->check = 4;
        sfRenderWindow_setMouseCursorVisible(window->w, sfTrue);
    }
}

void click_event(window_t *window)
{
    sfVector2f pos = sfSprite_getPosition(window->sprites->character);
    sfVector2i click_temp = sfMouse_getPosition(window->w);
    sfVector2f click = {click_temp.x, click_temp.y};
    sfVector2f scope = {click.x - 178 / 4, click.y - 178 / 4};
    sfSprite_setPosition(window->sprites->scope, scope);
    if (window->event.type == sfEvtMouseButtonPressed) {
        if ((pos.x <= click.x && pos.x + 110 >= click.x) &&
            (pos.y <= click.y && pos.y + 110 >= click.y)) {
            effect(window->quack);
            random_pos(window);
            window->rect.width = 110;
            window->i++;
            window->time_value -= window->i / 50000;
        }
        else
            window->life--;
        if (window->life == 0)
            window->check = 3;
    }
}
