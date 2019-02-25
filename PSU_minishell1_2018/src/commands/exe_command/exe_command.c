/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../../include/get_next_line.h"
#include "../../../include/mini_shell.h"
#include "../../../lib/my/lib.h"

int is_command_or_exec(char *dir, char *path, char **argv,
struct stat *fileStat)
{
    int access_int = 0;
    argv[0] = remove_quote(argv[0]);
    getcwd(dir, 256);
    my_strcat(dir, "/");
    my_strcat(dir, argv[0]);
    my_strcat(path, "/bin/");
    my_strcat(path, argv[0]);
    if (access(path, F_OK | X_OK) != 0) {
        access_int = 1;
        path[0] = 0;
        my_strcat(path, argv[0]);
    }
    stat(dir, fileStat);
    return (access_int);
}

void my_fork(int *command_error, char *path, char **argv, char **env)
{
    pid_t pid;

    pid = fork();
    signal(SIGINT, exe_signal_handler);
    if (pid == 0)
        *command_error = execve(path, argv, env);
    else if (pid < 0) {
        write(2, "Fork failed to create a new process.\n",
        my_strlen("Fork failed to create a new process.\n"));
    }
}

int my_wait(int *one_time, int *int_errno, char **path)
{
    int status;

    if (*one_time == 0) {
        *one_time = 1;
        *int_errno = errno;
        wait(&status);
        error_segfault(&status);
    }
    *path = malloc(sizeof(char) * 1000);
    my_memset(*path, 0, 999);
    return (status);
}

void system_command(char **argv, char **env)
{
    VAR_EXE
    CHECK_MALLOC_EXE
    access_int = is_command_or_exec(dir, path, argv, &fileStat);
    CHECK_IF_COMMAND
    CHECK_IF_DIR
    if (wrong_command == 0) {
        my_fork(&command_error, path, argv, env);
        status = my_wait(&one_time, &int_errno, &path);
    }
    error_wrong_architecture(int_errno, argv);
    if (wrong_command == 0 && command_error != 0 && int_errno != ENOEXEC) {
        DISPLAY_ERROR_PERMISSION
    }
    WRONG_COMMAND
}