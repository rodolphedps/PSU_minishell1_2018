/*
** EPITECH PROJECT, 2019
** clean buffer
** File description:
** minishell1
*/

#include "my.h"

char *clean_buffer(mini_t *mshell)
{
    for (int i = 0; mshell->buff[i] < 33; i++);
    for (int j = 0; mshell->buff[j] != '\0'; j++) {
        if (mshell->buff[j] == '\\' && mshell->buff[j] == 't') {
            mshell->buff[j] = ' ';
            mshell->buff[j + 1] = ' ';
        }
    }
    return (mshell->buff);
}