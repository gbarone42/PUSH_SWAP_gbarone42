/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/31 23:00:08 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_doubles(char **str)
{
    int a = 0;
    int b;
    
    while (str[a])//as long as the element at index a in the array str is not NULL 
    {
        b = a + 1;
        while (str[b])
        {
            if (ft_strcmp(str[a], str[b]) == 0)
                return (0); // Found a duplicate, return 0
            b++;
        }
        a++;
    }
    return (1); // No duplicates found, return 1
}

int	check_av_space(int ac, char **av)
{
	char **args;


	if(ac <= 1)
		ft_error_few_arg();
	else if (ac == 2)
	{	args = ft_split(av[1],' ');
		if(check_doubles(args))
		{	
			//freememory allocated by split
			//free args?
			ft_error_double();
		}
		//freememory allocated by split
		//free args?
		return(0);
	}
	else
	{
		if(check_doubles(av))
			ft_error_double();
	}
	return(0);
}

int	main(int ac, char **av)
{	
	int args;

	if(check_av_space(ac, av))
		return (1);
	args = ft_atoi(av);
	if(!ft_isdigit(args))
		ft_error_not_digit();
}
