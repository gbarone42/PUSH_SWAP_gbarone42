#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "ft_printf"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
} t_stack;

typedef struct s_stack_list
{
	t_stack		*a;
	t_stack		*b;
} t_stack_list;

t_stack	*allocate_stack(char **str);
int	main(int ac, char **av);
int	check_av(int ac, char **av);
//
//
void ft_error(void);
void ft_error_few_arg(void);
//
//
int	ft_atoi(const char *str);
static char	*stralloc(const char *str, int start, int finish);
static int	wordcount(const char *str, char c);
char	**ft_split(const char *s, char c);
void ft_free_args(char **str_array);
//
//
int digitsandsignsvalid(const char *str);
int duplicates(int ac, char **av);
int ft_strcmp(const char *str1, const char *str2);
int check_duplicate(char **str);
int	ft_isdigit_and_sign(int c);


#endif