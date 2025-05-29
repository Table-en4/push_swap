/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/29 12:07:25 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_swap *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (s->a[i] == s->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_error(t_swap *s)
{
	if (check_double(s))
		return (1);
	/*else if (check_min_max(s))
		return (1);*/
	return (0);
}

void	sort_three(t_swap *swap)
{
	int	*a;

	a = swap->a;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		ft_swap_sa(swap);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		ft_swap_sa(swap);
		ft_rr_a(swap);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ft_rotate_a(swap);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		ft_swap_sa(swap);
		ft_rotate_a(swap);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		ft_rr_a(swap);
}

void	sort_three_b(t_swap *swap)
{
	int	*b;

	b = swap->b;
	if (b[0] > b[1] && b[1] < b[2] && b[0] < b[2])
		ft_swap_sb(swap);
	else if (b[0] > b[1] && b[1] > b[2])
	{
		ft_swap_sb(swap);
		ft_rr_b(swap);
	}
	else if (b[0] > b[1] && b[1] < b[2] && b[0] > b[2])
		ft_rotate_b(swap);
	else if (b[0] < b[1] && b[1] > b[2] && b[0] < b[2])
	{
		ft_swap_sb(swap);
		ft_rotate_b(swap);
	}
	else if (b[0] < b[1] && b[1] > b[2] && b[0] > b[2])
		ft_rr_b(swap);
}

int	main(int ac, char **av)
{
	t_swap	swap;

	if (ac < 3)
		return (ft_error("Error"), 1);
	fill_stack(&swap, ac, av);
	if (parse_error(&swap) == 1)
	{
		free(swap.a);
		free(swap.b);
		return (ft_error("Error"), 1);
	}
	if (swap.size <= 5)
		sort_small(&swap);
	else
		radix_sort(&swap);
	free(swap.a);
	free(swap.b);
	return (0);
}
