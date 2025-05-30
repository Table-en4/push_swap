/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:09:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/29 18:35:59 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow_digit(unsigned long long res, int sign, char digit)
{
	if (res > (unsigned long long)(LLONG_MAX / 10))
		return (1);
	if (res == (unsigned long long)(LLONG_MAX / 10))
	{
		if (sign == 1 && (digit - '0') > LLONG_MAX % 10)
			return (1);
		if (sign == -1 && (digit - '0') > -(LLONG_MIN % 10))
			return (1);
	}
	return (0);
}

int	is_overflow(const char **str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (!**str)
		return (1);
	while (**str >= '0' && **str <= '9')
	{
		if (check_overflow_digit(res, sign, **str))
			return (1);
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	if (**str)
		return (1);
	return (0);
}

int	is_valid_number(const char *str)
{
	return (!is_overflow(str));
}

void	free_stack_exit(t_swap *swap)
{
	free(swap->a);
	free(swap->b);
	ft_error("Error");
	exit(EXIT_FAILURE);
}

void	fill_stack(t_swap *swap, int argc, char **argv)
{
	int	i;

	swap->size = argc - 1;
	swap->sa = swap->size;
	swap->sb = 0;
	swap->a = malloc(sizeof(long long) * swap->size);
	swap->b = malloc(sizeof(long long) * swap->size);
	if (!swap->a || !swap->b)
		free_stack_exit(swap);
	i = 0;
	while (i < swap->sa)
	{
		if (!is_valid_number(argv[i + 1]))
			free_stack_exit(swap);
		swap->a[i] = ft_atoll(argv[i + 1]);
		i++;
	}
}
