
#include "../inc/push.h"

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