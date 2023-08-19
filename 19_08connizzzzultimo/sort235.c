/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort235.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:01:55 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/19 02:13:57 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	i;

	while (count_elements(*stack_a) > 3)
	{
		min = find_min(*stack_a);
		i = get_index(*stack_a, min);
		if (i < 3)
		{
			while (*(int *)(*stack_a)->content != min)
				ft_ra(stack_a);
		}
		else
		{
			while (*(int *)(*stack_a)->content != min)
				ft_rra(stack_a);
		}
		ft_pb(stack_a, stack_b);
	}
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		ft_pa(stack_a, stack_b);
		*stack_b = (*stack_b)->next;
	}
}

static void	sort_3_number_helper(t_stack **stack_a)
{
	ft_rra(stack_a);
	ft_sa(stack_a);
}

void	sort_three_elements(t_stack **stack_a)
{
	int	tmp;
	int	tmp_n;

	tmp = *(int *)(*stack_a)->content;
	tmp_n = *(int *)(*stack_a)->next->content;
	if (!*(int *)(*stack_a)->next->next && tmp > tmp_n)
		ft_sa(stack_a);
	else if (tmp > tmp_n
		&& tmp < *(int *)(*stack_a)->next->next->content)
		ft_sa(stack_a);
	else if (tmp > *(int *)(*stack_a)->next->next->content
		&& tmp_n < *(int *)(*stack_a)->next->next->content)
		ft_ra(stack_a);
	else if (tmp < tmp_n
		&& tmp_n > *(int *)(*stack_a)->next->next->content
		&& tmp < *(int *)(*stack_a)->next->next->content)
		sort_3_number_helper(stack_a);
	else if (tmp < tmp_n && tmp_n > *(int *)(*stack_a)->next->next->content
		&& tmp > *(int *)(*stack_a)->next->next->content)
		ft_rra(stack_a);
	else if (tmp > tmp_n && tmp_n > *(int *)(*stack_a)->next->next->content)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}

void	sort_two_elements(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			ft_sa(stack_a);
	}
}
