/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/23 20:43:43 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_swap *swap)
{
	int i;

	i = 0;
	ft_printf("%s", "Pile A:\n");
	while (i < swap->size_a)
	{
		ft_printf("%d\n", swap->a[i]);
		i++;
	}
	i = 0;
	ft_printf("%s", "Pile B:\n");
	while (i < swap->size_b)
	{
		ft_printf("%d\n", swap->b[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
    t_swap  swap;

    if (argc < 3)
        return (1);
    fill_stack(&swap, argc, argv);
    //ft_swap_sa(&swap);
    //ft_ss(&swap);
    ft_rotate_a(&swap);
    print_stacks(&swap);
    free(swap.a);
	free(swap.b);
}
