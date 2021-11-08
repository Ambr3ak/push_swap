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

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*next;
}               t_list_int;

typedef struct s_arg
{
    int nb;
    t_list_int *num;
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

void	ft_lstadd_front_int(t_list_int **alst, t_list_int *new);
void	ft_lstclear_int(t_list_int **lst, void (*del)(int));
void	ft_lstdelone_int(t_list_int *lst, void (*del)(int));
void	ft_lstiter_int(t_list_int *lst, void (*f)(int));
t_list_int	*ft_lstlast_int(t_list_int *lst);
t_list_int *ft_lstmap_int(t_list_int *lst,
							void *(*f)(int), void (*del)(int));
t_list_int	*ft_lstnew_int(int content);
void			ft_lstadd_back_int(t_list_int **alst, t_list_int *new);
int	ft_lstsize_int(t_list_int *lst);	


int	ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_atoi(const char *str);

void	*malloc_list(t_swap *data, int size);
void	*free_malloc_lst(t_swap *data);

#endif