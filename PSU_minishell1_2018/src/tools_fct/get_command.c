/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

char *get_command(char *input)
{
    char *result = malloc(sizeof(char) * 2000);
    int i = 0;
    int a = 0;

    if (!result)
        exit(84);

    my_memset(result, 0, 1999);
    if (input[0] == '\0') {
        result[0] = 0;
        return (result);
    }
    while (!(INTERVALLE))
        i++;
    while (INTERVALLE) {
        result[a] = input[i];
        i++;
        a++;
    }
    return (result);
}