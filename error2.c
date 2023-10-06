/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badph <badph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:12:11 by gbarone           #+#    #+#             */
/*   Updated: 2023/10/06 12:53:29 by badph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_errorrr(void)
{
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError\033[0m\n\n", 19);
	write(1, " 4       <°)))><  \n", 21);
	write(1, "    /\\_/\\     \n", 16);
	write(1, "   ( o.o )    \n", 16);
	write(1, "   (> ^ <)      <°)))><  \n", 28);
	write(1, "  /      \\   2  \n", 18);
	write(1, " / /~~~~\\ \\  \n", 15);
	write(1, "/_/      \\_\\   \n", 17);
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError03\033[0m\n\n", 21);
	write(1, "\n", 1);
}

void	ft_errorrrr(void)
{
	write(1, "\n", 1);
	write(1, "   <°)))><       \n", 20);
	write(1, "\n\033[1;31mError\033[0m\n\n", 19);
	write(1, "     /\\_/\\     \n", 17);
	write(1, "    ( o.o )    \n", 16);
	write(1, "    > ^ <    42\n", 17);
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError04\033[0m\n\n", 22);
	write(1, "\n", 1);
	exit(1);
}

void	ft_errorrrrr(void)
{
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError\033[0m\n\n", 19);
	write(1, "     ><(((°>    \n", 19);
	write(1, "       <°)))><  \n", 18);
	write(1, "     /\\___/\\      \n", 20);
	write(1, " /  O O  \\       \n", 19);
	write(1, "( == ^ == )    2 \n", 19);
	write(1, "   )      (     \n", 17);
	write(1, "  /        \\   \n", 17);
	write(1, " /          \\  \n", 17);
	write(1, "/_ _ _ _ _ _\\ \n", 16);
	write(1, "     ><(((°>    \n", 19);
	write(1, " 4     <°)))><  \n", 18);
	write(1, "\n\033[1;31mError05\033[0m\n\n", 21);
	write(1, "\n", 1);
	exit(1);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack != NULL)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	get_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (*(int *)stack->content == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
