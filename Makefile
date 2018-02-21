##
## EPITECH PROJECT, 2017
## CSFML_example
## File description:
## Build the example
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c						\
			create_engine.c					\
			game_scene.c					\
			load_scenes.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	platformer

INCLUDE		=	-I include -I lib/mysfml/include

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	lib/

#The way Epitech compile the CSFML lib we need to use -lc_graph_prog as lib
LIB_FLAGS	=	-L $(LIB_DIR)mysfml -lmysfml -lc_graph_prog

LIB		=	$(LIB_DIR)mysfml/libmysfml.a

CC		=	gcc

all:		$(NAME)

$(NAME):	$(LIB) $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

$(LIB):
		$(MAKE) -C $(LIB_DIR)mysfml
		$(MAKE) clean -C $(LIB_DIR)mysfml

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re