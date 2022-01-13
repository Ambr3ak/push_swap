#include "../inc/push.h"

void sort_min(t_swap *data)
{
    t_list_int *a_tmp;

    a_tmp = data->a->next;
    if (data->a->content > a_tmp->content)
        sa(&data->a);
    free(a_tmp);
}

void sort_three(t_swap *data)
{
    int *tab;

    tab = malloc_list(data, sizeof(int) * (3));
    while (!is_sorted(data->a, tab, 3))
    {
        if (tab[0] > tab[1])
            sa(&data->a);
        else if (tab[0] > tab[1] && tab[2] > tab[1])
            ra(&data->a);
        else if (tab[0] < tab[1])
            rra(&data->a);    
    }
}

void sort_10(t_swap *data)
{
    int smaller;

    while (get_lst_size(data->a) != 3)
    {
        smaller = small(data->a);
        data->index = get_index(data->a, smaller);
        if (get_lst_size(data->a) / 2 > data->index)
            ra(&data->a);
        else
            rra(&data->a);
        if (data->a->content == smaller)
            pb(&data->a, &data->b);
    }
    sort_three(data);
    while (data->b)
        pa(&data->a, &data->b);
}
