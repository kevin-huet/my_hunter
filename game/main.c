/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    window_t window;
    window.i = 0;
    window.fps = 60;
    set_window(&window);
    text(&window);
    life(&window);
    button_create(&window, 3);
    game_status(&window);
    destroy_all(&window);
    return (0);
}
