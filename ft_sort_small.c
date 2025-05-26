/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:33:30 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/26 15:32:14 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int *tab, int size)
{
	int	i;
	int	min;
	int	index;

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
	int	min_index;
	int	i;

	min_index = find_min_index(s->a, s->sa);
	if (min_index == 1)
		ft_swap_sa(s);
	else if (min_index == 2 && s->sa == 3)
	{
		ft_rotate_a(s);
		ft_rotate_a(s);
	}
	else if (min_index == 2 || min_index == 3)
	{
		i = s->sa - min_index;
		while (i-- > 0)
			ft_rr_a(s);
	}
	else if (min_index != 0)
	{
		i = min_index;
		while (i-- > 0)
			ft_rotate_a(s);
	}
	ft_push_pb(s);
}
void	push_min_to_a(t_swap *s)
{
	int	min_index;
	int	i;

	min_index = find_min_index(s->b, s->sb);
	if (min_index == 1)
		ft_swap_sb(s);
	else if (min_index == 2 && s->sb == 3)
	{
		ft_rotate_b(s);
		ft_rotate_b(s);
	}
	else if (min_index == 2 || min_index == 3)
	{
		i = s->sb - min_index;
		while (i-- > 0)
			ft_rr_b(s);
	}
	else if (min_index != 0)
	{
		i = min_index;
		while (i-- > 0)
			ft_rotate_b(s);
	}
	ft_push_pa(s);
}

void	sort_small(t_swap *s)
{
	ft_rr_b(s);
	if (s->sa == 2 && s->a[0] > s->a[1])
		ft_swap_sa(s);
	else if (s->sa == 3)
		sort_three(s);
	else if (s->sa <= s->size)
	{
		while (s->sa > s->size)
			push_min_to_b(s);
		sort_three(s);
		while (s->sb > 0)
			ft_push_pa(s);
	}/*
	if (s->sb == 2 && s->b[0] > s->b[1])
		ft_swap_sa(s);
	else if (s->sb == 3)
		sort_three_b(s);
	else if (s->sb <= s->size)
	{
		while (s->sb > s->size)
			push_min_to_a(s);
		sort_three_b(s);
		while (s->sa > 0)
			ft_push_pb(s);
	}*/
}

