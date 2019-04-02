/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** task06 strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int x = 0;

    while (s1[x] == s2[x] && s1[x] && s2[x] && x < n) {
        x++;
    }
    if (s1[x] != s2[x]) {
        return (s1[x] - s2[x]);
    }
    return (0);
}
