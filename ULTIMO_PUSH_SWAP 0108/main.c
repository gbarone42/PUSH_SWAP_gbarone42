/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/02 02:04:33 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_av(int ac, char **av)
{
	char **args;
	int argz;

	args = ft_split(av[1], ' ');
	if (!args)
		ft_error();
	else if (ac <= 1)
		ft_error_few_arg();
	else if (ac == 2)
	{	
		argz = ft_atoi(av[1]);
		if (check_duplicate(args) && !ft_isdigit_and_sign(argz))
		{
			ft_free_args(args); // Free memory allocated by split? just free(args);?
			ft_error();
		}
		ft_free_args(args); //`Free memory allocated by split?
		return (0);
	}
	if (duplicates(ac,av) && digitsandsignsvalid(av))
	return(0);
}

/*
t_stack *allocate_stack(char **str)
{
	int i;
	t_stack *head = NULL;
	t_stack *current = NULL;
	t_stack *prev = NULL;

	i = 0;
	while (str[i])
	{
		current = malloc(sizeof(t_stack));
		if (!current)
			return (NULL); // Handle allocation failure, or you can exit the program
		current->content = ft_atoi(str[i]);
		current->next = NULL;

		if (!head)
			head = current; // Set head if it's not set already

		if (prev)
			prev->next = current; // Link the previous node to the current node

		prev = current; // Move the previous pointer to the current node
		i++;
	}

	return (head);
}
*/
int main(int ac, char **av)
{
	int argz;
	
	t_inter stacks;

	if (check_av(ac, av))
		return (1);
	//stacks.a = allocate_stack(av);
}
