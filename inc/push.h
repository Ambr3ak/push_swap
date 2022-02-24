/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:54:04 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 15:54:07 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define ERR_ARG -1
# define ERR_PARS -2
# define ERR_DOUBLE -3
# define ERR_INT -4
# define LIST_TRIEE -5
# define ERR_MALLOC -6
# define OK 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*next;
}				t_list_int;

typedef struct s_swap
{
	t_list		*mlc;
	t_list_int	*a;
	t_list_int	*b;
	t_list_int	*k;
	int			*tab;
	int			*tmp;
	int			smallst;
	int			key_nbr;
	int			j;
	int			nb;
	int			nb_ac;
	int			index;
	int			lst_size;
	int			nb_arg;
	int			error;
}				t_swap;

/* LIB_PUSH */
t_list		*ft_lstmap(t_list *lst,
				void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list_int	*ft_lstlast_int(t_list_int *lst);
t_list_int	*ft_lstmap_int(t_list_int *lst,
				void *(*f)(int), void (*del)(int));
t_list_int	*ft_lstnew_int(int content);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstadd_front_int(t_list_int **alst, t_list_int *new);
void		ft_lstclear_int(t_list_int **lst);
void		ft_lstadd_back_int(t_list_int **alst, t_list_int *new);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			lst_add(int ptr, t_list_int **stack);
int			ft_isdigit(int c);
long		ft_atoi(const char *str);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const char *s);

/* SRCS */
void		*malloc_list(t_swap *data, int size);
void		*free_malloc_lst(t_swap *data);
void		sort_k(t_swap *data);
void		start_sort(t_swap *data);

int			init_lst(t_swap *data, int *tmp, t_list_int **stack);
int			init_swap(t_swap *data, char **argv, int argc);
int			parser_nb(t_swap *data, char **argv);
int			is_sorted(t_list_int *list, int *tab, int size);
int			find_small(t_swap *data, t_list_int *num_a);
int			get_index(t_list_int *list, int nb);
int			get_lst_size(t_list_int *list);
int			find_keynbr(t_swap *data, t_list_int *num_a, int key_nbr);
int			find_chunk(t_list_int *lst, int index);
int			small(t_list_int *a);
int			large(t_list_int *b);

t_list_int	*init_k(t_list_int *list_a);

/* INSTRUCTIONS */
void		sa(t_list_int **list_a);
void		ra(t_list_int **list_a);
void		rra(t_list_int **list_a);
void		pa(t_list_int **a, t_list_int **b);

void		sb(t_list_int **list_b);
void		rb(t_list_int **list_b);
void		rrb(t_list_int **list_b);
void		pb(t_list_int **a, t_list_int **b);

void		ss(t_list_int **list_a, t_list_int **list_b);
void		rr(t_list_int **list_a, t_list_int **list_b);
void		rrr(t_list_int **list_a, t_list_int **list_b);

/* ALGOS */
void		sort_min(t_swap *data);
void		sort_100(t_swap *data);
void		sort_three(t_swap *data);
void		sort_10(t_swap *data);
void		sort_more(t_swap *data);
void		proximity_algo(t_swap *data, int index);
void		sort_a(t_swap *data);
void		sort_a_2(t_swap *data);
#endif
