/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void animation_duck(window_t *w, int max, int min)
{
    static sfTime time;
    time = sfClock_getElapsedTime(w->clock_->clock_duck);
    w->seconds3 = time.microseconds / 1000000.0;
    if (w->seconds3 > 0.2) {
        w->rect.left += 110;
        sfClock_restart(w->clock_->clock_duck);
    }
    if (w->rect.left >= max)
        w->rect.left = min;
}

void animation_cloud2(int x, window_t *w)
{
    static sfTime time;
    sfVector2f move = {x, 0};
    time = sfClock_getElapsedTime(w->clock_->clock_cloud2);
    if (w->seconds2 > 0.05) {
        sfSprite_move(w->sprites->cloud2, move);
        sfClock_restart(w->clock_->clock_cloud2);
    }
}

void animation_cloud(int x, window_t *w)
{
    static sfTime time;
    sfVector2f move = {x, 0};
    time = sfClock_getElapsedTime(w->clock_->clock_cloud);
    w->seconds2 = time.microseconds / 1000000.0;
    if (w->seconds2 > 0.06) {
        sfSprite_move(w->sprites->cloud, move);
        sfClock_restart(w->clock_->clock_cloud);
    }
}

void animation_reset(window_t *window)
{
    sfVector2f reset = {-850, 0};
    sfVector2f reset1 = {-600, 0};
    sfVector2f pos = sfSprite_getPosition(window->sprites->cloud);
    sfVector2f pos1 = sfSprite_getPosition(window->sprites->cloud2);
    if (pos.x > window->video_mode.width + 50)
        sfSprite_setPosition(window->sprites->cloud, reset);
    if (pos1.x > window->video_mode.width + 50)
        sfSprite_setPosition(window->sprites->cloud2, reset1);
}

void print_game(window_t *window)
{
    animation_cloud(1, window);
    animation_cloud2(1, window);
    animation_reset(window);
    sfRenderWindow_drawSprite(window->w, window->sprites->sky, NULL);
    sfRenderWindow_drawSprite(window->w, window->sprites->cloud, NULL);
    sfRenderWindow_drawSprite(window->w, window->sprites->rocks, NULL);
    sfRenderWindow_drawSprite(window->w, window->sprites->cloud2, NULL);
    sfRenderWindow_drawSprite(window->w, window->sprites->ground, NULL);
    sfRenderWindow_drawSprite(window->w, window->sprites->character, NULL);
    sfRenderWindow_drawSprite(window->w, window->sprites->scope, NULL);
}
