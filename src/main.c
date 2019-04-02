/*
** EPITECH PROJECT, 2019
** main minishell
** File description:
** minishell
*/

#include "my.h"

void get_path(mini_t *mshell)
{
    char *get_line;

    for (int z = 0; mshell->envp[z] != NULL; z++) {
        if (mshell->envp[z][0] == 'P' && mshell->envp[z][1] == 'A'
        && mshell->envp[z][2] == 'T' && mshell->envp[z][3] == 'H') {
            get_line = my_strdup(mshell->envp[z]);
        }
    }
    mshell->path = my_str_to_word_array(get_line + 5, ':');
}

int search_path(mini_t *mshell)
{
    int x = 0;

    mshell->path[x] = my_strcat(mshell->path[x], "/");
    mshell->path[x] = my_strcat(mshell->path[x], mshell->ret_get[0]);
    while (access(mshell->path[x], X_OK) != 0) {
        x++;
        mshell->path[x] = my_strcat(mshell->path[x], "/");
        mshell->path[x] = my_strcat(mshell->path[x], mshell->ret_get[0]);
    }
    if (execve(mshell->path[x], mshell->ret_get, mshell->envp) == -1)
        my_printf("Commande Inconnue\n");
}

void clone(mini_t *mshell)
{
    mshell->pid = fork();
    if (mshell->pid == -1)
        exit(84);
    if (mshell->pid == 0)
            search_path(mshell);
    else {
        wait(&mshell->wt);
        if (mshell->wt == 139)
            my_printf("%s : Command not found\n", mshell->buff);
    }
}

void get_n(mini_t *mshell)
{
    int i = 0;

    for (; mshell->buff[i] != '\n'; i++);
    mshell->buff[i] = '\0';
}

int main(int ac, char **av, char *envp[])
{
    char *input = NULL;
    size_t size = 0;
    mini_t *mshell = malloc(sizeof(mini_t));

    mshell->envp = envp;
    while (1) {
        if (isatty(0) == 1)
            my_printf("\033[33;01m[Minishell 1]$ > \033[00m");
        if (getline(&input, &size, stdin) == -1) {
            return (0);
        }
        mshell->buff = input;
        get_n(mshell);
        mshell->ret_get = my_str_to_word_array(mshell->buff, ' ');
        if (check_command(mshell, av) == 0) {
            get_path(mshell);
            clone(mshell);
        }
    }
}