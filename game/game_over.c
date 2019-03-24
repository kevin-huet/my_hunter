/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void save_score(window_t *window)
{
    FILE *fp;
    char *str = my_nbr(window->i);
    int i = window->i;
    fp = fopen("score.dat", "r+w");
    if (window->bestscore == NULL || i > my_getnbr(window->bestscore)) {
        sfText_setString(window->text_->text_bestscore, my_nbr(i));
        fwrite(str, 1, sizeof(str), fp);
    }else
        my_putstr("Nope.\n");
    fclose(fp);
    free(str);
}

void set_score_str(window_t *window)
{
    for (int i = 0; i != 3; i++) {
    }
}

void game_over(window_t *window)
{
    static int i = 0;
    while (sfRenderWindow_pollEvent(window->w, &window->event)) {
        if (key_pressed(window->event) == 5) {
            window->check = 0;
            i = 0;
        }
        if (key_pressed(window->event) == 6)
            sfRenderWindow_close(window->w);
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->w);
    }
    if (i == 0) {
        set_score_str(window);
        save_score(window);
        i++;
    }
    sfRenderWindow_clear(window->w, sfBlack);
    sfRenderWindow_drawText(window->w, window->text_->text_indic, NULL);
    sfRenderWindow_drawText(window->w, window->text_->text, NULL);
    sfRenderWindow_drawText(window->w, window->text_->text_bestscore, NULL);
    sfRenderWindow_drawText(window->w, window->text_->text_score, NULL);
    sfRenderWindow_display(window->w);
}
