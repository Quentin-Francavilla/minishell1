/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

char *parse_current_dir(char *cwd)
{
    int i = 0;
    int a = 0;
    char *result = malloc(sizeof(char) * 2000);

    if (!result)
        exit(84);
    my_memset(result, 0, 1999);

    while (cwd[i] != 0)
        i++;
    i--;
    while (cwd[i] != '/')
        i--;
    while (cwd[i] != 0) {
        result[a] = cwd[i];
        a++;
        i++;
    }
    return (result);
}