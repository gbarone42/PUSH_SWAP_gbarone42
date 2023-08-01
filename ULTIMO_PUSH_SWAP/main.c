/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/01 15:48:58 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicate(char **str)
{
	int a = 0;
	int b;

	while (str[a])
	{
		b = a + 1;
		while (str[b])
		{
			if (ft_strcmp(str[a], str[b]) == 0)
				return (0); // Found a duplicate, return 0
			b++;
		}
		a++;
	}
	return (1); // No duplicates found, return 1
}

int check_av_space(int ac, char **av)
{
	char **args;
	int argz;

	args = ft_split(av[1], ' ');
	argz = ft_atoi(av[1]);
	if (!args)
		ft_error();
	else if (ac <= 1)
		ft_error_few_arg();
	else if (ac == 2)
	{
		if (check_duplicate(args) && !ft_isdigit_and_sign(argz))
		{
			free(args); // Free memory allocated by split?
			ft_error_double();
		}
		free(args); //`Free memory allocated by split?
		return (0);
	}
	return (0);
}

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

int main(int ac, char **av)
{
	int argz;
	int i;
	t_inter stacks;

	i = 0;
	if (check_av_space(ac, av))
		return (1);
	while (i < ac)
	{
		argz = ft_atoi(av[i]);
		if (check_duplicate(av[i]) && !ft_isdigit_and_sign(argz))
			ft_error();
		i++;
	}
	//stacks.a = allocate_stack(av);
}
