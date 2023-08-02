#include "push_swap.h"

/*
int ft_isdigit_and_sign(int c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else if ((c == '-' || c == '+') && ft_isdigit_and_sign(c + 1))
    {
        return 1; // return(0)
    }
    return 0; // Not a digit
}
*/
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

static int	wordcount(const char *str, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*stralloc(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof (char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	int		l;
	size_t	j;
	char	**split;

	split = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	i = 0;
	l = -1;
	j = 0;
	if (!split || !s)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && l < 0)
			l = i;
		else if ((s[i] == c || s[i] == '\0') && l >= 0)
		{
			split[j++] = stralloc(s, l, i);
			l = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


void ft_free_args(char **str_array)
{
    if (str_array)
    {
        int i = 0;
        while (str_array[i])
        {
            free(str_array[i]);
            i++;
        }
        free(str_array);
    }
}


