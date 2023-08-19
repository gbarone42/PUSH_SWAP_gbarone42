/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:20:45 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/19 03:59:21 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int arr[], int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(arr, i, j);
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

int	binary_search(int a[], int e, int l, int r)
{
	int	mid;

	mid = l + (r - l) / 2;
	if (a[mid] == e)
		return (mid);
	else if (a[mid] > e)
		return (binary_search(a, e, l, mid - 1));
	else
		return (binary_search(a, e, mid + 1, r));
}

static void	helper(int size, char **nums)
{
	if (size == 1)
	{
		ft_free_arr(nums);
		exit(1);
	}
}

void	create_list(char **av, t_stack **stack_a)
{
	char		**nums;
	int			i;
	long int	*new_num;
	int			*arr;
	int			size;

	i = 0;
	size = 0;
	nums = ft_split(av[1], ' ');
	while (nums[size])
		size++;
	helper(size, nums);
	arr = (int *)malloc(sizeof(int) * size);
	new_num = (long int *)malloc(sizeof(long int) * size);
	if (!new_num || !arr)
		return ;
	arr = ft_copy_nums(i, nums, arr, new_num);
	i = -1;
	while (++i < size)
		new_num[i] = arr[i];
	quick_sort(arr, 0, size - 1);
	add_tolst(stack_a, size, new_num, arr);
	free(arr);
	free(new_num);
	ft_free_arr(nums);
}

void	create_lists(int ac, char **av, t_stack **stack_a, t_hold *hold)
{
	int		i;
	int		*new_num;
	int		*arr;

	i = -1;
	arr = (int *)malloc(sizeof(int) * ac - 1);
	copy_nums(i, av, arr, hold);
	new_num = (int *)malloc(sizeof(int) * ac - 1);
	if (!new_num)
		return ;
	while (++i < ac - 1)
		new_num[i] = arr[i];
	quick_sort(arr, 0, ac - 2);
	i = -1;
	while (++i < ac - 1)
	{
		hold->num = (long int *)malloc(sizeof(long int));
		if (!hold->num)
			return ;
		*hold->num = binary_search(arr, new_num[i], 0, ac - 2);
		ft_lstadd_back(stack_a, ft_lstnew(hold->num));
	}
	free(arr);
	free(new_num);
}
