/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort235.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:01:55 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/18 17:43:20 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	total_elements;

	total_elements = count_elements(*stack_a);
	while (total_elements > 3)
	{
		if ((*stack_a)->content < 3)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		total_elements--;
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	sort_three_elements(t_stack **stack_a)
{
	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		ft_rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		ft_sa(stack_a);
		sort_three_elements(stack_a);
	}
}

void	sort_two_elements(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
	}
}
