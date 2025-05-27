/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:02:54 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/27 22:28:02 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_a(t_swap *swap)
{
	int	i;
	int	last;

	if (!swap || swap->sa < 2)
		return ;
	last = swap->a[swap->sa - 1];
	i = swap->sa - 1;
	while (i > 0)
	{
		swap->a[i] = swap->a[i - 1];
		i--;
	}
	swap->a[0] = last;
	ft_printf("rra\n");
}

void	ft_rr_b(t_swap *swap)
{
	int	i;
	int	last;

	if (!swap || swap->sb < 2)
		return ;
	last = swap->b[swap->sb - 1];
	i = swap->sb - 1;
	while (i > 0)
	{
		swap->b[i] = swap->b[i - 1];
		i--;
	}
	swap->b[0] = last;
	ft_printf("rrb\n");
}

void	ft_rrr(t_swap *swap)
{
	ft_rr_a(swap);
	ft_rr_b(swap);
	ft_printf("rrr\n");
}

void	ft_pp(t_swap *swap)
{
	ft_push_pa(swap);
	ft_push_pb(swap);
	ft_printf("pp\n");
}
