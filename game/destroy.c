/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void destroy_text(window_t *w)
{
    sfText_destroy(w->text_->before_bscore);
    sfText_destroy(w->text_->before_score);
    sfText_destroy(w->text_->text_bestscore);
    sfText_destroy(w->text_->text);
    sfText_destroy(w->text_->text_indic);
    sfText_destroy(w->text_->text_score);
}

void destroy_all(window_t *w)
{
    sfSprite_destroy(w->sprites->character);
    sfSprite_destroy(w->sprites->background);
    sfSprite_destroy(w->sprites->scope);
    sfMusic_destroy(w->quack);
    sfMusic_destroy(w->music);
    for (int i = 0; i != 2; i++)
        sfSprite_destroy(w->sprites->life[i]);
    destroy_text(w);
    free(w->sprites);
    free(w->textures);
    free(w->text_);
    free(w->clock_);
    free(w->button);
}
