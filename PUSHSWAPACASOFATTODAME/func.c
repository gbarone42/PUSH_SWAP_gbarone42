void ft_error_double(void)
{
    printf("\n");
    printf("     /\\_/\\     \n");
    printf("    ( o.o )    \n");
    printf("    > ^ <      \n");
    printf("\n");
    printf("\n\033[1;31mError: DUPLICATE\033[0m\n\n");
    return(1);
}

void ft_error_few_arg(void)
{
    printf("\n");
    printf("     /\\_/\\     \n");
    printf("    ( o.o )    \n");
    printf("    > ^ <      \n");
    printf("\n");
    printf("\n\033[1;31mError: TOO-FEW-ARGS\033[0m\n\n");
    return(1);
}

void ft_error_not_digit(void)
{
    printf("\n");
    printf("     /\\_/\\     \n");
    printf("    ( o.o )    \n");
    printf("    > ^ <      \n");
    printf("\n");
    printf("\n\033[1;31mError: DIGIT-ONLY\033[0m\n\n");
    return(1);
}

/*
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
*/

int ft_isdigit_and_sign(int c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else if ((c == '-' || c == '+') && ft_isdigit_and_sign(c + 1))
    {
        return 1;
    }
    return 0; // Not a digit
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;

	i = 0;
	neg = 0;
	while (*str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if (neg % 2 != 0)
		i = i * -1;
	return (i);
}

int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (int)((unsigned char)*str1 - (unsigned char)*str2);
}