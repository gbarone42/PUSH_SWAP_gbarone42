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

static void	ft_negative_zero(char **av)
{
	int	i;
	int	j;

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

static void	check_number_limits(int ac, char **av)
{
	int		i;
	char	**str;

	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		while (str[++i])
		{
			if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			{
				ft_free_arr(str);
				ft_errorrrrr();
			}
		}
		ft_free_arr(str);
	}
	else
	{
		while (av[++i])
		{
			if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
				ft_errorrrrr();
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
	ft_check_if_sorted(ac, av, args);
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
		j = -1;
		while (args[i][++j])
		{
			ascii = args[i][j];
			if (ft_isdigit_and_sign(ascii))
			{
				ft_errorrr();
				return (1);
			}
		}
		i++;
	}
	return (0);
}
