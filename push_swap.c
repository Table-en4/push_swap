/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:18 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/20 00:23:51 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int main(int argc, char **argv)
{
    t_swap  swap;
    int     i;

    if (argc < 2)
        return (ft_putstr_fd("Error ARG", 2), 1);
    if (!ft_malloc_stack(&swap, argc - 1))
		return (ft_putstr_fd("Faill malloc", 1), 1);
    i = 0;
    while (i < argc - 1)
    {
        swap.a[i] = atoi(argv[i + 1]);
        i++;
    }
    swap.sa = argc - 1;
    ft_divide_stack(&swap);
    i = 0;
    ft_printf("%s\n", "stack a");
    while (i < swap.sa)
    {
        ft_printf("%d ", swap.a[i]);
        i++;
    }
	ft_putcharp('\n');
    i = 0;
    ft_printf("%s\n", "stack b");
    while (i < swap.sb)
    {
        ft_printf("%d\n", swap.b[i]);
        i++;
    }
    free(swap.a);
    free(swap.b);
    return (0);
}
