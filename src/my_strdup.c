/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup.c
*/

#include "my.h"

int my_strlen(char const *str);

char *my_strdup(char *str)
{
    int i = 0;
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0') {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}