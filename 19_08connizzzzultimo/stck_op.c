/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:00:00 by your_username    #+#    #+#             */
/*   Updated: 2023/08/17 10:00:00 by your_username   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack_a, int print)
{
	t_stack	*temp;
	t_stack	*last_node;
	int		size;

	size = count_elements(*stack_a);
	temp = *stack_a;
	while (size - 2 > 0)
	{
		temp = temp->next;
		size--;
	}
	last_node = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, last_node);
	if (print != 1)
		write(1, "rra\n", 4);
}

// void	ft_rra(t_stack **stack_a)
// {
// 	t_stack	*last;
// 	t_stack	*tmp;

// 	last = *stack_a;
// 	tmp = *stack_a;
// 	while (last->next != NULL)
// 	{
// 		tmp = last;
// 		last = last->next;
// 	}
// 	last->next = *stack_a;
// 	*stack_a = last;
// 	tmp->next = NULL;
// 	write(1, "rra\n", 4);
// }

void	ft_sa(t_stack **stack_a, int print)
{
	t_stack	*temp_a;
	t_stack	*next_node;

	if (count_elements(*stack_a) < 2)
		return ;
	temp_a = *stack_a;
	next_node = (*stack_a)->next;
	*stack_a = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, temp_a);
	ft_lstadd_front(stack_a, next_node);
	if (print != 1)
		write(1, "sa\n", 3);
}

// void	ft_sa(t_stack **stack_a)
// {
// 	t_stack	*tmp;
// 	t_stack	*tmp2;

// 	tmp = *stack_a;
// 	tmp2 = tmp->next;
// 	*stack_a = tmp2;
// 	tmp->next = tmp2->next;
// 	tmp2->next = tmp;
// 	write(1, "sa\n", 3);
// 	return ;
// }

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	if (!*stack_a)
		ft_lstadd_back(stack_a, ft_lstnew(&(*stack_b)->content));
	else
		ft_lstadd_front(stack_a, ft_lstnew(&(*stack_b)->content));
	*stack_b = (*stack_b)->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;

	if (!stack_a || !(*stack_a))
		return ;
	temp_a = *stack_a;
	if (!*stack_b)
		ft_lstadd_back(stack_b, ft_lstnew(&(*stack_a)->content));
	else
		ft_lstadd_front(stack_b, ft_lstnew(&(*stack_a)->content));
	*stack_a = (*stack_a)->next;
	free(temp_a);
	write(1, "pb\n", 3);
}

// void	ft_pa(t_stack **stack_b, t_stack **stack_a)
// {
// 	t_stack	*tmp;

// 	if (*stack_b == NULL || stack_b == NULL)
// 		return ;
// 	tmp = *stack_b;
// 	*stack_b = (*stack_b)->next;
// 	tmp->next = *stack_a;
// 	*stack_a = tmp;
// 	free(tmp);
// 	write(1, "pa\n", 3);
// }

// void	ft_pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*tmp;

// 	if (*stack_a == NULL)
// 		return ;
// 	tmp = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	tmp->next = *stack_b;
// 	*stack_b = tmp;
// 	free(tmp);
// 	write(1, "pb\n", 3);
// }
void	ft_ra(t_stack **stack_a, int print)
{
	t_stack	*first_elem;

	first_elem = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, first_elem);
	first_elem->next = NULL;
	if (print != 1)
		write(1, "ra\n", 3);
}

// void	ft_ra(t_stack **stack_a)
// {
// 	t_stack	*first;
// 	t_stack	*current;

// 	if (*stack_a == NULL || (*stack_a)->next == NULL)
// 		return ;
// 	first = *stack_a;
// 	*stack_a = first->next;
// 	first->next = NULL;
// 	current = *stack_a;
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = first;
// 	write(1, "ra\n", 3);
// }
