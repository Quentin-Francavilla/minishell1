/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../include/get_next_line.h"
#include "../include/mini_shell.h"
#include "../lib/my/lib.h"

int main(int ac, char **av, char **env)
{
    VAR_MAIN
    CHECK_ERROR_MALLOC_MAIN
    while (1) {
        signal(SIGINT, signal_handler);
        display_message();
        input = get_next_line(0);
        if (input == NULL) {
            write(0, "\n", 1);
            return (0);}
        argv = my_str_to_wordtab(input);
        command = get_command(input);
        EXITS
        CD
        ENV
        SETENV
        UNSETENV
        OTHERS_COMMANDS}
    return (0);
}