/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** set_unsetenv
*/

#include "my.h"

int get_nb_obj_tab(mini_t *mshell)
{
    int i = 0;

    while (mshell->envp[i] != NULL) {
        i++;
    }
    return (i);
}

void set_env(mini_t *mshell, char **av)
{
    char **new_env = malloc(sizeof(char *) * (get_nb_obj_tab(mshell) + 1));
    int i = 0;

    while (mshell->envp[i] != NULL) {
        new_env[i] = my_strdup(mshell->envp[i]);
        printf("%s\n", new_env[i]);
        i++;
    }
    new_env[i] = malloc(sizeof(char) * (10000));
}