/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort235.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:01:55 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/18 19:23:31 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *a = *stack_a;

	if (count_elements(a) == 2)
	{
		if (a->content > a->next->content)
			ft_sa(stack_a);
		return;
	}
	else if (count_elements(a) == 3)
	{
		sort_three_elements(stack_a);
		return;
	}

	if (a->content > a->next->next->content)
	{
		if (a->next->content > a->next->next->content)
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
		else
			ft_ra(stack_a);
	}
	else
	{
		if (a->next->content > a->next->next->content)
			ft_rra(stack_a);
	}

	sort_three_elements(stack_a);
	while (*stack_b)
		ft_pa(stack_b, stack_a);
}


void	sort_three_elements(t_stack **stack_a)
{
	t_stack *a = *stack_a;

	if (a->content > a->next->content && a->next->content < a->next->next->content)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a->content > a->next->content && a->content < a->next->next->content)
		ft_ra(stack_a);
	else if (a->content > a->next->next->content && a->next->content < a->next->next->content)
		ft_sa(stack_a);
	else if (a->content > a->next->next->content && a->content > a->next->content)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (a->content < a->next->content && a->content < a->next->next->content && a->next->content > a->next->next->content)
		ft_rra(stack_a);
}

void	sort_two_elements(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
	}
}
