#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
} t_stack;

typedef struct s_inter
{
	t_stack		*a;
	t_stack		*b;
} t_inter;

t_stack	*allocate_stack(char **str);
int	main(int ac, char **av);
int	check_av_space(int ac, char **av);
int check_duplicate(char **str);
void ft_error(void);
void ft_error_few_arg(void);
int ft_strcmp(const char *str1, const char *str2);
int	ft_isdigit_and_sign(int c);
int	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);

#endif