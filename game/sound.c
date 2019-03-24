/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void set_music(window_t *w)
{
    w->music = sfMusic_createFromFile("graphics/main.ogg");
    w->quack = sfMusic_createFromFile("graphics/quack.ogg");
}

void music(sfMusic *music)
{
    if (sfMusic_getStatus(music) == 0)
        sfMusic_play(music);
}

void stop_music(sfMusic *music)
{
    if (sfMusic_getStatus(music) == 2)
        sfMusic_stop(music);
}

void effect(sfMusic *music)
{
    sfMusic_play(music);
}
