/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/22 20:12:11 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_sort(t_swap *swap)
{
	int	i;

	if (!swap)
		return ;
	i = 0;
	while (swap->a[i + 1] > swap->a[i])
		ft_push_pb(swap);
}

int	main(int argc, char **argv)
{
	t_swap	*swap;
	int		i;

	if (argc < 2)
		return (1);

	swap = malloc(sizeof(t_swap));
	if (!swap)
		return (ft_putstr_fd("Erreur de malloc\n", 2), 1);

	swap->size = argc - 1;
	swap->a = malloc(sizeof(int) * swap->size);
	if (!swap->a)
		return (ft_putstr_fd("Erreur de malloc pour a\n", 2), 1);
	swap->b = malloc(sizeof(int) * swap->size);
	if (!swap->b)
		return (ft_putstr_fd("Erreur de malloc pour b\n", 2), 1);
	swap->sa = swap->size;
	swap->sb = 0;
	swap->pb = 0;
	i = 0;
	while (i < swap->size)
	{
		swap->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}

	//ft_divide_stack(swap);
	//ft_swap_sa(swap);
	//ft_swap_sb(swap);
	//ft_rotate_a(swap);
	//ft_rotate_b(swap);
	//ft_rr(swap);
	//ft_rr_a(swap);
	//ft_rr_b(swap);
	//ft_rrr(swap);
	//ft_push_pa(swap);
	//try_sort(swap);
	//ft_push_pb(swap);

	printf("Après rotation :\n");
	i = 0;
	while (i < swap->sa)
		ft_printf("pile a : %d\n", swap->a[i++]);
	i = 0;
	while (i < swap->sb)
		ft_printf("pile b : %d\n", swap->b[i++]);
	//free(swap->a);
	free(swap);
	return (0);
}

