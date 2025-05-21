/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:00 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/21 16:25:13 by molapoug         ###   ########.fr       */
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

void	ft_push_pa(t_swap *swap)
{
	//int	tmp;
	int	i;

	//tmp = swap;
	if (!swap->b)
		return ;
	i = 0;
	while (i < swap->size)
		i++;
	//tmp = swap->b[0];
	swap->b[0] = swap->a[i + 1];
}

void	ft_push_pb(t_swap *swap)
{
	int	i;

	if (!swap->a)
		return ;
	i = 0;
	while (i < swap->size)
		i++;
	swap->a[0] = swap->b[i + 1];
}
