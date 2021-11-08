#include "../inc/push.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstadd_front_int(t_list_int **alst, t_list_int *new)
{
	new->next = *alst;
	*alst = new;
}