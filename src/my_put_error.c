/*
** EPITECH PROJECT, 2019
** my_put_error
** File description:
** put_error
*/

#include <unistd.h>

void my_char_error(char c)
{
    write(2, &c, 1);
}

int my_put_error(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        my_char_error(str[count]);
        count++;
    }
    return (0);
}
