/*
** EPITECH PROJECT, 2018
** f
** File description:
** f
*/

#include "../include/my.h"

int key_released(sfEvent event)
{
    if ((event.type == sfEvtKeyReleased) && (event.key.code == sfKeyUp))
        return (1);
    if ((event.type == sfEvtKeyReleased) && (event.key.code == sfKeyRight))
        return (2);
    if ((event.type == sfEvtKeyReleased) && (event.key.code == sfKeyDown))
        return (3);
    if ((event.type == sfEvtKeyReleased) && (event.key.code == sfKeyLeft))
        return (4);
    else
        return (0);
}

int key_pressed(sfEvent event)
{
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyUp))
        return (1);
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyRight))
        return (2);
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyDown))
        return (3);
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyLeft))
        return (4);
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyReturn))
        return (5);
    if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyEscape))
        return (6);
    else
        return (0);
}
