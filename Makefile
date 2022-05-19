LIB			= printf/libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3

SRCS		= $(wildcard *.c)

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= so_long
 
FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

all:	${NAME}
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}:	${OBJS} $(LIB)
# 			make -C ${MLXPATH}
# 		${CC} ${CFLAGS} ${INCLUDEMLX} -o ${NAME} ${OBJS} ${LMLX} ${FRAMEWORK} 

$(NAME):
		@$(MAKE) -C ${MLXPATH}
		@$(MAKE) -C ./printf
		@$(CC) $(CFLAGS) $(FRAMEWORK) $(SRCS) $(LMLX) $(LIB) -o $(NAME)


# $(LIB): #libft/
# 		make -C ./printf/

clean:
				echo "$(OBJS)"
				${RM} $(OBJS)
				make clean -C ./printf

fclean:		clean
				${RM} ${NAME}
				make  fclean -C ./printf

re:				fclean all
