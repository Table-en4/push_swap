/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:16:56 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/27 20:34:49 by molapoug         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_swap;

/* fonctions with void for divide */
void    fill_stack(t_swap *swap, int argc, char **argv);

/* fonctions with void for swap and push */
void	ft_swap_sa(t_swap *swap);
void	ft_swap_sb(t_swap *swap);
void    ft_ss(t_swap *swap);
void	ft_push_pa(t_swap *swap);
void	ft_push_pb(t_swap *swap);
void	ft_pp(t_swap *swap);

/* fonctions with void for rotate and reverse rotate */
void	ft_rotate_a(t_swap *swap);
void	ft_rotate_b(t_swap *swap);
void	ft_rr(t_swap *swap);
void	ft_rr_a(t_swap *swap);
void	ft_rr_b(t_swap *swap);
void	ft_rrr(t_swap *swap);

/* utils fonctions */
void	ft_perror(char *str);

/* fonctions for the algo */
void	sort_small(t_swap *s);
void	sort_three(t_swap *swap);
void	sort_three_b(t_swap *swap);
void	radix_sort(t_swap *s);

#endif
