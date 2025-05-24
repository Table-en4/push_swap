/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:09:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/24 12:04:19 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_swap *swap, int argc, char **argv)
{
	int	i;
	int	half;

	swap->size = argc - 1;
	half = swap->size / 2;
	swap->sa = half;
	swap->sb = swap->size - half;
	/*swap->a = malloc(sizeof(int) * swap->sa);
	swap->b = malloc(sizeof(int) * swap->sb);*/
	swap->a = malloc(sizeof(int) * argc - 1);
	swap->b = malloc(sizeof(int) * argc - 1);
	if (!swap->a || !swap->b)
		return ;
	i = 0;
	while (i < swap->sa)
	{
		swap->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < swap->sb)
	{
		swap->b[i] = ft_atoi(argv[i + 1 + swap->sa]);
		i++;
	}
}
