#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
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
	int					content; //nb
	struct s_list_int	*next;
}               t_list_int;

typedef struct s_arg
{
    int nb;
	t_list_int *stack_k;
}				t_arg;

typedef struct s_swap
{
	t_list *mlc;
	t_arg *arg;
	t_list_int *a;
	t_list_int *b;
	int smallst;
	int key_nbr;
	int j;
	int nb;
	int index;
	int lst_size;
	int nb_arg;
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
int	lst_add(int ptr, t_list_int **stack);

void	ft_lstadd_front_int(t_list_int **alst, t_list_int *new);
void	ft_lstclear_int(t_list_int **lst);
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
long	ft_atoi(const char *str);

void	*malloc_list(t_swap *data, int size);
void	*free_malloc_lst(t_swap *data);


int	init_lst(t_swap *data, int *tmp, t_list_int **stack);
int init_swap(t_swap *data, char **argv, int argc);
void init_tab(t_list_int *list, int *tab);
int parser_nb(t_swap *data, char **argv);
int is_sorted(t_list_int *list, int *tab, int size);

void    start_sort(t_swap *data);

void sa(t_list_int **list_a);
void ra(t_list_int **list_a);
void    rra(t_list_int **list_a);
void pa(t_list_int **a, t_list_int **b);
void sort_k(t_swap *data);
t_list_int *init_k(t_list_int *list_a);
int find_small(t_swap *data, t_list_int *num_a);
int get_index(t_list_int *list, int nb);
int get_lst_size(t_list_int *list);

void sb(t_list_int **list_b);
void rb(t_list_int **list_b);
void rrb(t_list_int **list_b);
void pb(t_list_int **a, t_list_int **b);

void ss(t_list_int **list_a, t_list_int **list_b);
void rr(t_list_int **list_a, t_list_int **list_b);
void rrr(t_list_int **list_a, t_list_int **list_b);


int find_small(t_swap *data, t_list_int *num_a);
int get_lst_size(t_list_int *list);
int get_index(t_list_int *list, int nb);

void sort_min(t_swap *data);
void sort_100(t_swap *data);
void sort_three(t_swap *data);
void sort_10(t_swap *data);
void sort_more(t_swap *data);

int find_keynbr(t_swap *data, t_list_int *num_a, int key_nbr);
int find_chunk(t_list_int *lst, int index);
int small(t_list_int *a);
int large(t_list_int *b);
void proximity_algo(t_swap *data, int index);

void sort_a(t_swap *data);
void sort_a_2(t_swap *data);
#endif