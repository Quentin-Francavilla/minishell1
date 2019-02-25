/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MS_H
#define MS_H

#include "../lib/my/lib.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/sysmacros.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct s_la
{
    char *value;
    struct s_la *next;
    struct s_la *tmp_a;
} t_la;

typedef struct s_lb
{
    char *value;
    struct s_lb *next;
    struct s_lb *tmp_a;
} t_lb;

typedef struct s_arg
{
    char *arg;
    int arg_next;
} t_arg;

typedef struct s_flags
{

} t_flags;

typedef struct s_glo
{
    int count_array;
    int check_cd;
    char **array_last_str;
    int var_already_exist;
    int malloc_check;
    t_flags      *_f;
} t_glo;

void my_ls(char *);
char *get_next_line(int fd);
char **my_str_to_wordtab(char *str);
void display_message(void);
char *my_get_env(char *name, char **env);
void cd_command(char **argv, char **env, t_glo *a);
void exe_signal_handler(int signal_int);
void signal_handler(int signal_int);
void system_command(char **argv, char **env);
char *parse_current_dir(char *cwd);
void env_command(char **argv, char **env, t_glo *a);
void setenv_command(char **argv, char **env, t_glo *a);
void unsetenv_command(char **argv, char **env, t_glo *a);
char *get_command(char *input);

//main

#define VAR_MAIN t_glo *a = malloc(sizeof(t_glo)); \
a->var_already_exist = 0; \
a->check_cd = 0; \
a->count_array = 0; \
a->malloc_check = 0; \
a->malloc_check = 0; \
char *input; \
char *command = malloc(sizeof(char) * 1000); \
char **argv = malloc(sizeof(char) * 1000); \
int y = 0; \

#define EXITS if (my_strcmp(command, "exit") == 0) \
return (0); \
else if (argv[1] && my_strcmp(command, "exit") == 0 \
&& my_strcmp(argv[1], "43") == 0) { \
my_putstr("exit\n"); \
return (43);} \

#define CD else if (my_strcmp(command, "cd") == 0) \
cd_command(argv, env, a); \

#define ENV else if (my_strcmp(command, "env") == 0) \
env_command(argv, env, a); \

#define SETENV else if (my_strcmp(command, "setenv") == 0) \
setenv_command(argv, env, a); \

#define UNSETENV else if (my_strcmp(command, "unsetenv") == 0) \
unsetenv_command(argv, env, a); \

#define OTHERS_COMMANDS else if (argv[0]) \
system_command(argv, env); \

#define CHECK_ERROR_MALLOC_MAIN if (!command || !argv) \
return (84); \
my_memset(command, 0, 999); \


//mygetenv
#define VAR_MY_GET_ENV int t = 0; \
int i = 0; \
int a = 0; \
int check = 0; \
char *result = malloc(sizeof(char) * 1000); \


//unsetenv

#define VAR_UNSETENV int egal = 0; \
int check = 0; \
int j = 0; \
int u = 0; \
int one_time = 0; \
int one_egal = 0; \
int z = 1; \

#define CHECK_ARGS_UNSETENV if (!argv[1]) { \
my_putstr("unsetenv: Too few arguments.\n"); \
return; \
} \

//setenv

#define VAR_SETENV int i = 0; \
int z = 0; \
int egal_pos = 0; \
int only_one_time = 0; \
int total_len = 0; \
int size_array = 0; \
char *tmp_2 = malloc(sizeof(char) * 500); \
a->var_already_exist = 0; \

#define CHECK_MALLOC_SETENV if (!tmp_2) \
return; \
my_memset(tmp_2, 0, 499); \

#define CHECK_ARGS_SETENV if (!argv[1]) { \
write(2, "Wrong arguments.\n", 17); \
return; \
} \

#define PROMPT_ERROR  else { \
*back_dir[0] = 0; \
my_strcat(*back_dir, ""); \
if (is_reg == 1) { \
my_putstr(*path_cd); \
my_putstr(": Not a directory.\n"); \
} \
else { \
my_putstr(*path_cd); \
my_putstr(": No such file or directory.\n"); \
} \
} \

#define PROMPT_ERROR2 if (k != 0) { \
if (my_strcmp(path_cd, "/root") == 0) { \
my_putstr("/root: Permission denied.\n"); \
back_dir[0] = 0; \
my_strcat(back_dir, ""); \
} \
else \
my_putstr(": No such file or directory.\n"); \
} \

//CD
int check_if_directory(char *back_dir, char **argv);
char *remove_quote(char *path_cd);
#define VAR_CD int k = 0; \
static char back_dir[256] = ""; \
static char back_dir2[256] = ""; \
char *path_cd = malloc(sizeof(char) * 1000);  \

#define CHECK_MALLOC_CD if (!path_cd) \
return; \
my_memset(path_cd, 0, 999); \

#define CD_SCORE else if (argv[1] && argv[1][0] == '-') \
cd_score(a, back_dir2, back_dir, path_cd); \

#define CD_WAVE else if (!argv[1] || argv[1][0] == '~') \
cd_wave(a, path_cd, env, back_dir); \

//EXE
#define VAR_EXE int t = 0; \
int g = 0; \
int status; \
pid_t pid; \
int access_int = 0; \
char *path = malloc(sizeof(char) * 1000); \
int wrong_command = 0; \
char *dir_parsed = malloc(sizeof(char) * 1000); \
int command_error = 0; \
struct stat fileStat; \
char dir[256]; \
int z = 1; \
int is_dir = 0; \
int one_time = 0; \
int int_errno = 0; \

#define CHECK_MALLOC_EXE if (!path || !dir || !dir_parsed) \
return; \
my_memset(path, 0, 999); \
my_memset(dir_parsed, 0, 999); \
my_memset(dir, 0, 255); \

#define CHECK_IF_COMMAND if (!(fileStat.st_mode & S_IXUSR) \
&& !(S_ISREG(fileStat.st_mode)) \
&& access_int == 1) \
wrong_command = 1; \

#define CHECK_IF_DIR if (S_ISDIR(fileStat.st_mode)) \
is_dir = 1; \

#define WRONG_COMMAND if (wrong_command != 0) { \
write(2, argv[0], my_strlen(argv[0])); \
write(2, ": Command not found.\n", 21); \
} \

void error_wrong_architecture(int int_errno, char **argv);
void error_segfault(int *status);

//error

#define DISPLAY_ERROR_SEGFAULT if (WCOREDUMP(*status)) \
my_putstr("Segmentation fault (core dumped)\n"); \
else \
my_putstr("Segmentation fault\n"); \

#define DISPLAY_ERROR_PERMISSION if (is_dir == 1) \
my_putstr(argv[0]); \
else { \
dir_parsed = argv[0]; \
my_putstr(dir_parsed); \
} \
my_putstr(": Permission denied.\n"); \




#define INTERVALLE input[i] >= 33 && input[i] <= 125

#endif