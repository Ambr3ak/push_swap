#include "../inc/push.h"

void sort_more(t_swap *data)
{
    int key_nbr;
    t_list_int *lst;
    int IDX;
    int size;

    data->arg->stack_k = init_k(data->a);
    sort_k(data);
    lst = data->arg->stack_k;
    size = get_lst_size(data->arg->stack_k);
    IDX = size / 11;
    while (IDX < size)
    {
        key_nbr = find_chunk(data->arg->stack_k, IDX);
        while (find_keynbr(data, data->a, key_nbr))
        {   
            data->index = get_index(data->a, data->key_nbr);
            proximity_algo(data, data->index);
        }
        IDX += size / 11;
    }
    sort_a(data);
    sort_a_2(data);
}