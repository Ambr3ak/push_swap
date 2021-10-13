#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //a enlever
# define ERR_MALLOC -1
# define ERR_ARG -2
# define ERR_LIST -3
# define OK 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}               t_list;

typedef struct s_arg
{
    int nb;
    t_list *num;
}				t_arg;

typedef struct s_swap
{
	t_list *mlc;
	t_arg *arg;
	int error;
}				t_swap;

t_list			*ft_lstmap(t_list *lst,
							void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int	ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);


void	*malloc_list(t_swap *data, int size);
void	*free_malloc_lst(t_swap *data);

#endif