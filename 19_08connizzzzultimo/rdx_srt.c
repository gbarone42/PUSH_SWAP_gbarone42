/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_srt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:01:55 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/19 02:10:46 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countbits(int num)
{
	int	count;

	count = 1;
	while (num && count++)
		num >>= 1;
	return (count - 1);
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
		size = count_elements(*stack_a) + 1;
		while (--size)
		{
			if (*(int *)((*stack_a)->content) & (1 << i))
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		size = count_elements(*stack_b) + 1;
		while (--size)
			ft_pa(stack_a, stack_b);
		i++;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*k;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	k = ft_lstlast(*lst);
	k->next = new;
}

t_stack	*ft_lstnew(void *content)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(*temp));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}