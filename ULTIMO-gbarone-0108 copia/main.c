/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/02 23:28:25 by gbarone          ###   ########.fr       */
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


t_stack *allocate_stack(char **str)
{
	int i;
	t_stack *head = NULL;
	t_stack *current = NULL;
	t_stack *prev = NULL;

	i = 0;
	if (!str || !str[0])// Handle the case of an empty input or NULL pointer
        return NULL;
	while (str[i])//till its !(NULL), till encounters NULLpointer // linked list is built during the loop
	{
		current = malloc(sizeof(t_stack));//size of memory block is determined by the size  oft_stack structure representing a node in the linked list.
		if (!current) // After allocating memory for the current node, the function checks if the allocation was successful by verifying if current is not NULL. If the allocation fails (current is NULL), the function returns NULL, indicating that there was a memory allocation failure. This can be handled later in the program if needed.
			return (NULL); // Handle allocation failure, or you can exit the program
		current->content = ft_atoi(str[i]);
		current->next = NULL;
		if (!head) // means we are at the beginning of the list, since this is the first node
			head = current; // Set head if it's not set already
		if (prev)
			prev->next = current; // Link the previous node to the current node
		prev = current; // Move the previous pointer to the current node
		i++;
	}
	return (head);
}

int count_elements(t_stack *A)
{
    int count;
	
	count = 0;
    t_stack *current = A;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}


int main(int ac, char **av)
{
	int argz;
	t_inter stacks;

	if (check_av(ac, av))
		return (1);
	stacks.a = allocate_stack(av);
	//  if (!stacks.a)
    //{
    //   printf("Memory allocation failed. Exiting...\n");
    //    return 1;
    //}
	if(count_elements(stacks.a) == 1)
	{
		free(stacks.a);
		return (0);
	}
}
