##
## Makefile for rtv1 in /home/rousse_3/rendu/MUL_2013_rtv1
## 
## Made by rousse_3
## Login   <rousse_3@epitech.net>
## 
## Started on  Thu Mar 13 18:29:28 2014 rousse_3
## Last update Fri May 30 13:19:16 2014 Elliott ZWERTVAEGHER
##

CC	=	gcc

RM	=	rm -rf

DEBUG	=	0

OPTI	=	0

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I header/ -I /usr/include/
ifeq ($(DEBUG), 1)
CFLAGS	+=	-g
endif
ifeq ($(OPTI), 1)
CFLAGS	+=	-O3
endif

LDFLAGS	+=	-Lminilibx/ -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm -Llib/ -lmy_lib

NAME	=	rt

SRC	=	src/main.c				\
		src/init/my_init.c			\
		src/init/my_init_eye.c			\
		src/init/my_init_color.c		\
		src/init/my_init_scene.c		\
		src/init/my_free.c			\
		src/init/my_free_eye.c			\
		src/my_math/my_create_point.c		\
		src/my_math/my_create_vector.c		\
		src/my_math/my_op_vector.c		\
		src/my_math/my_rot_vector.c		\
		src/my_math/my_rot_point.c		\
		src/my_math/my_translate_point.c	\
		src/my_math/my_normalize.c		\
		src/calcul/my_fill_image.c		\
		src/calcul/my_figure.c			\
		src/calcul/normal.c			\
		src/calcul/my_lumo.c			\
		src/calcul/my_ombre.c			\
		src/calcul/my_rot_eye.c

SRC	+=	src/parser/my_parse.c			\
		src/parser/my_create_op.c		\
		src/parser/get_next_line.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
		@echo "##############################"
		@echo "# Creation de la pokeball... #"
ifeq ($(OPTI), 1)
		@echo "#           V 2.2            #"
endif
ifeq ($(DEBUG), 1)
		@echo "#         Mode Debug         #"
endif
		@echo "##############################"

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

dolib	:
		cd lib_src/ && make re && make clean

re	:	fclean all
