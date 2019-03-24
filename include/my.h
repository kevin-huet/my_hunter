/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>

void scoreboard(window_t *window);
sfTexture **options_texture(void);
void game_over(window_t *window);
void menu(window_t *window, button_t **button);
void game(window_t *window);
void my_putchar(char c);
void my_putstr(char *str);
void game_status(window_t *window);
char *my_nbr(int nb);
void best_score(window_t *window);
void set_music(window_t *window);
int my_getnbr(char *str);
void pause_menu(window_t *window, button_t **button);
void click_event(window_t *window);
void music(sfMusic *music);
void text(window_t *window);
void option(window_t *window, button_t **button);
void effect(sfMusic *music);
void animation_duck(window_t *window, int min, int max);
void life(window_t *window);
void random_pos(window_t *window);
void destroy_all(window_t *window);
void graphicInitialise(button_t *b, sfColor col, sfVector2f pos, sfTexture *t);
void menu(window_t *window, button_t **button);
void button_create(window_t *window, int nb);
void buttonInitialise(button_t *button, sfVector2f p, sfVector2f s);
sfTexture **pause_texture(void);
sfTexture **menu_texture(void);
int key_pressed(sfEvent event);
void print_game(window_t *window);
void game_status(window_t *w);
void print_game();
void set_window(window_t *w);
void button_event(window_t *window);
void stop_music(sfMusic *music);