/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

void create_sprite(window_t *w, sprite_t *sprite)
{
    sprite->background = sfSprite_create();
    sprite->character = sfSprite_create();
    sprite->scope = sfSprite_create();
    sprite->rocks = sfSprite_create();
    sprite->sky = sfSprite_create();
    sprite->ground = sfSprite_create();
    sprite->cloud = sfSprite_create();
    sprite->cloud2 = sfSprite_create();
}

void set_texture(window_t *w, texture_t *t)
{
    t->background = sfTexture_createFromFile("graphics/background.png", NULL);
    t->character = sfTexture_createFromFile("graphics/spritesheet.png", NULL);
    t->scope = sfTexture_createFromFile("graphics/viseur.png", NULL);
    t->rocks = sfTexture_createFromFile("graphics/rocks.png", NULL);
    t->sky = sfTexture_createFromFile("graphics/sky.png", NULL);
    t->ground = sfTexture_createFromFile("graphics/ground.png", NULL);
    t->cloud = sfTexture_createFromFile("graphics/clouds_1.png", NULL);
    t->cloud2 = sfTexture_createFromFile("graphics/clouds_2.png", NULL);
}

void set_sprite(window_t *w, sprite_t *s, texture_t *t)
{
    sfVector2f scale = {0.25, 0.25};
    sfVector2f scale2 = {0.45, 0.56};
    sfVector2f pos = {0, 64};
    sfSprite_setTexture(s->background, t->background, sfTrue);
    sfSprite_setTexture(s->character, t->character, sfTrue);
    sfSprite_setTexture(s->scope, t->scope, sfTrue);
    sfSprite_setTexture(s->rocks, t->rocks, sfTrue);
    sfSprite_setTexture(s->sky, t->sky, sfTrue);
    sfSprite_setTexture(s->ground, t->ground, sfTrue);
    sfSprite_setTexture(s->cloud, t->cloud, sfTrue);
    sfSprite_setTexture(s->cloud2, t->cloud2, sfTrue);
    sfSprite_setScale(s->scope, scale);
    sfSprite_setScale(s->rocks, scale2);
    sfSprite_setScale(s->sky, scale2);
    sfSprite_setScale(s->ground, scale2);
    sfSprite_setScale(s->cloud, scale2);
    sfSprite_setScale(s->cloud2, scale2);
    sfSprite_setPosition(s->character, pos);
}

void set_rect(window_t *w)
{
    w->rect.left = 0;
    w->rect.top = 0;
    w->rect.width = 110;
    w->rect.height = 110;
}

void set_window(window_t *w)
{
    sfVideoMode mode = {800, 600, 32};
    w->button = malloc(sizeof(button_t *) * 3);
    w->sprites = malloc(sizeof(sprite_t));
    w->textures = malloc(sizeof(texture_t));
    w->text_ = malloc(sizeof(text_t));
    w->clock_ = malloc(sizeof(clocks_t));
    w->clock_->clock_cloud = sfClock_create();
    w->clock_->clock_cloud2 = sfClock_create();
    w->clock_->clock_duck = sfClock_create();
    best_score(w);
    set_music(w);
    create_sprite(w, w->sprites);
    set_texture(w, w->textures);
    set_sprite(w, w->sprites, w->textures);
    set_rect(w);
    free(w->textures);
    w->video_mode = mode;
    w->w = sfRenderWindow_create
        (w->video_mode, "my_hunter_2018", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(w->w, 60);
}
