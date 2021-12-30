#include "../inc/push.h"

int get_lst_size(t_list_int *list)
{
    t_list_int *lst;
    int size;

    size = 0;
    lst = list;
    while (lst)
    {
        lst = lst->next;
        size++;
    }
    return (size);
}

int find_small(t_swap *data)
{
    t_list_int *lst;
    t_list_int *lst_2;

    lst = data->arg->num_a;
    lst_2 = lst->next;
    data->smallst = lst->content;
    while (lst)
    {
        if (lst_2->content < lst->content)
        {
            data->smallst = lst_2->content;
            lst = lst->next;
        }
        else
        {
            lst_2 = lst_2->next;
            if (!lst_2)
                return (data->smallst);
        }
    }
    return (data->smallst);
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

int get_index(t_list_int *list, int nb)
{
    t_list_int *lst;
    int i;

    lst = list;
    i = 0;
    while (lst->content != nb)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

void sort_five(t_swap *data)
{
    while (get_lst_size(data->arg->num_a) != 3)
    {
        data->ind_sml = get_index(data->arg->num_a, find_small(data));
        if (get_lst_size(data->arg->num_a) / 2 > data->ind_sml)
            ra(&data->arg->num_a);
        else
            rra(&data->arg->num_a);
        if (data->arg->num_a->content == data->smallst)
            pb(&data->arg->num_a, &data->arg->num_b);
    }
    sort_three(data);
    while (data->arg->num_b)
        pa(&data->arg->num_a, &data->arg->num_b);
}

void    start_sort(t_swap *data)
{
    if (data->lst_size == 3)
        sort_three(data);
    if (data->lst_size == 5)
        sort_five(data);
    printf("\nA\n");
    while (data->arg->num_a)
	{
		printf("%d -> ", (int)data->arg->num_a->content);
        data->arg->num_a = data->arg->num_a->next;
	}
    printf("\nB\n");
    while (data->arg->num_b)
	{
		printf("%d -> ", (int)data->arg->num_b->content);
        data->arg->num_b = data->arg->num_b->next;
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