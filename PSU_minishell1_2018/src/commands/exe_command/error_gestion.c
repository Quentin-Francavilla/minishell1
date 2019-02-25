/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../../include/get_next_line.h"
#include "../../../include/mini_shell.h"
#include "../../../lib/my/lib.h"

void error_segfault(int *status)
{
    if (WTERMSIG(*status) == SIGSEGV) {
        DISPLAY_ERROR_SEGFAULT
    }
    if (WTERMSIG(*status) == 8)
        my_putstr("Floating exception (core dumped)\n");
}

void error_wrong_architecture(int int_errno, char **argv)
{
    if (int_errno == ENOEXEC) {
        my_putstr(argv[0]);
        my_putstr(": Exec format error. Wrong Architecture.\n");
    }
}