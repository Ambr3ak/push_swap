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
            return (1);
        }
        else
            lst = lst->next;
    }
    return (0);
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

void proximity_algo(t_swap *data, int index)
{
    if (index == 0)
        pb(&data->a, &data->b);
    else if ((get_lst_size(data->a)) / 2 > index)
        ra(&data->a);
    else
        rra(&data->a);
    data->j++;
}