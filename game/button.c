/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void button_menu(window_t *window, button_t **button, int nb)
{
    sfVector2f size = {210, 60};
    sfVector2f position;
    sfTexture **texture = menu_texture();
    position.x = (window->video_mode.width/2) - size.x/2;
    position.y = (window->video_mode.height/2) - size.y/2;
    for (int i = 0; i != nb; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->click = sfSprite_create();
        buttonInitialise(button[i], position, size);
        graphicInitialise(button[i], sfTransparent, position, texture[i]);
        position.y += 100;
    }
}

void button_options(window_t *window, button_t **button, int nb)
{
    sfVector2f size = {210, 60};
    sfVector2f position;
    sfTexture **texture = options_texture();
    position.x = (window->video_mode.width/2) - size.x/2;
    position.y = (window->video_mode.height/2);
    button[0] = malloc(sizeof(button_t));
    button[0]->click = sfSprite_create();
    buttonInitialise(button[0], position, size);
    graphicInitialise(button[0], sfTransparent, position, texture[0]);
    position.y += 100;
    for (int i = 1; i != nb; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->click = sfSprite_create();
        buttonInitialise(button[i], position, size);
        graphicInitialise(button[i], sfTransparent, position, texture[i]);
    }
}

void button_pause(window_t *window, button_t **button, int nb)
{
    sfVector2f size = {210, 60};
    sfVector2f position;
    sfTexture **texture = pause_texture();
    position.x = (window->video_mode.width/2) - size.x/2;
    position.y = (window->video_mode.height/2) - size.y/2;
    for (int i = 0; i != nb; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->click = sfSprite_create();
        buttonInitialise(button[i], position, size);
        graphicInitialise(button[i], sfTransparent, position, texture[i]);
    }
}

void button_battle(window_t *window, button_t **button, int nb)
{
    sfVector2f size = {210, 60};
    sfVector2f position = {50, 540};
    sfTexture **texture = menu_texture();
    for (int i = 0; i != nb; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->click = sfSprite_create();
        buttonInitialise(button[i], position, size);
        graphicInitialise(button[i], sfTransparent, position, texture[i]);
        position.x += 220;
    }
}

void button_create(window_t *w, int nb)
{
    w->button[0] = malloc(sizeof(button_t *) * 3);
    w->button[1] = malloc(sizeof(button_t *) * 4);
    w->button[2] = malloc(sizeof(button_t *) * 1);
    button_menu(w, w->button[0], 3);
    button_options(w, w->button[1], 4);
    button_pause(w, w->button[2], 1);
}
