#include "../inc/push.h"

void sb(t_list_int **list_b)
{
    t_list_int *tmp;
    t_list_int *list;

    list = *list_b;
    if (list && list->next)
    {
        tmp = list->next;
        list->next = tmp->next;
	    ft_lstadd_front_int(list_b, tmp);
    }
}

void rb(t_list_int **list_b)
{
	t_list_int *tmp;
	t_list_int *list;

    list = *list_b;
    if (list && list->next)
    {
	    tmp = list;
        list = list->next;
	    ft_lstadd_back_int(list_b, tmp);
        tmp->next = NULL;
        *list_b = list;
    }
}

void    rrb(t_list_int **list_b)
{
	t_list_int *tmp;
	t_list_int *list;

    list = *list_b;
    if (list && list->next)
    {
        tmp = list;
        while (tmp->next->next)
            tmp = tmp->next;
        ft_lstadd_front_int(list_b, tmp->next);
        tmp->next = NULL;
    }
}

void pb(t_list_int **a, t_list_int **b)
{
    t_list_int *tmp;
    t_list_int *list_a;

    list_a = *a;
    if (list_a)
    {
	    tmp = list_a;
	    list_a = list_a->next;
	    ft_lstadd_front_int(b, tmp);
        *a = list_a;
        printf("pb\n");
    }
}