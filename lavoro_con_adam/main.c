/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/03 19:16:04 by gbarone          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
    if (!split)
        return;

    // Free each individual string
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }

    // Free the array of pointers
    free(split);
}

int	check_av2(int ac, char **av)
{
	char **args;
	int result;
	int i;
    int containsNonSpaceTab;

    if (!av[1] || av[1][0] == '\0')
	{
        ft_error_few_arg();
	}
	while (av[1][i] && !containsNonSpaceTab)
    {
        if (av[1][i] != ' ' && av[1][i] != '\t')
        {
            containsNonSpaceTab = 1;
        }
        i++;
    }
    if (!containsNonSpaceTab)
        ft_error_few_arg();
    args = ft_split(av[1], ' ');
    result = check_av3(args, ac);
    free_split(args);
    return result;
}

int	check_av3(char **args, int ac)
{
    if (ac == 2)
    {
        validate_args(args);
    }
    return 0;
}

int	validate_args(char **args)
{
    int i;
	int j;
	int ascii;

	i = 0;
    while (args[i])
    {
        if (!check_duplicate(&args[i]))
             ft_errorr();
        j = 0;
        while (args[i][j])
        {
            ascii = args[i][j];
            if (ft_isdigit_and_sign(ascii))
                ft_errorrr();
            j++;
        }
        i++;
    }
    return 0;
}

int	check_av(char **av)
{
	int i = 0;
	while(av[i])
	{
    	if (!check_duplicate(&av[i]))
    	{	
			   ft_errorrrr();
		   	return 1;
		}
		i++;
	}
    return 0;
}


int	check_av_b(int ac, char **av)
{
    int i = 1;
    if(ac > 2)
	{
		while (i < ac)
    	{
        	int j = 0;
       	 while (av[i][j] != '\0')
        	{
            	int ascii = av[i][j];
           	 if (ft_isdigit_and_sign(ascii))
            	{
					ft_errorrrrr();
					return 1;
				}
           	 j++;
        	}
       	 i++;
    	}
	}
	return 0;
}



t_stack	*allocate_stack(char **str)
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
		//printf("1outside");
		//	printf("inside loop");
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



int	count_elements(t_stack *A)
{
    int count;
	
	count = 0;
    t_stack *current = A;
	//printf("outside");
    while (current != NULL)
    {
	//	printf("1inside");
        count++;
        current = current->next;
    }

    return count;
}


void	check_sorti(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
		
	//t_stack_list stacks;
	if(ac <= 1)
	{
		ft_error_few_arg();
		write(1,"\n",1);
		//return(0);
	}

	else if(ac >= 2)
	{
		*stack_a = allocate_stack(av);
        *stack_b = NULL;
		// if(count_elements(*stack_a) == 1)
		// {	
		// 	printf("\n999ooo22w23");
		// 	//return (0);
		// }
		//printf("2outside");
		ft_radix_sort(&(*stack_a), &(*stack_b));
	}
}

void	ft_free_list(t_stack **lst)
{
    t_stack *temp;
    while (*lst)
    {
        temp = (*lst)->next;
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}


int	main(int ac, char **av)
{	
	t_stack *stack_a;
	t_stack *stack_b;

	//stack_a = NULL;
	stack_b = NULL;

	if(check_av2(ac, av) == 0 && check_av_b(ac,av) == 0 && check_av(av) == 0 )
	{	
		stack_a = allocate_stack(av);
		if (stack_a)
			check_sorti(ac, av,&stack_a, &stack_b);
		ft_free_list(&stack_a);
		ft_free_list(&stack_b); /// da fare la funzione di free
		return (0);	
	}
	else
		return(1);
}



// at the moment if I give in input 1 it goes in segmentaation
// if i give any other number it enters the infinite loop





/*Time Complexity: The provided implementation might end up
with a high time complexity due to the multiple passes through
the list for each digit. An efficient radix sort implementation
typically processes each digit once, resulting in a time complexity
of O(d * (n + k)), where n is the number of elements, d is the number
of digits in the largest number, and k is the base (in this case, k=10).*/

