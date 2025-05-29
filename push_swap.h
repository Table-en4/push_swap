/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:16:56 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/29 18:37:33 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_swap
{
	int	size;
	int	*a;
	int	*b;
	int	sa;
	int	sb;
}	t_swap;

void		fill_stack(t_swap *swap, int argc, char **argv);
void		ft_swap_sa(t_swap *swap);
void		ft_swap_sb(t_swap *swap);
void		ft_ss(t_swap *swap);
void		ft_push_pa(t_swap *swap);
void		ft_push_pb(t_swap *swap);
void		ft_pp(t_swap *swap);
void		ft_rotate_a(t_swap *swap);
void		ft_rotate_b(t_swap *swap);
void		ft_rr(t_swap *swap);
void		ft_rr_a(t_swap *swap);
void		ft_rr_b(t_swap *swap);
void		ft_rrr(t_swap *swap);
void		ft_error(char *str);
void		sort_small(t_swap *s);
void		sort_three(t_swap *swap);
void		sort_three_b(t_swap *swap);
void		radix_sort(t_swap *s);
void		sort_array(int *arr, int size);
long long	ft_atoll(const char *str);
int			check_min_max(t_swap *s);
int			is_sorted(t_swap *s);

#endif
