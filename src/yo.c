/*
** EPITECH PROJECT, 2019
** word array
** File description:
** array
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int get_col(char *str, char delim, int i)
{
    int cols = 0;

    while (str[i] != delim && str[i] != '\0') {
        cols++;
        i++;
    }
    return (cols);
}

int get_line(char *str, char delim)
{
    int i = 0;
    int nb_l = 0;

    while (str[i] != '\0') {
        if (str[i] == delim)
            nb_l++;
        i++;
    }
    return (nb_l);
}

char **my_str_to_word_array(char *s, char delim)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int line = get_line(s, delim) + 1;
    int col = get_col(s, delim, i);
    char **tab = malloc(sizeof(char *) * (line + 1));

    tab[j] = malloc(sizeof(char) * (col + 1));
    for (; s[i] != '\0'; i++) {
        k = 0;
        for (; s[i] && s[i] == delim || s[i] == ' ' || s[i] == '\t'; i++);
        for (; s[i] != delim && s[i] != '\0'; i++, k++)
            tab[j][k] = s[i];
        tab[j][k] = '\0';
        j++;
        tab[j] = malloc(sizeof(char) * (get_col(s, delim, i) + 1));
    }
    tab[j] = NULL;
    return (tab);
}