#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
} t_stack;
/*
typedef struct s_stack_list
{
	t_stack		*a;
	t_stack		*b;
} t_stack_list;
*/

t_stack	*allocate_stack(char **str);
int	main(int ac, char **av);
int	check_av(char **av);
int check_av_b(int ac, char **av);
int	validate_args(char **args);
int	count_elements(t_stack *A);
//

void    sort_two_elements(t_stack **stack_a);
void    sort_three_elements(t_stack **stack_a);
void	sort_five_elements(t_stack **stack_a, t_stack **stack_b);
//
void ft_error(void);
void ft_error_few_arg(void);
void ft_errorr(void);
//
//
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int	wordcount(const char *str, char c);
char	*stralloc(const char *str, int start, int finish);
char	**ft_split(const char *s, char c);
//
//
int digitsandsignsvalid(const char *str);
int duplicates(int ac, char **av);
int ft_strcmp(const char *str1, const char *str2);
int check_duplicate(char **str);
int	ft_isdigit_and_sign(int c);

void ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void move_from_b_to_a(t_stack **stack_a, t_stack **stack_b);
void move_zeros(t_stack **stack_a, t_stack **stack_b);
int num_digits(int num);
int get_msd(int num);

void free_split(char **split);
int check_av2(int ac, char **av);
int	check_av3(char **args, int ac);
void ft_errorrrrr(void);
void ft_errorrr(void);
void ft_errorrrr(void);
void print_stack(t_stack *stack);
void print_max_digit(int max_digit);

void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_sa(t_stack **stack_a);
void	ft_rra(t_stack **stack_a);

#endif