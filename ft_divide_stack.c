/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:09:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/23 20:03:34 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_swap *swap, int argc, char **argv)
{
    int i;
	int half;

	swap->size = argc - 1;
	half = swap->size / 2;
	swap->size_a = half;
	swap->size_b = swap->size - half;
	swap->a = malloc(sizeof(int) * swap->size_a);
	swap->b = malloc(sizeof(int) * swap->size_b);
	if (!swap->a || !swap->b)
        return ;
	i = 0;
	while (i < swap->size_a)
	{
		swap->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < swap->size_b)
	{
		swap->b[i] = ft_atoi(argv[i + 1 + swap->size_a]);
		i++;
	}
}
