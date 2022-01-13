#include "../inc/push.h"

void sort_three(t_swap *data)
{
    int *tab;

    tab = malloc_list(data, sizeof(int) * (3));
    while (!is_sorted(data->arg->num_a, tab, 3))
    {
        if (tab[0] > tab[1])
            sa(&data->arg->num_a);
        else if (tab[0] > tab[1] && tab[2] > tab[1])
            ra(&data->arg->num_a);
        else if (tab[0] < tab[1])
            rra(&data->arg->num_a);    
    }
}

void sort_five(t_swap *data)
{
    while (get_lst_size(data->arg->num_a) != 3)
    {
        data->index = get_index(data->arg->num_a, find_small(data, data->arg->num_a));
        if (get_lst_size(data->arg->num_a) / 2 > data->index)
            ra(&data->arg->num_a);
        else
            rra(&data->arg->num_a);
        if (data->arg->num_a->content == data->smallst)
            pb(&data->arg->num_a, &data->arg->num_b);
    }
    sort_three(data);
}


void    start_sort(t_swap *data)
{
    if (data->lst_size == 3)
        sort_three(data);
    else if (data->lst_size < 10)
        sort_five(data);
    else if (data->lst_size <= 100)
        sort_100(data);
    /*printf("\nB\n");
    while (data->arg->num_b)
	{
		printf("%d -> ", (int)data->arg->num_b->content);
        data->arg->num_b = data->arg->num_b->next;
	}
    printf("\nK\n");
    while (data->arg->stack_k)
	{
		printf("%d -> ", (int)data->arg->stack_k->content);
        data->arg->stack_k = data->arg->stack_k->next;
	}
    printf("\nA\n");
    while (data->arg->num_a)
	{
		printf("%d -> ", (int)data->arg->num_a->content);
        data->arg->num_a = data->arg->num_a->next;
	}*/
}

int is_sorted(t_list_int *list, int *tab, int size)
{
    int i;
    int j;
    t_list_int *lst;

    lst = list;
    i = 0;
	while (lst)
	{
		tab[i] = (int)lst->content;
        lst = lst->next;
        i++;
	}
    i = 0;
    j = i + 1;
    while (i < size)
    {
        j = i + 1;
        while (j < size && tab[i] < tab[j])
            j++;
        if (j != size)
            return (0);
        i++;
    }
    return (1);
}