/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:09:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/20 11:37:40 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_divide_stack(t_swap *swap)
{
	int	i;
	int	pivot;

	i = 0;
	pivot = swap->a[swap->sa / 2];
	while (i < swap->sa)
	{
		if (swap->a[i] < pivot)
		{
			swap->b[swap->sb++] = swap->a[i];
			swap->pb++;
		}
		else
			swap->a[i - swap->pb] = swap->a[i];
		i++;
	}
	swap->sa -= swap->pb;
}

int	ft_malloc_stack(t_swap *swap, int size)
{
	swap->a = malloc(sizeof(int) * size);
	swap->b = malloc(sizeof(int) * size);
	if (!swap->a || !swap->b)
	{
		free(swap->a);
		free(swap->b);	
		return (0);
	}
	swap->sa = size;
	swap->sb = 0;
	return (1);
}
