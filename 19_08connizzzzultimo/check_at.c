/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email@example.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:00:00 by your_username    #+#    #+#             */
/*   Updated: 2023/08/17 00:00:00 by your_username   ###    ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!check_duplicate(&av[i]))
		{
			ft_errorrrr();
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_av_b(int ac, char **av)
{
	int	i;
	int	j;
	int	ascii;

	if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				ascii = av[i][j];
				if (ft_isdigit_and_sign(ascii))
				{
					ft_errorrrrr();
					return (1);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}
