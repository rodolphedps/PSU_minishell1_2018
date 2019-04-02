/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MSHELL_H
#define MSHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

typedef struct mini_s {
    char **path;
    char **envp;
    char **ret_get;
    char *buff;
    char *get;
    int wt;
    pid_t pid;
}              mini_t;

char *my_strdup(char *str);
char **my_str_to_word_array(char *str, char delim);
char *my_strcat(char *src, char *dest);
int my_strlen(char const *str);
int my_printf(char *s, ...);
void leave(mini_t *mshell);
int my_strncmp(char const *s1, char const *s2, int n);
int check_command(mini_t *mshell, char **av);

#endif /* !MSHELL_H */