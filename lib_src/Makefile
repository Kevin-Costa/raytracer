##
## Makefile for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
## 
## Made by rousse_3
## Login   <rousse_3@epitech.net>
## 
## Started on  Thu Mar  6 16:33:47 2014 rousse_3
## Last update Thu Mar  6 16:33:48 2014 rousse_3
##

CC	=	gcc

RM	=	rm -rf

NAME	=	libmy_lib.a

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I src/

HEADER	=	lib.h

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_putnbr.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_strcat.c	\
		my_str_cmp.c	\
		my_str_cpy.c	\
		xmalloc.c	\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		cp $(NAME) ../lib/
		cp $(HEADER) ../header/

clean	:
		$(RM) $(OBJ) $(NAME)

fclean	:	clean
		$(RM) ../header/$(HEADER) ../lib/$(NAME)

re	:	fclean	all