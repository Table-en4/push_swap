/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:16:56 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/20 21:21:21 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_swap
{
	int	size;
	int	*a;
	int	*b;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	struct s_stack	*next;
}	t_swap;

/* fonctions with void */
void    ft_divide_stack(t_swap *swap);

/*fonctions with int */
int	ft_malloc_stack(t_swap *swap, int size);
void	*ft_rotate_sa(t_swap *swap);

#endif
