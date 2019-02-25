/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

void display_message(void)
{
    char cwd[256];
    char *result = malloc(sizeof(char) * 2000);
    if (!cwd || !result)
        return;
    my_memset(cwd, 0, 255);
    my_memset(result, 0, 1999);
    write(0, "~", 1);
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        result = parse_current_dir(cwd);
        write(0, result, my_strlen(result));
    }
    else {
        perror("getcwd() error");
        return;
    }
    write(0, " \033[1;35m(╯°□°）╯\033[0m$ ",
    my_strlen(" \033[1;35m(╯°□°）╯\033[0m$ "));
}