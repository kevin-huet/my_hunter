/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void random_pos(window_t *window)
{
    sfVector2f move = {0, 0};
    srand(time(NULL));
    move.y = (rand() % (500 - 64 + 1)) + 64;
    sfSprite_setPosition(window->sprites->character, move);
    window->direction = 0;
}

void reverse_duck(window_t *window, sfVector2f duck_pos)
{
    sfVector2f move = {-20, 0};
    window->time = sfClock_getElapsedTime(window->clock_->clock);
    window->seconds = window->time.microseconds / 1000000.0;
    if (duck_pos.x <= -110) {
        window->rect.width = 110;
        window->life--;
        random_pos(window);
        if (window->life <= 0)
            window->check = 3;
        window->direction = 0;
    }
    if (window->seconds > window->time_value) {
        sfClock_restart(window->clock_->clock);
        sfSprite_move(window->sprites->character, move);
    }
    animation_duck(window, 440, 110);
}

void move_duck(window_t *window, sfVector2f duck_pos)
{
    sfVector2f move = {20, 0};
    window->time = sfClock_getElapsedTime(window->clock_->clock);
    window->seconds = window->time.microseconds / 1000000.0;
    if (duck_pos.x >= window->video_mode.width - 110) {
        window->rect.width = -110;
        window->rect.left = 110;
        window->direction = 1;
    }
    if (window->seconds > window->time_value) {
        sfClock_restart(window->clock_->clock);
        sfSprite_move(window->sprites->character, move);
    }
    animation_duck(window, 330, 0);
}

void game(window_t *window)
{
    sfVector2f duck_pos = sfSprite_getPosition(window->sprites->character);
    if (window->direction == 0)
        move_duck(window, duck_pos);
    if (window->direction == 1)
        reverse_duck(window, duck_pos);
    while (sfRenderWindow_pollEvent(window->w, &window->event)) {
        button_event(window);
        click_event(window);
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->w);
    }
    sfRenderWindow_clear(window->w, sfBlack);
    sfSprite_setTextureRect(window->sprites->character, window->rect);
    print_game(window);
    scoreboard(window);
    sfRenderWindow_display(window->w);
}

void game_status(window_t *window)
{
    window->check = 0;
    window->clock_->clock = sfClock_create();
    while (sfRenderWindow_isOpen(window->w)) {
        if (window->check == 1) {
            music(window->music);
            game(window);
        }
        if (window->check == 0) {
            stop_music(window->music);
            menu(window, window->button[0]);
        }
        if (window->check == 2)
            option(window, window->button[1]);
        if (window->check == 3)
            game_over(window);
        if (window->check == 4)
            pause_menu(window, window->button[2]);
    }
    sfRenderWindow_destroy(window->w);
}

