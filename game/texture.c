/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

sfTexture **pause_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 1 + 1);
    texture[0] = sfTexture_createFromFile("graphics/menu.png", NULL);
    return (texture);
}

sfTexture **options_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 4 + 1);

    texture[1] = sfTexture_createFromFile("graphics/60.png", NULL);
    texture[0] = sfTexture_createFromFile("graphics/back.png", NULL);
    texture[2] = sfTexture_createFromFile("graphics/120.png", NULL);
    texture[3] = sfTexture_createFromFile("graphics/30.png", NULL);
    return (texture);
}

sfTexture **menu_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 3 + 1);

    texture[0] = sfTexture_createFromFile("graphics/start.png", NULL);
    texture[1] = sfTexture_createFromFile("graphics/options.png", NULL);
    texture[2] = sfTexture_createFromFile("graphics/quit.png", NULL);
    return (texture);
}
