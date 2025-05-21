/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:16:56 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/21 17:16:56 by molapoug         ###   ########.fr       */
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
	int	size_a;
	int	size_b;
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

/* fonctions with void for divide */
void    ft_divide_stack(t_swap *swap);

/* fonctions with void for swap and push */
void	ft_swap_sa(t_swap *swap);
void	ft_swap_sb(t_swap *swap);
void	ft_push_pa(t_swap *swap);
void	ft_push_pb(t_swap *swap);

/* fonctions with void for rotate */
void	ft_rotate_a(t_swap *swap);
void	ft_rotate_b(t_swap *swap);
void	ft_rr(t_swap *swap);

/*fonctions with int */
int	ft_malloc_stack(t_swap *swap, int size);

#endif
