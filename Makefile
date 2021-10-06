NAME  = push_swap

SRCS	= 	main.c \
			./lib_push/ft_lstclear.c \
			./lib_push/ft_lstnew.c \
			./lib_push/ft_lstadd_back.c \
			./lib_push/ft_memset.c

OBJS= $(SRCS:.c=.o)

INC	=	-I inc

CC	=	clang

CFLAGS	=	-Wall -Werror -Wextra

.c.o	:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) :	${OBJS}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS)


clean	:	
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re