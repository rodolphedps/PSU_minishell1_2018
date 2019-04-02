/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1
*/

#include "my.h"

char *get_cd_path(mini_t *mshell)
{
    char *stock_path;

    for (int x = 0; mshell->envp[x] != NULL; x++) {
        if (mshell->envp[x][0] == 'H' && mshell->envp[x][1] == 'O'
        && mshell->envp[x][2] == 'M' && mshell->envp[x][3] == 'E') {
            stock_path = my_strdup(mshell->envp[x] + 5);
            chdir(stock_path);
        }
    }
    return (stock_path + 5);
}

void get_cd(mini_t *mshell)
{
    char *stock;

    if (mshell->ret_get[1] == NULL)
        stock = get_cd_path(mshell);
    else {
        if (chdir(mshell->ret_get[1]) == -1)
            my_printf("Dossier introuvable\n");
    }
}

int check_command(mini_t *mshell, char **av)
{
    if (mshell->ret_get[0] == NULL)
        return (0);
    if (my_strncmp(mshell->ret_get[0], "cd", 2) == 0) {
        get_cd(mshell);
        return (1);
    }
    if (my_strncmp(mshell->ret_get[0], "exit", 4) == 0) {
        leave(mshell);
        return (1);
    }
    if (my_strncmp(mshell->ret_get[0], "setenv", 6) == 0)
        set_env(mshell,av);
    if (my_strncmp(mshell->ret_get[0], "unsetenv", 8) == 0)
        return (1);
    return (0);
}

void leave(mini_t *mshell)
{
    char leave[] = "exit";

    if (my_strncmp(mshell->ret_get[0], leave, 4) == 0) {
        my_printf("exit\n");
        exit(0);
    }
}