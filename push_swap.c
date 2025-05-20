/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/20 21:00:20 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	nbr;
	t_swap	*swap;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
			ft_putchar(argv[j][i++]);
		ft_putchar('\n');
		j++;
	}
	swap = malloc(sizeof(t_swap));
	if (!swap)
		return (ft_putstr_fd("erreur de malloc dans le main", 2), 1);
	swap->a = &nbr;
	ft_rotate_sa(swap);
	j = 1;
	ft_printf("%s\n", "ft_rotate_sa :");
	while (j < argc)
	{
		nbr = ft_atoi(argv[j]);
		printf("%d\n", nbr);
		j++;
	}
}
