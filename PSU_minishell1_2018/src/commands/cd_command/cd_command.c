/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../../include/get_next_line.h"
#include "../../../include/mini_shell.h"
#include "../../../lib/my/lib.h"

void cd_score(t_glo *a, char *back_dir2, char *back_dir, char *path_cd)
{
    int k = 0;
    if (a->check_cd == 1) {
        k = chdir(back_dir2);
        a->check_cd = 0;
    }
    else {
        getcwd(back_dir2, 256);
        k = chdir(back_dir);
        a->check_cd = 1;
    }
    PROMPT_ERROR2
}

void cd_wave(t_glo *a, char *path_cd, char **env, char *back_dir)
{
    int k = 0;

    my_strcat(path_cd, "/home/");
    my_strcat(path_cd, my_get_env("USER", env));
    getcwd(back_dir, 256);
    k = chdir(path_cd);
    a->check_cd = 0;
}

void prompt_error_cd_normal(char **path_cd, char **back_dir, int is_reg, int k)
{
    if (k != 0) {
        if (my_strcmp(*path_cd, "/root") == 0) {
            my_putstr("/root: Permission denied.\n");
            *back_dir[0] = 0;
            my_strcat(*back_dir, "");
        }
        PROMPT_ERROR
    }
}

void cd_normal(char *back_dir, t_glo *a, char **path_cd, char **argv)
{
    int k = 0;
    int is_reg = 0;

    getcwd(back_dir, 256);
    is_reg = check_if_directory(back_dir, argv);
    a->check_cd = 0;
    *path_cd = argv[1];
    *path_cd = remove_quote(*path_cd);
    k = chdir(*path_cd);
    prompt_error_cd_normal(path_cd, &back_dir, is_reg, k);
}

void cd_command(char **argv, char **env, t_glo *a)
{
    VAR_CD
    CHECK_MALLOC_CD
    my_get_env("PATH", env);
    if (argv[2])
        my_putstr("cd: Too many arguments.\n");
    CD_SCORE
    CD_WAVE
    else
        cd_normal(back_dir, a, &path_cd, argv);
}