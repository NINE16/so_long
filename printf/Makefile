SRCS		= ft_printf.c ft_print_str.c ft_print_int.c ft_itoa.c ft_print_hex.c ft_putchar_fd.c ft_print_unsigned_int.c ft_print_ptr.c ft_print_char.c 

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a 

LIBFT 		= ./libft/

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C $(LIBFT)
			cp ./libft/libft.a $(NAME)
			ar rc ${NAME} ${OBJS}
			# ranlib ${NAME]}

all:		${NAME}

clean:
			echo "$(OBJS)"
			$(MAKE) clean -C $(LIBFT)
			${RM} $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT)
			${RM} ${NAME}

re:				fclean all