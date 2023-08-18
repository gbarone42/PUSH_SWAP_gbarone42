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

static void ft_negative_zero(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && av[i][j + 1] == '0')
				ft_errorrrrr();
			j++;
		}
		i++;
	}
}

static void check_number_limits(int ac, char **av)
{
	int i;
	char **str;

	i = 1;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		while (str[i])
		{
			if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			{
				int j = 0;
				while (str[j])
				{
					free(str[j]);
					j++;
				}
				free(str);
				ft_errorrrrr();
			}
			i++;
		}
		int j = 0;
		while (str[j])
		{
			free(str[j]);
			j++;
		}
		free(str);
	}
	else
	{
		while (av[i])
		{
			if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
				ft_errorrrrr();
			i++;
		}
	}
}

int	check_av2(int ac, char **av)
{
	char	**args;
	int		result;
	int		i;
	int		containsnotspace_tab;

	if (!av[1] || av[1][0] == '\0' || ac == 1)
		ft_error_few_arg();
	ft_negative_zero(av);
	check_number_limits(ac, av);
	ft_check_if_sorted(ac, av);
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
		if (validate_args(args) == 1)
			return (1);
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
		{
			ft_errorr();
			return (1);
		}
		j = 0;
		while (args[i][j])
		{
			ascii = args[i][j];
			if (ft_isdigit_and_sign(ascii))
			{
				ft_errorrr();
				return (1);
			}
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
