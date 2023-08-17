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
	int i = 0;
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



t_stack *allocate_stack(char **str)
{
    int i;
    t_stack *head = NULL;
    t_stack *current = NULL;
    t_stack *prev = NULL;

    i = 1;
    if (!str || !str[0])
        return NULL;
    while (str[i])
    {           
        current = malloc(sizeof(t_stack));
        if (!current)
            return (NULL);
        current->content = ft_atoi(str[i]);
        current->next = NULL;
        if (!head)
            head = current;
        if (prev)
            prev->next = current;
        prev = current;
        
        printf("Allocated element with content: %d\n", current->content);
        
        i++;
    }
    return (head);
}


void sort_five_elements(t_stack **stack_a, t_stack **stack_b)
{
    int total_elements = count_elements(*stack_a);

    while (total_elements > 3)
    {
        if ((*stack_a)->content < 3) // Assuming the numbers are between 0 and 4
        {
            ft_pb(stack_a, stack_b); // Push the smallest elements to stack B
        }
        else
        {
            ft_ra(stack_a); // Rotate if the element is not part of the smallest group
        }

        total_elements--;
    }

    sort_three_elements(stack_a); // Sort the remaining elements on stack A

    while (*stack_b)
    {
        ft_pa(stack_a, stack_b); // Push back the elements from stack B to stack A
    }
}


void sort_three_elements(t_stack **stack_a)
{
    if ((*stack_a)->next->content > (*stack_a)->next->next->content)
        ft_rra(stack_a);
    if ((*stack_a)->content > (*stack_a)->next->content)
    {
        ft_sa(stack_a);
        sort_three_elements(stack_a);
    }
}


void    sort_two_elements(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        printf("abhul");
        if ((*stack_a)->content > (*stack_a)->next->content)
        {
            ft_sa(stack_a); // Swap the top two elements
        }
    }
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
		 if(count_elements(*stack_a) == 1)
		 {	
		 	printf("\n 1 number");
		 	exit(1);
		 }
		else if(count_elements(*stack_a) == 2)
		{
			printf("\n 2 numbers choosen");
			sort_two_elements(stack_a);
			exit(1);
		}
		else if(count_elements(*stack_a) == 3)
		{
			sort_three_elements(stack_a);
			//printf("\n 3 numbers");
			//exit(1);
		}
		else if(count_elements(*stack_a) == 5)
		{
            sort_five_elements(stack_a, stack_b);
			//printf("\n 5 numbers ");
			exit(1);
		}
		else
		{
		ft_radix_sort(&(*stack_a), &(*stack_b));
		}
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
    stack_a = allocate_stack(av);

	if(check_av2(ac, av) == 0 && check_av_b(ac,av) == 0 && check_av(av) == 0 )
	{	
		//stack_a = allocate_stack(av);
		if (stack_a)
			check_sorti(ac, av,&stack_a, &stack_b);
		ft_free_list(&stack_a);
		ft_free_list(&stack_b); /// da fare la funzione di free
		return (0);	
	}
	else
		return(1);
}

/*Time Complexity: The provided implementation might end up
with a high time complexity due to the multiple passes through
the list for each digit. An efficient radix sort implementation
typically processes each digit once, resulting in a time complexity
of O(d * (n + k)), where n is the number of elements, d is the number
of digits in the largest number, and k is the base (in this case, k=10).*/


/*
void    sort_two_elements(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
		//printf("sjsjs");
if ((*stack_a)->content > (*stack_a)->next->content)
{
    printf("Condition met: %d > %d\n", (*stack_a)->content, (*stack_a)->next->content);
    ft_sa(stack_a); // Swap the top two elements
    printf("Elements swapped.\n");
}
else
{
    printf("Condition not met: %d <= %d\n", (*stack_a)->content, (*stack_a)->next->content);
}
    }
} 
*/