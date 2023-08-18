/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_srt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:01:55 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/18 02:52:25 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countbits(int num)
{
	int	count;

	count = 1;
	while (num && count++)
		num >>= 1;
	return (count);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nb;
	int	i;
	int	size;

	nb = countbits(count_elements(*stack_a) - 1);
	i = 0;
	while (i < nb)
	{
		size = count_elements(*stack_a);
		while (size--)
		{
			if (((*stack_a)->content) & (1 << i))
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		size = count_elements(*stack_b);
		while (size--)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
