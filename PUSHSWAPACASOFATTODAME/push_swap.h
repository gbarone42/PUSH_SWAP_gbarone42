#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>



int	main(int ac, char **av);
int	check_av_space(int ac, char **av);
int check_doubles(char **str);
void ft_error_double(void);
void ft_error_few_arg(void);
void ft_error_not_digit(void);
void ft_error_double(void);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int ft_strcmp(const char *str1, const char *str2);

#endif
