/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:33:30 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/27 22:55:07 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int *tab, int size)
{
    int i;
    int min;
    int index;

    min = tab[0];
    index = 0;
    i = 1;
    while (i < size)
    {
        if (tab[i] < min)
        {
            min = tab[i];
            index = i;
        }
        i++;
    }
    return (index);
}

void	push_min_to_b(t_swap *s)
{
    int min_index;
    int r;

    min_index = find_min_index(s->a, s->sa);
    if (min_index == 1)
        ft_swap_sa(s);
    else if (min_index != 0)
    {
        if (min_index <= s->sa / 2)
        {
            while (min_index-- > 0)
                ft_rotate_a(s);
        }
        else
        {
            r = s->sa - min_index;
            while (r-- > 0)
                ft_rr_a(s);
        }
    }
    ft_push_pb(s);
}

void	push_min_to_a(t_swap *s)
{
    int min_index;
    int r;

    min_index = find_min_index(s->b, s->sb);
    if (min_index == 1)
        ft_swap_sb(s);
    else if (min_index != 0)
    {
        if (min_index <= s->sb / 2)
        {
            while (min_index-- > 0)
                ft_rotate_b(s);
        }
        else
        {
            r = s->sb - min_index;
            while (r-- > 0)
                ft_rr_b(s);
        }
    }
    ft_push_pa(s);
}

void	sort_small(t_swap *s)
{
    if (s->sa == 2)
    {
        if (s->a[0] > s->a[1])
            ft_swap_sa(s);
    }
    else if (s->sa == 3)
        sort_three(s);
    else if (s->sa == 4)
    {
        push_min_to_b(s);
        sort_three(s);
        ft_push_pa(s);
    }
    else if (s->sa == 5)
    {
        push_min_to_b(s);
        push_min_to_b(s);
        sort_three(s);
        /*if (s->sb == 2 && s->b[0] < s->b[1])
            ft_swap_sb(s);*/
        ft_push_pa(s);
        ft_push_pa(s);
    }
}
