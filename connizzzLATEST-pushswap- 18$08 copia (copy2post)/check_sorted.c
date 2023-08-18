#include "push_swap.h"

static int	ft_check_sorted_one(char **av)
{
	int		i;
	int		size;
	char	**str;

	i = 0;
	str = ft_split(av[1], ' ');
	while (str[i])
		i++;
	size = i;
	i = 0;
	while (i < size - 1)
	{
		if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
		{
            int j = -1;
            while (str[++j])
                free(str[j]);
            free(str);
			return (1);
		}
		i++;
	}
    int k = -1;
    while (str[++k])
        free(str[k]);
    free(str);
	return (0);
}

static int	ft_check_sorted_two(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_if_sorted(int ac, char **av)
{
	int	res;

	res = 1;
	if (ac == 2)
		res = ft_check_sorted_one(av);
	else if (ac > 2)
		res = ft_check_sorted_two(ac, av);
	if (res == 0)
        exit(1);
    return (res);
}