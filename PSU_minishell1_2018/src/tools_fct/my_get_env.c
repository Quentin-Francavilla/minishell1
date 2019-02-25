/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

char *my_get_env(char *name, char **env)
{
    VAR_MY_GET_ENV
    my_memset(result, 0, 999);
    while (env[t]) {
        if (my_strncmp(env[t], name, 4) == 0 && check ==0) {
            check = 1;
            while (env[t][i] != '=')
                i++;
            i++;
            while (env[t][i] != 0) {
                result[a] = env[t][i];
                a++;
                i++;
            }
        }
        t++;
    }
    return (result);
}