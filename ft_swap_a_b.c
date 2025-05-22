/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:00 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/22 20:11:50 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sa(t_swap *swap)
{
	int	tmp;

	if (!swap || !swap->a || swap->size < 2)
		return ;
	tmp = swap->a[0];
	swap->a[0] = swap->a[1];
	swap->a[1] = tmp;
}

void	ft_swap_sb(t_swap *swap)
{
	int	tmp;

	if (!swap || !swap->b || swap->size < 2)
		return ;
	tmp = swap->b[0];
	swap->b[0] = swap->b[1];
	swap->b[1] = tmp;
}

void	ft_ss(t_swap *swap)
{
	ft_swap_sa(swap);
	ft_swap_sb(swap);
}

void ft_push_pa(t_swap *swap)
{
    int i;

    i = 0;
    if (swap->sb > 0)
    {
        swap->a[swap->sa] = swap->b[0];
        swap->sa++;
        while (i < swap->sb - 1)
        {
            swap->b[i] = swap->b[i + 1];
            i++;
        }
        swap->sb--;
    }
}


void ft_push_pb(t_swap *swap)
{
    int i;

    i = 0;
    if (swap->sa > 0)
    {
        swap->b[swap->sb] = swap->a[0];
        swap->sb++;
        while (i < swap->sa - 1)
        {
            swap->a[i] = swap->a[i + 1];
            i++;
        }
        swap->sa--;
    }
}

