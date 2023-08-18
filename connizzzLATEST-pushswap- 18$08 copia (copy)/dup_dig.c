/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_dig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:00:00 by your_username    #+#    #+#             */
/*   Updated: 2023/08/17 10:00:00 by your_username   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digits_and_signs_valid(const char *str)
{
	int	is_valid;

	is_valid = 1;
	while (*str)
	{
		if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		{
			is_valid = 0;
			return (is_valid);
		}
		str++;
	}
	return (is_valid);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((int)((unsigned char)*str1 - (unsigned char)*str2));
}

int	duplicates(int ac, char **av)
{
	int	index;
	int	flag;
	int	num2;
	int	num1;
	int	next_index;

	index = 1;
	flag = 0;
	while (index < ac && flag == 0)
	{
		num1 = ft_atoi(av[index]);
		next_index = index + 1;
		while (next_index < ac)
		{
			num2 = ft_atoi(av[next_index]);
			if (num1 == num2)
			{
				flag = 1;
				return (1);
			}
			next_index++;
		}
		index++;
	}
	return (flag);
}

int	check_duplicate(char **str)
{
	int	a;
	int	b;

	a = 0;
	while (str[a])
	{
		b = a + 1;
		while (str[b])
		{
			if (ft_strcmp(str[a], str[b]) == 0)
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	ft_isdigit_and_sign(int c)
{
	if (c == '-' || c == '+')
		return (0);
	else if (c >= 48 && c <= 57)
		return (0);
	return (1);
}
