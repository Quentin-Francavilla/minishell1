/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../../include/get_next_line.h"
#include "../../../include/mini_shell.h"
#include "../../../lib/my/lib.h"

char *remove_quote(char *path_cd)
{
    int i = 0;
    int a = 0;
    char *tmp = malloc(sizeof(char) * 500);
    my_memset(tmp, 0, 499);

    while (path_cd[i] != 0) {
        if (path_cd[i] != '"') {
            tmp[a] = path_cd[i];
            a++;
        }
        i++;
    }
    return (tmp);
}

int check_if_directory(char *back_dir, char **argv)
{
    struct stat fileStat;
    int is_dir = 0;
    char *tmp = malloc(sizeof(char) * 500);
    my_memset(tmp, 0, 499);

    my_strcat(tmp, back_dir);
    my_strcat(tmp, "/");
    my_strcat(tmp, argv[1]);

    stat(tmp, &fileStat);
    if (S_ISREG(fileStat.st_mode))
        is_dir = 1;

    return (is_dir);
}