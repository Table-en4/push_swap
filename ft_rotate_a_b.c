/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:00 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/20 21:20:48 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_rotate_sa(t_swap *swap)
{
	int	i;
	int	*tmp;

	i = 0;
	if (!swap || !swap->a || swap->size < 2)
		return ;
	tmp = &swap->a[0];
	while (i < swap->size - 1)
	{
		swap->a[i] = swap->a[i + 1];
		i++;
	}
	swap->a[swap->size - 1] = *tmp;
}
