#include "../inc/push.h"

void proximity_algo(t_swap *data, int index)
{
    if (index == 0)
        pb(&data->arg->num_a, &data->arg->num_b);
    else if ((get_lst_size(data->arg->num_a)) / 2 > index)
        ra(&data->arg->num_a);
    else
        rra(&data->arg->num_a);
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
        if (index == 0)
            pa(&data->arg->num_a, &data->arg->num_b);
        else if ((get_lst_size(data->arg->num_b)) / 2 > index)
            rb(&data->arg->num_b);
        else
            rrb(&data->arg->num_b);
    }
}

void sort_a(t_swap *data)
{
    int smaller;

    while (get_lst_size(data->arg->num_a) > 1)
    {
        smaller = small(data->arg->num_a);
        data->index = get_index(data->arg->num_a, smaller);
        proximity_algo(data, data->index);
    }      
}

void sort_100(t_swap *data)
{
    int key_nbr;
    t_list_int *lst;
    int IDX;
    int size;

    data->arg->stack_k = init_k(data->arg->num_a);
    sort_k(data);
    lst = data->arg->stack_k;
    size = get_lst_size(data->arg->stack_k);
    IDX = size / 4;
    while (IDX < size)
    {
        key_nbr = find_chunk(data->arg->stack_k, IDX);
        while (find_keynbr(data, data->arg->num_a, key_nbr))
        {   
            data->index = get_index(data->arg->num_a, data->key_nbr);
            proximity_algo(data, data->index);
        }
        IDX += size / 4;
    }
    sort_a(data);
    sort_a_2(data);
}
