/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/18 19:18:48 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	check_sort(int ac, t_stack **stack_a, t_stack **stack_b)
{
	if (ac <= 1)
	{
		ft_error_few_arg();
		write(1, "\n", 1);
	}
	else if	(ac >= 2)
	{
		//*stack_a = allocate_stack(av);
		*stack_b = NULL;
		if (count_elements(*stack_a) == 1)
			return ;
		else if (count_elements(*stack_a) == 2)
		{
			sort_two_elements(stack_a);
			return ;
		}
		else if (count_elements(*stack_a) == 3)
		{	
			sort_three_elements(stack_a);
		}
		else if (count_elements(*stack_a) == 5)
		{
			sort_five_elements(stack_a, stack_b);
			//return ;
		}
		else
			ft_radix_sort(&(*stack_a), &(*stack_b));
	}
}

static int ft_strlen_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	str = NULL;
	stack_b = NULL;
	if (check_av2(ac, av) == 1 || check_av_b(ac, av) == 1 || check_av(av) == 1)
		exit(1);
	if (ac == 2)
		str = ft_split(av[1], ' ');
	else
		str = (av + 1);
	stack_a = allocate_stack(str);
	// print_stack(stack_a);
	check_sort(ac, &stack_a, &stack_b);
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);

	if (ft_strlen_arr(str) == 1 || ac == 2)
	{
		int i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
		return (0);	
	}
	else
		return (0);	
}

/*

void	check_sorti(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	
	//char **args;
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
*/

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
