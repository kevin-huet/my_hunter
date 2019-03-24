/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void life_position(window_t *window)
{
    sfVector2f pos = {window->video_mode.width - 192, 0};
    for (int i = 0; i != 3; i++) {
        sfSprite_setPosition(window->sprites->life[i], pos);
        pos.x += 64;
    }
}

void life(window_t *w)
{
    w->textures->life = sfTexture_createFromFile("graphics/life.png", NULL);
    w->sprites->life = malloc(sizeof(sfSprite *) * 3);
    for (int i = 0; i != 3; i++) {
        w->sprites->life[i] = sfSprite_create();
        sfSprite_setTexture(w->sprites->life[i], w->textures->life, NULL);
    }
    life_position(w);
}

void scoreboard(window_t *window)
{
    sfText_setString(window->text_->text_score, my_nbr(window->i));
    for (int i = 0; i != window->life; i++)
        sfRenderWindow_drawSprite(window->w, window->sprites->life[i], NULL);
    sfRenderWindow_drawText(window->w, window->text_->text_score, NULL);
}

void create_file(window_t *window, FILE *fp)
{
    fp = fopen("score.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("score.dat", "wb");
        my_putstr("Données inexistantes, creation en cours...\n");
    }
    else
        my_putstr("Données existantes, chargement...\n");
    fclose(fp);
}

void best_score(window_t *window)
{
    FILE *fp;
    window->bestscore = malloc(sizeof(char) * 4);
    create_file(window, fp);
    fp = fopen("score.dat", "r+w");
    fread(window->bestscore, 3, 1, fp);
    window->bestscore[3] = '\0';
    my_putstr("Best score : ");
    my_putstr(window->bestscore);
    my_putchar('\n');
    fclose(fp);
}
