/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    char *add = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest)));

    for (int i = 0; dest[i] != '\0'; i++, j++)
        add[j] = dest[i];
    for (int i = 0; src[i] != '\0'; i++, j++)
        add[j] = src[i];
    add[j + 1] = '\0';
    return (add);
}