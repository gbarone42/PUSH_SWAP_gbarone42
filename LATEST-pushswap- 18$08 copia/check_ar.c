/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email@example.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:00:00 by your_username    #+#    #+#             */
/*   Updated: 2023/08/17 00:00:00 by your_username   ###    ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_av2(int ac, char **av)
{
	char	**args;
	int		result;
	int		i;
	int		containsnotspace_tab;

	if (!av[1] || av[1][0] == '\0')
		ft_error_few_arg();
	i = 0;
	containsnotspace_tab = 0;
	while (av[1][i] && !containsnotspace_tab)
	{
		if (av[1][i] != ' ' && av[1][i] != '\t')
			containsnotspace_tab = 1;
		i++;
	}
	if (!containsnotspace_tab)
		ft_error_few_arg();
	args = ft_split(av[1], ' ');
	result = check_av3(args, ac);
	free_split(args);
	return (result);
}

int	check_av3(char **args, int ac)
{
	if (ac == 2)
		validate_args(args);
	return (0);
}

int	validate_args(char **args)
{
	int	i;
	int	j;
	int	ascii;

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
	return (0);
}

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
