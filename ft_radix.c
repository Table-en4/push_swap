/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:41:25 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/28 16:30:19 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack(t_swap *s, int *sorted)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		sorted[i] = s->a[i];
		i++;
	}
}

void	sort_array(int *arr, int size)
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
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	replace_with_index(t_swap *s, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size)
	{
		j = 0;
		while (j < s->size && s->a[i] != sorted[j])
			j++;
		if (j < s->size)
			s->a[i] = j;
		i++;
	}
}

void	normalize_values(t_swap *s)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * s->size);
	if (!sorted)
		return ;
	copy_stack(s, sorted);
	sort_array(sorted, s->size);
	replace_with_index(s, sorted);
	free(sorted);
}

int	get_max_bits(t_swap *s)
{
	int	max;
	int	bits;
	int	i;

	max = s->a[0];
	i = 1;
	while (i < s->size)
	{
		if (s->a[i] > max)
			max = s->a[i];
		i++;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_swap *s)
{
	int	i;
	int	j;
	int	max_bits;
	int	current_size;

	normalize_values(s);
	max_bits = get_max_bits(s);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		current_size = s->sa;
		while (j < current_size)
		{
			if (((s->a[0] >> i) & 1) == 0)
				ft_push_pb(s);
			else
				ft_rotate_a(s);
			j++;
		}
		while (s->sb > 0)
			ft_push_pa(s);
		i++;
	}
}
