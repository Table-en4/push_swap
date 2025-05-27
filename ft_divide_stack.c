/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:09:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/27 14:06:54 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_swap *swap, int argc, char **argv)
{
    int	i;

    swap->size = argc - 1;
    swap->sa = swap->size;
    swap->sb = 0;
    swap->a = malloc(sizeof(int) * swap->size);
    swap->b = malloc(sizeof(int) * swap->size);
    if (!swap->a || !swap->b)
        return ;
    i = 0;
    while (i < swap->sa)
    {
        swap->a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
}

void    get_max_bits(t_swap *s, int *max_bits)
{
    int i;
    int max;

    max = s->a[0];
    i = 1;
    while (i < s->size)
    {
        if (s->a[i] > max)
            max = s->a[i];
        i++;
    }
    *max_bits = 0;
    while ((max >> *max_bits) != 0)
        (*max_bits)++;
}

void    radix_sort(t_swap *s)
{
    int i;
    int j;
    int max_bits;

    get_max_bits(s, &max_bits);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < s->size)
        {
            if ((s->a[0] >> i) & 1)
                ft_rotate_a(s);
            else
                ft_push_pb(s);
            j++;
        }
        while (s->sb > 0)
            ft_push_pa(s);
        i++;
    }
}
