int digitsandsignsvalid(const char *str)
{
    int isValid = 1;
    while (*str)
	{
        if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		{
            isValid = 0; // Invalid character found, set isValid to 0
            return isValid; // Return 0 (false) immediately
        }
        str++; // Move to the next character
    }
    return isValid; // Return 1 if the string is valid, 0 if it contains invalid characters
}

int duplicates(int ac, char **av)
{
    int index = 1; // Start from the second argument (skip the program name)
    int flag = 0;  // Initialize flag to 0 (no duplicates found)

    while (index < ac && flag == 0)
	{
        int num1 = ft_atoi(av[index]);
        int nextIndex = index + 1;
        while (nextIndex < ac)
		{
            int num2 = ft_atoi(av[nextIndex]);
            if (num1 == num2) 
			{
                flag = 1; // Found a duplicate
                return(1);
            }
            nextIndex++;
        }
        index++;
    }
    return flag;
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

int check_duplicate(char **str)
{
	int a = 0;
	int b;

	while (str[a])
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

int ft_isdigit_and_sign(int c)
{
    if (c == '-' || c == '+')
    {
        return 1; // Treat '-' and '+' as valid sign characters
    }
    else if (c >= '0' && c <= '9')
    {
        return 1; // Digit character
    }
    return 0; // Not a digit or sign
}
