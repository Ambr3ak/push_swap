NAME  = push_swap

SRCS	= 	./srcs/main.c \
			./srcs/init_list.c \
			./srcs/instructions_a.c \
			./srcs/instructions_b.c \
			./srcs/instructions_rs.c \
			./srcs/parser.c \
			./srcs/sort.c \
			./srcs/sort_k.c \
			./srcs/utils.c \
			./srcs/algo_100.c \
			./srcs/algo_10.c \
			./srcs/sort_500.c \
			./srcs/algo_utils.c \
			./lib_push/ft_lstadd_back.c \
			./lib_push/ft_lstadd_front.c \
			./lib_push/ft_lstclear.c \
			./lib_push/ft_lstlast.c \
			./lib_push/ft_lstnew.c \
			./lib_push/ft_isdigit.c \
			./lib_push/ft_putchar_fd.c \
			./lib_push/ft_atoi.c \
			./lib_push/ft_putstr_fd.c \
			./lib_push/ft_memset.c \
			./lib_push/ft_strlen.c \
			./srcs/malloc_lst.c



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