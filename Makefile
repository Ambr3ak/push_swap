NAME  = push_swap

SRCS	= 	./srcs/main.c \
			./lib_push/ft_lstadd_back.c \
			./lib_push/ft_lstadd_front.c \
			./lib_push/ft_lstclear.c \
			./lib_push/ft_lstdelone.c\
			./lib_push/ft_lstiter.c \
			./lib_push/ft_lstlast.c \
			./lib_push/ft_lstmap.c \
			./lib_push/ft_lstnew.c \
			./lib_push/ft_lstsize.c \
			./lib_push/ft_isdigit.c \
			./lib_push/ft_putchar_fd.c \
			./lib_push/ft_putstr_fd.c \
			./malloc_lst.c


OBJS= $(SRCS:.c=.o)

INC	=	-I inc

CC	=	clang

CFLAGS	=	-Wall -Werror -Wextra -g

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