/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:50:06 by mcerchi           #+#    #+#             */
/*   Updated: 2023/06/20 18:32:57 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_lst_delete(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}
/*
//old
void	ft_lstcheck(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == check)
				ft_display_exit();
		stack_a = stack_a->next;
	}
	return ;
}

*/

void	ft_lstcheck(t_list *stack_a, int check)// check if there are copie
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == check)
			{
				ft_display_exit();
				return;
			}
		stack_a = stack_a->next; // scorre di un nodo
	}
	return ;
}
/*old 


void	ft_lst_order(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content > tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	exit(0);
}
*/

void ft_lst_order(t_list **stack_a)
{
    t_list	*tmp;
	
	tmp = *stack_a;

    while (tmp->next != NULL && tmp->content <= tmp->next->content) // check if this "=" is necessary
    {
        tmp = tmp->next; //scorri di un nodo
    }

    if (tmp->next != NULL)
    {
        return;
    }

    exit(0);
}

/*
void	ft_lst_inverted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content < tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_sa(stack_a);
	return ;
}
*/	

void ft_lst_inverted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next; 
    while (tmp2 != NULL && tmp->content >= tmp2->content) // (rispetto a ft_lst_order) 
    {
        tmp = tmp->next; //scorre
        tmp2 = tmp2->next; //scorre
    }

    if (tmp2 == NULL) // dopo i controlli swappo
        ft_sa(stack_a);
}

void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp); //
		ft_lstcheck(*stack_a, tmp->content);
		i++;
	}
	ft_lst_order(stack_a);
	ft_lst_inverted(stack_a);
	tmp = NULL;
}
