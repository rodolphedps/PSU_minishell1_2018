##
## EPITECH PROJECT, 2019
## Makefile minishell1
## File description:
## Makefile
##

NAME	=	mysh

SRC	=	src/main.c	\
		src/my_strcat.c	\
		src/my_strdup.c	\
		src/yo.c	\
		src/my_strncmp.c	\
		src/following.c	\
		src/set_unsetenv.c	\
		print/functions.c	\
		print/functions2.c	\
		print/functions3.c	\
		print/my_printf.c	\
		print/my_put_nbr_unsigned.c	\
		print/my_put_nbr.c	\
		print/my_putchar.c	\
		print/my_putstr.c	\
		print/my_strcpy.c	\
		print/my_strlen.c	\

CFLAGS	=	-I ./include

BUGFLAGS	=	-I ./include -g3

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
