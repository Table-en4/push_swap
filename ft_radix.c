/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:41:25 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/24 18:08:40 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_swap *s)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = malloc(sizeof(int) * s->sa);
	if (!sorted)
		return ;
	i = -1;
	while (++i < s->sa)
		sorted[i] = s->a[i];
	sort_int_tab(sorted, s->sa);
	i = -1;
	while (++i < s->sa)
	{
		j = -1;
		while (++j < s->sa)
		{
			if (s->a[i] == sorted[j])
			{
				s->a[i] = j;
				break ;
			}
		}
	}
	free(sorted);
}

void	radix_sort(t_swap *s)
{
	int	i;
	int	j;
	int	bit;
	int	max;

	index_stack(s);
	max = s->sa - 1;
	bit = 0;
	while ((max >> bit) != 0)
		bit++;
	i = 0;
	while (i < bit)
	{
		j = s->sa;
		while (j-- > 0)
		{
			if (((s->a[0] >> i) & 1) == 1)
				ft_rotate_a(s);
			else
				ft_push_pb(s);
		}
		while (s->sb > 0)
			ft_push_pa(s);
		i++;
	}
}

