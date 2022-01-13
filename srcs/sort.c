#include "../inc/push.h"


int find_keynbr(t_swap *data, t_list_int *num_a, int key_nbr)
{
    t_list_int *lst;

    lst = num_a;
    data->key_nbr = 0;
    while (lst)
    {
        if (lst->content <= key_nbr)
        {
            data->key_nbr = lst->content;
            return (data->key_nbr);
        }
        else
            lst = lst->next;
    }
    return (0);
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
    //while (data->arg->num_b)
   //     pa(&data->arg->num_a, &data->arg->num_b);
}

int find_chunk(t_list_int *lst, int index)
{
    t_list_int *list;
    int i;

    list = lst;
    i = 1 ;
    while (i != index)
    {
        list = list->next;
        i++;
    }
    return (list->content);
}

int small(t_list_int *a)
{
   t_list_int *a_tmp;
    int small;

    a_tmp = a;
    small = a_tmp->content;
    while (a_tmp)
    {
        if (a_tmp->content < small)
            small = a_tmp->content;
        a_tmp = a_tmp->next;
    }
   return (small);
}

int large(t_list_int *b)
{
    t_list_int *b_tmp;
    int large;

    b_tmp = b;
    large = b_tmp->content;
    while (b_tmp)
    {
        if (b_tmp->content > large)
            large = b_tmp->content;
        b_tmp = b_tmp->next;
    }
   return (large);
}

int    rounded(float i)
{
    int    j;

    j = (int) i;
    if ((i - j) >= 0.5)
        return (j + 1);
    else
        return (j);
}

void sort_a_2(t_swap *data)
{
    int count;
    t_list_int *tmp_b;
    int index;
    int lrg;

    count = 0;
    while (data->arg->num_b)
    {
        tmp_b = data->arg->num_b->next;
        lrg = large(data->arg->num_b); 
        if (data->arg->num_b->content != lrg && tmp_b->content == lrg)
            sb(&data->arg->num_b);
        index = get_index(data->arg->num_b, lrg);
        if (data->arg->num_b->content == lrg)
            pa(&data->arg->num_a, &data->arg->num_b);
        if (get_lst_size(data->arg->num_b) / 2 > index)
            rb(&data->arg->num_b);
        else
            rrb(&data->arg->num_b);
    }
}

void sort_a(t_swap *data)
{
    int smaller;
    int index;

    while (get_lst_size(data->arg->num_a) > 1)
    {
        smaller = small(data->arg->num_a);
        index = get_index(data->arg->num_a, smaller);
        if (data->arg->num_a->content == smaller)
            pb(&data->arg->num_a, &data->arg->num_b);
        if (get_lst_size(data->arg->num_a) / 2 > index)
            ra(&data->arg->num_a);
        else
            rra(&data->arg->num_a);
    }      
    sort_a_2(data);
}

void sort_100(t_swap *data)
{
    int key_nbr;
    t_list_int *lst;
    int i;
    int index;
    int size;

    i = 1;
    data->arg->stack_k = init_k(data->arg->num_a);
    sort_k(data);
    lst = data->arg->stack_k;
    size = get_lst_size(data->arg->stack_k);
    index = size / 4;
    while (index < size)
    {
        key_nbr = find_chunk(data->arg->stack_k, index);
        while (find_keynbr(data, data->arg->num_a, key_nbr))
        {   
            data->ind_sml = get_index(data->arg->num_a, data->key_nbr);
            if (data->arg->num_a->content == data->key_nbr)
                pb(&data->arg->num_a, &data->arg->num_b);
            if (get_lst_size(data->arg->num_a) / 2 > data->ind_sml)
                ra(&data->arg->num_a);
            else
                rra(&data->arg->num_a);
        }
        index += size / 4;
    }
    sort_a(data);
    //sort_five(data);
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