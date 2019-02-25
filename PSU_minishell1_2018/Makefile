##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## M
##

SRC	=	./src/main.c \
		./src/get_next_line.c \
		./src/commands/cd_command/cd_command.c \
		./src/commands/cd_command/tools_cd_command.c \
		./src/commands/exe_command/exe_command.c \
		./src/commands/exe_command/error_gestion.c \
		./src/commands/env_command.c \
		./src/commands/setenv_command.c \
		./src/tools_fct/signal_handler_fct.c \
		./src/commands/unsetenv_command.c \
		./src/tools_fct/display_msg.c \
		./src/tools_fct/parse_current_directory.c \
		./src/tools_fct/my_get_env.c \
		./src/tools_fct/get_command.c \


OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

FLAG	=	-W -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	gcc $(SRC) -o $(NAME) -L./lib/my -lmy
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#.PHONY
