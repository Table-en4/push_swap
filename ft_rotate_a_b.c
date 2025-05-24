/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:32:34 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/24 13:37:25 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_swap *swap)
{
	int i;
	int	tmp;

	if (!swap->a || swap->sa < 2)
		return ;
	tmp = swap->a[0];
	i = 0;
	while (i < swap->sa - 1)
	{
		swap->a[i] = swap->a[i + 1];
		i++;
	}
	swap->a[swap->sa - 1] = tmp;
}

void	ft_rotate_b(t_swap *swap)
{
	int	i;
	int	tmp;

	if (!swap->b || swap->sb < 2)
		return ;
	tmp = swap->b[0];
	i = 0;
	while (i < swap->sb - 1)
	{
		swap->b[i] = swap->b[i + 1];
		i++;
	}
	swap->b[swap->sb - 1] = tmp;
}

void	ft_rr(t_swap *swap)
{
	ft_rotate_a(swap);
	ft_rotate_b(swap);
}
