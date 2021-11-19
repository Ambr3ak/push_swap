#include "../inc/push.h"

void sa(t_list_int **list_a)
{
    t_list_int *tmp;
    t_list_int *list;

    list = *list_a;
    if (list && list->next)
    {
        tmp = list->next;
        list->next = tmp->next;
	    ft_lstadd_front_int(list_a, tmp);
    }
}

void ra(t_list_int **list_a)
{
	t_list_int *tmp;
	t_list_int *list;

    list = *list_a;
    if (list && list->next)
    {
	    tmp = list;
        list = list->next;
	    ft_lstadd_back_int(list_a, tmp);
        tmp->next = NULL;
        *list_a = list;
    }
}

void    rra(t_list_int **list_a)
{
	t_list_int *tmp;
	t_list_int *list;

    list = *list_a;
    if (list && list->next)
    {
        tmp = list;
        while (tmp->next->next)
            tmp = tmp->next;
        ft_lstadd_front_int(list_a, tmp->next);
        tmp->next = NULL;
    }
}

void pa(t_list_int **a, t_list_int **b)
{
    t_list_int *tmp;
    t_list_int *list_b;

    list_b = *b;
    if (list_b)
    {
	    tmp = list_b;
	    list_b = list_b->next;
	    ft_lstadd_front_int(a, tmp);
        *b = list_b;
    }
}