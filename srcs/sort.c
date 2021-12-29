#include "../inc/push.h"

int find_small(t_swap *data, int *tab, int nb)
{
    int i;
    
    i = 0;
    while (tab[i] && tab[i] < nb)
        i++;
    if (i == 0)
        return (-1);
    return (data->i_small = i - 1);
}

int find_large(t_swap *data, int *tab, int nb)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (tab[j])
        j++;
    while (tab[i] && tab[i] < nb)
        i++;
    if (i == j)
        return (-1);
    return (data->i_large = i);
}

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
    int *tab;
    int stack_a;

    tab = malloc_list(data, sizeof(int) * (5));
    stack_a = 5;
    while (stack_a != 3)
    



    /*pb(&data->arg->num_a, &data->arg->num_b);
    pb(&data->arg->num_a, &data->arg->num_b);
    sort_three(data);
    init_tab(data->arg->num_a, tab);
    find_small(data, tab, data->arg->num_b->content);
    find_large(data, tab, data->arg->num_b->content);
    printf("small %d\n", data->i_small);
    printf("large %d\n", data->i_large);
    pa(&data->arg->num_a, &data->arg->num_b);*/
   
    while (data->arg->num_a)
	{
		printf("%d -> ", (int)data->arg->num_a->content);
        data->arg->num_a = data->arg->num_a->next;
	}
}

void    start_sort(t_swap *data)
{
    if (data->arg->nb - 1 == 3)
        sort_three(data);
    if (data->arg->nb - 1 == 5)
        sort_five(data);
    while (data->arg->num_a)
	{
		printf("%d -> ", (int)data->arg->num_a->content);
        data->arg->num_a = data->arg->num_a->next;
	}
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
    j = 0;
    while (tab[i])
    {
        j = i + 1;
        while (tab[i] < tab[j] && j < size)
            j++;
        if (j != size)
            return (0);
        i++;
    }
    return (1);
}