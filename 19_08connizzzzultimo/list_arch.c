/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:08:27 by naal-jen          #+#    #+#             */
/*   Updated: 2023/08/19 03:58:43 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int	*ft_copy_nums(int i, char **nums, int *arr, long int *new_num)
{
	long int	*a;

	i = -1;
	while (nums[++i])
	{
		a = (long int *)malloc(sizeof(*a));
		if (!a)
			return (0);
		*a = ft_atoi(nums[i]);
		if (*a > (long int)(2147483647) || *a < (long int)(-2147483648))
		{
			free(arr);
			free(new_num);
			ft_free_arr(nums);
			free(a);
			write(1, "Error\n", 6);
			exit(1);
		}
		arr[i] = *a;
		free(a);
		a = NULL;
	}
	return (arr);
}

void	add_tolst(t_stack **stack_a, int size, long int *new_num, int *arr)
{
	int			i;
	long int	*a;

	i = -1;
	while (++i < size)
	{
		a = (long int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = binary_search(arr, new_num[i], 0, size - 1);
		ft_lstadd_back(stack_a, ft_lstnew(a));
	}
}

void	copy_nums(int i, char **av, int *arr, t_hold *hold)
{
	long int	*a;

	i = 0;
	if (!arr)
		return ;
	while (av[++i])
	{
		a = (long int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = ft_atoi(av[i]);
		if (*a > (long int)(2147483647) || *a < (long int)(-2147483648))
		{
			free(a);
			free(arr);
			free(hold);
			write(1, "Error\n", 6);
			exit(1);
		}
		arr[i - 1] = *a;
		free(a);
		a = NULL;
	}
}
