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

int find_small(t_swap *data, t_list_int *num_a)
{
    t_list_int *lst;
    t_list_int *lst_2;

    lst = num_a;
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
        data->ind_sml = get_index(data->arg->num_a, find_small(data, data->arg->num_a));
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

int is_key_nb(t_list_int *stack_a, int key_nbr)
{
    while (stack_a)
    {
        if (stack_a->content <= key_nbr)
            return (1);
        stack_a = stack_a->next;
        return (0);
    }
    return (0); 
}

t_list_int *init_k(t_list_int *list_a)
{
    t_list_int *lst;
    t_list_int *tmp_k;
    

    lst = list_a;
    tmp_k = NULL;
    while (lst)
    {
        lst_add(lst->content, &tmp_k);
        lst = lst->next;
    }
    return (tmp_k);
}

void sort_100(t_swap *data)
{
    int key_nbr;
    t_list_int *lst;
    int i;
    int j;

    i = 0;
    j = 1;
    data->arg->stack_k = init_k(data->arg->num_a);
    sort_k(data);
    lst = data->arg->stack_k;
    key_nbr = get_lst_size(data->arg->stack_k) / 4 * j;
    while (key_nbr <= get_lst_size(data->arg->stack_k) / 4 * 3)
    {
        while (i != key_nbr)
        {
            lst = lst->next;
            i++;
        }
        key_nbr = lst->content;
        while (find_small(data, data->arg->num_a) <= key_nbr)
        {   
            data->ind_sml = get_index(data->arg->num_a, find_small(data, data->arg->num_a));
            if (get_lst_size(data->arg->num_a) / 2 > data->ind_sml)
                ra(&data->arg->num_a);
            else
                rra(&data->arg->num_a);
            if (data->arg->num_a->content == data->smallst)
                pb(&data->arg->num_a, &data->arg->num_b);
        }
        j++;
        key_nbr = get_lst_size(data->arg->stack_k) / 4 * j;
    }
    sort_five(data);
}

void    start_sort(t_swap *data)
{
    if (data->lst_size == 3)
        sort_three(data);
    else if (data->lst_size < 10)
        sort_five(data);
    else if (data->lst_size <= 100)
        sort_100(data);
    printf("\nB\n");
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
    j = i + 1;
    while (j < size && tab[i] < tab[j])
        j++;
    if (j != size)
        return (0);
    return (1);
}