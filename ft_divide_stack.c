/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:09:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/28 17:40:54 by molapoug         ###   ########.fr       */
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
