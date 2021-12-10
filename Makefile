CFLAGS = -Wall -Wextra -Werror
GCC     = gcc -g -O0
SRCS	= push_swap.c push_swap_utils.c operations.c push.c algo.c
OBJ    = ${SRCS:.c=.o}
NAME   = push_swap

all: 		${NAME}
			@make -C ./libft/

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	${OBJ}
			${GCC} ${CFLAGS} -I ./libft/ ${OBJ} -o ${NAME} -L ./libft/ -lft

clean:
			${RM} ${OBJ}
			@make -C ./libft/ clean

fclean: 	clean
			${RM} ${NAME}

.PHONY: all clean fclean