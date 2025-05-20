/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/20 22:43:12 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
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

	i = 0;
	while (i < swap->size)
	{
		swap->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}

	ft_rotate_sa(swap);

	printf("Après rotation :\n");
	i = 0;
	while (i < swap->size)
		printf("%d\n", swap->a[i++]);

	free(swap->a);
	free(swap);
	return (0);
}

