/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/get_next_line.h"
#include "../../include/mini_shell.h"
#include "../../lib/my/lib.h"

void exe_signal_handler(int signal_int)
{
    if (signal_int == SIGINT) {
        write(1, "\n", 1);
        signal(SIGINT, exe_signal_handler);
    }
}

void signal_handler(int signal_int)
{
    if (signal_int == SIGINT) {
        write(1, "\n", 1);
        display_message();
        signal(SIGINT, signal_handler);
    }
}