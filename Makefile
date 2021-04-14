##
## EPITECH PROJECT, 2021
## malloc
## File description:
## makefile
##

CPPFLAGS	=	-I include/ -Wall -Wextra -Werror
LDFLAGS		=	-lm

SRC			=	src/internal/find_block.c	\
				src/internal/get_block.c	\
				src/internal/round_to_pwr.c	\
				src/public/calloc.c			\
				src/public/free.c			\
				src/public/malloc.c			\
				src/public/realloc.c		\
				src/public/reallocarray.c

SRC_OBJ		= $(SRC:.c=.o)

NAME		= libmy_malloc.so

all: CFLAGS += -fPIC
all: $(SRC_OBJ)
	$(CC) $(SRC_OBJ) -shared -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(SRC_OBJ)
	$(RM) $(TEST_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) unit_tests

re: fclean all