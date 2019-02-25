/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

int search_egal_unsetenv(int *one_egal, char **env, int u, int j)
{
    int egal = 0;

    while (env[u][j] != 0) {
        if (env[u][j] == '=' && *one_egal == 0) {
            *one_egal = 1;
            egal = j;
        }
        j++;
    }
    return (egal);
}

void unsetenv_command(char **argv, char **env, t_glo *a)
{
    VAR_UNSETENV
    CHECK_ARGS_UNSETENV
    while (argv[z]) {
        u = 0;
        while (env[u]) {
            egal = search_egal_unsetenv(&one_egal, env, u, j);
            if (my_strncmp(argv[z], env[u], egal) == 0)
                check = 1;
            one_egal = 0;
            if (check == 1)
                env[u] = env[u + 1];
            u++;
            j = 0;}
        check = 0;
        one_egal = 0;
        one_time = 0;
        z++;}
    env[u + 1] = NULL;
}