/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:20:58 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/18 23:20:59 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_few_arg(void)
{
	write(1, "\n", 1);
	exit(1);
}

void	ft_error(void)
{
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError\033[0m\n\n", 19);
	write(1, "     /\\_/\\     \n", 16);
	write(1, "    ( o.o )    \n", 16);
	write(1, "    > ^ <    42\n", 16);
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError01\033[0m\n\n", 21);
	write(1, "\n", 1);
	exit(1);
}

void	ft_errorr(void)
{
	write(1, "\n", 1);
	write(1, "\n\033[1;31mError\033[0m\n\n", 19);
	write(1, "      ><(((°>      \n", 22);
	write(1, "    <°)))><       \n", 21);
	write(1, "   >°)))><        \n", 20);
	write(1, "  <°)))><         \n", 19);
	write(1, " ><°)))><          \n", 18);
	write(1, "       ><(((°>    \n", 22);
	write(1, " 42      <°)))><  \n", 21);
	write(1, "\n\033[1;31mError2\033[0m\n\n", 21);
	write(1, "\n", 1);
}

// void	print_stack(t_stack *stack)
// {
// 	t_stack *current = stack;
// 	while (current != NULL)
// 	{
// 		printf("%d ", current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// }
/*
void	print_max_digit(int max_digit)
{
	printf("Max Digit: %d\n", max_digit);
}
*/