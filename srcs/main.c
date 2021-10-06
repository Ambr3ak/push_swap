#include "inc/push.h"

void parser_nb

void init_swap(t_swap *data)
{
    data->arg = malloc_list(data, sizeof(t_arg));
    if (!data->arg)
        data->error = MALLOC;
}

int main(int ac, char **ag)
{
    t_swap data;

    if (ac < 2)
        return (0);
    data = malloc(sizeof(t_swap));
    data->mlc = NULL;
    if (data)
        init_swap(data);
}