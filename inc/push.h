#ifndef PUSH_H
# define PUSH_H

# define MALLOC -1

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

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

void	*malloc_list(t_swap *data, int size);
void	*free_malloc_lst(t_swap *data);

#endif