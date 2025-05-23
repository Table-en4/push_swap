/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/24 17:56:30 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stacks(t_swap *swap)
{
	int	i;

	i = 0;
	ft_printf("%s", "Pile A:\n");
	while (i < swap->sa)
	{
		ft_printf("%d\n", swap->a[i]);
		i++;
	}
	i = 0;
	ft_printf("%s", "Pile B:\n");
	while (i < swap->sb)
	{
		ft_printf("%d\n", swap->b[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_swap	swap;

	if (ac < 3)
		return (ft_perror("manque d'argument") ,1);
	fill_stack(&swap, ac, av);
	/* tentative d'algo simple */
	sort_small(&swap);
	print_stacks(&swap);
	free(swap.a);
	free(swap.b);
}
