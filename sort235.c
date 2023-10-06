/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort235.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:01:55 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/19 14:41:37 by gbarone          ###   ########.fr       */
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
				ft_ra(stack_a, 0);
		}
		else
		{
			while (*(int *)(*stack_a)->content != min)
				ft_rra(stack_a, 0);
		}
		ft_pb(stack_a, stack_b);
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

static void	sort_3_number_helper(t_stack **stack_a)
{
	ft_rra(stack_a, 0);
	ft_sa(stack_a, 0);
}

void	sort_three_elements(t_stack **stack_a)
{
	int	tmp;
	int	tmp_n;

	tmp = *(int *)(*stack_a)->content;
	tmp_n = *(int *)(*stack_a)->next->content;
	if (!(*stack_a)->next->next && tmp > tmp_n)
		ft_sa(stack_a, 0);
	else if (tmp > tmp_n
		&& tmp < *(int *)(*stack_a)->next->next->content)
		ft_sa(stack_a, 0);
	else if (tmp > *(int *)(*stack_a)->next->next->content
		&& tmp_n < *(int *)(*stack_a)->next->next->content)
		ft_ra(stack_a, 0);
	else if (tmp < tmp_n
		&& tmp_n > *(int *)(*stack_a)->next->next->content
		&& tmp < *(int *)(*stack_a)->next->next->content)
		sort_3_number_helper(stack_a);
	else if (tmp < tmp_n && tmp_n > *(int *)(*stack_a)->next->next->content
		&& tmp > *(int *)(*stack_a)->next->next->content)
		ft_rra(stack_a, 0);
	else if (tmp > tmp_n && tmp_n > *(int *)(*stack_a)->next->next->content)
	{
		ft_sa(stack_a, 0);
		ft_rra(stack_a, 0);
	}
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
