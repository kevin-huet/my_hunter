/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

char *my_nbr(int nb)
{
    char *str;
    int temp = nb;
    int modul = 10;
    int i = 0;

    for (;temp % modul != 0; i++) {
        temp %= modul;
        modul /= 10;
    }
    str = malloc(sizeof(char) * i + 1);
    str[0] = nb / 100 % 100 + '0';
    str[1] = nb / 10 % 10 + '0';
    str[2] = nb / 1 % 10 + '0';
    str[3] = '\0';
    return (str);
}

void text_setPosition(window_t *window)
{
    sfVector2f pos_t;
    pos_t.x = (window->video_mode.width/2) - 150;
    pos_t.y = (window->video_mode.height/2) - 50;
    sfText_setPosition(window->text_->text, pos_t);
    pos_t.x = (window->video_mode.width/2) - 160;
    pos_t.y = (window->video_mode.height/2);
    sfText_setPosition(window->text_->text_indic, pos_t);
    pos_t.x = (window->video_mode.width/2) + 75;
    pos_t.y = (window->video_mode.height/2) + 30;
    sfText_setPosition(window->text_->text_bestscore, pos_t);
    sfText_setPosition(window->text_->before_bscore, pos_t);

}

void init_text(window_t *window)
{
    window->text_->text_bestscore = sfText_create();
    window->text_->text_score = sfText_create();
    window->text_->text = sfText_create();
    window->text_->text_indic = sfText_create();
    window->text_->before_bscore = sfText_create();
    window->text_->before_bscore = sfText_create();
}

void text_score(window_t *window, sfFont *font)
{
    sfText_setString(window->text_->text_bestscore, window->bestscore);
    sfText_setString(window->text_->text_score, my_nbr(0));
    sfText_setFont(window->text_->text_score, font);
    sfText_setFont(window->text_->text_bestscore, font);
    sfText_setCharacterSize(window->text_->text_bestscore, 30);
    sfText_setCharacterSize(window->text_->text_score, 30);
}

void text(window_t *window)
{
    char *str = "Enter = Main menu | Esc = Quit";
    init_text(window);
    sfFont *font = sfFont_createFromFile("graphics/arial.ttf");
    sfText_setString(window->text_->text, "Game Over");
    sfText_setString(window->text_->text_indic, str);
    sfText_setFont(window->text_->text, font);
    sfText_setFont(window->text_->text_indic, font);
    sfText_setCharacterSize(window->text_->text, 50);
    sfText_setCharacterSize(window->text_->text_indic, 20);
    text_score(window, font);
    text_setPosition(window);
}
