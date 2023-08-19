/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/19 04:01:08 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*temp1;

	temp1 = *lst;
	if (!*lst)
		return ;
	while (*lst)
	{
		temp1 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp1;
	}
	*lst = NULL;
}

void	ft_free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

// void	check_sort(int ac, t_stack **stack_a, t_stack **stack_b)
// {
// 	if (ac <= 1)
// 	{
// 		ft_error_few_arg();
// 		write(1, "\n", 1);
// 	}
// 	else if (ac >= 2)
// 	{
// 		*stack_b = NULL;
// 		if (count_elements(*stack_a) == 1)
// 			return ;
// 		else if (count_elements(*stack_a) == 2)
// 		{
// 			sort_two_elements(stack_a);
// 			return ;
// 		}
// 		else if (count_elements(*stack_a) == 3)
// 			sort_three_elements(stack_a);
// 		else if (count_elements(*stack_a) == 5)
// 		{
// 			sort_five_elements(stack_a, stack_b);
// 			return ;
// 		}
// 		else
// 	}
// }

static int	ft_strlen_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_hold	*hold;
	char	**str;

	str = NULL;
	stack_b = NULL;
	stack_a = NULL;
	if (check_av2(ac, av) == 1 || check_av_b(ac, av) == 1 || check_av(av) == 1)
		exit(1);
	if (ac == 2)
		str = ft_split(av[1], ' ');
	else
		str = (av + 1);
	// stack_a = allocate_stack(str);
	if (ac == 2)
		create_list(av, &stack_a);
	else if (ac > 2)
	{
		hold = (t_hold *)malloc(sizeof(t_hold));
		if (!hold)
			return (0);
		create_lists(ac, av, &stack_a, hold);
	}
	if (count_elements(stack_a) <= 5)
		sort_five_elements(&stack_a, &stack_b);
	else
		ft_radix_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	if (ac > 2)
		free(hold);
	if (ft_strlen_arr(str) == 1 || ac == 2)
	{
		ft_free_arr(str);
		return (0);
	}
	else
		return (0);
}
