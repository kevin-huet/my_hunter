/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get a nbr
*/

#include "../include/my.h"

int my_atoi(char *str, int i)
{
    int nbr = 0;

    if (str[i] == '-' && str[i + 1] != '-') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            nbr = 10 * nbr + (str[i] - '0');
            i++;
        }
        nbr = nbr - (nbr * 2);
    }else {
        while (str[i] >= '0' && str[i] <= '9') {
            nbr = 10 * nbr + (str[i] - '0');
            i++;
        }
    }
    return (nbr);
}

int my_getnbr(char *str)
{
    int i = 0;
    int nbr = 0;
    while (str[i] < '0' || str[i] > '9')
        i++;
    if (str[i-1] == '-')
        i--;
    nbr = my_atoi(str, i);
    return (nbr);
}
