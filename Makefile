CFLAGS = -Wall -Wextra -Werror
GCC     = gcc -g -O0
SRCS	= ${addprefix sources/, push_swap.c push_swap_utils.c operations.c push.c algo.c radix_conversion.c hardcode.c}
OBJ    = ${SRCS:.c=.o}
NAME   = push_swap

all: 		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	${OBJ}
			@make -C ./libft/
			${GCC} ${CFLAGS} -I ./libft/ ${OBJ} -o ${NAME} -L ./libft/ -lft

clean:
			${RM} ${OBJ}
			@make -C ./libft/ clean

fclean: 	clean
			${RM} ${NAME}
		
re:			fclean all

.PHONY: all clean fclean
