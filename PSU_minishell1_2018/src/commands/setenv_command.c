/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

void where_is_egal(char **env, int i, int *z, int *egal_pos)
{
    while (env[i][*z] != 0) {
        if (env[i][*z] == '=' && env[i][*z - 1] != '_')
            *egal_pos = *z - 1;
        *z += 1;
    }
}

void replace_var_already_exist(int i, int size_array, char **env,
char **tmp_2)
{
    if (i + 1 != size_array) {
        *tmp_2 = env[i + 1];
        env[i + 1] = malloc(sizeof(char) * 500);
        my_memset(env[i + 1], 0, 499);
        my_strcat(env[i + 1], *tmp_2);
    }
}

void create_new_var(int i, char **env, int size_array, char **argv)
{
    env[size_array] = argv[1];
    my_strcat(env[size_array], "=");
    if (argv[2])
        my_strcat(env[i], argv[2]);
    env[size_array + 1] = NULL;
}

void count_size_env(int *size_array, char **env)
{
    while (env[*size_array]) {
        *size_array += 1;
    }
}

void setenv_command(char **argv, char **env, t_glo *a)
{
    VAR_SETENV
    CHECK_MALLOC_SETENV
    CHECK_ARGS_SETENV
    count_size_env(&size_array, env);
    while (env[i]) {
        where_is_egal(env, i, &z, &egal_pos);
        if (my_strncmp(argv[1], env[i], egal_pos + 1) == 0)
            a->var_already_exist = 1;
        if (a->var_already_exist == 1 && only_one_time == 0) {
            only_one_time = 1;
            env[i][egal_pos + 2] = 0;
            replace_var_already_exist(i, size_array, env, &tmp_2);
            if (argv[2])
                my_strcat(env[i], argv[2]);
        }
        i++;
        z = 0;
    }
    if (a->var_already_exist == 0)
        create_new_var(i, env, size_array, argv);
}