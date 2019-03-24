/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct window_s window_t;
typedef struct button_s button_t;
typedef struct sprite_s sprite_t;
typedef struct texture_s texture_t;
typedef struct clocks_s clocks_t;
typedef struct text_s text_t;

struct button_s {
    sfVector2i clickPosition;
    sfVector2f size;
    sfVector2f position;
    sfRectangleShape *rect;
    sfSprite *click;
};
struct sprite_s {
    sfSprite *background;
    sfSprite *cloud;
    sfSprite *cloud2;
    sfSprite *ground;
    sfSprite *rocks;
    sfSprite *sky;
    sfSprite *character;
    sfSprite **life;
    sfSprite *scope;
};
struct texture_s {
    sfTexture *background;
    sfTexture *cloud;
    sfTexture *cloud2;
    sfTexture *ground;
    sfTexture *rocks;
    sfTexture *sky;
    sfTexture *character;
    sfTexture *life;
    sfTexture *scope;
};
struct text_s {
    sfText *text;
    sfText *before_score;
    sfText *text_score;
    sfText *text_indic;
    sfText *before_bscore;
    sfText *text_bestscore;
};
struct clocks_s {
    sfClock *clock;
    sfClock *clock_duck;
    sfClock *clock_cloud;
    sfClock *clock_cloud2;
};
struct window_s {
    struct button_s ***button;
    struct texture_s *textures;
    struct sprite_s *sprites;
    struct text_s *text_;
    struct clocks_s *clock_;
    char *bestscore;
    float seconds3;
    float seconds2;
    float seconds;
    float i;
    float time_value;
    int fps;
    int check;
    int life;
    int direction;
    sfRenderWindow *w;
    sfVideoMode video_mode;
    sfEvent event;
    sfMusic *music;
    sfMusic *quack;
    sfIntRect rect;
    sfVector2f move;
    sfTime time;
    sfTime time2;
};