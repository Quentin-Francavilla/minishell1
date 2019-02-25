/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

void env_command(char **argv, char **env, t_glo *a)
{
    int i = 0;
    int z = 0;

    if (argv[1]) {
        write(2, "Too many arguments.\n", 20);
        return;
    }
    while (env[i]) {
        my_putstr(env[i]);
        write(1, "\n", 1);
        i++;
    }
}