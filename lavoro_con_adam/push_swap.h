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

// typedef struct s_stack_list
// {
// 	t_stack		*a;
// 	t_stack		*b;
// } t_stack_list;


t_stack	*allocate_stack(char **str);
int	main(int ac, char **av);
int	check_av(char **av);
int check_av_b(int ac, char **av);
//
//
void ft_error(void);
void ft_error_few_arg(void);
void ft_errorr(void);
//
//
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*stralloc(const char *str, int start, int finish);
int	wordcount(const char *str, char c);
char	**ft_split(const char *s, char c);
//
//
int digitsandsignsvalid(const char *str);
int duplicates(int ac, char **av);
int ft_strcmp(const char *str1, const char *str2);
int check_duplicate(char **str);
int	ft_isdigit_and_sign(int c);

void move_from_b_to_a(t_stack **stack_a, t_stack **stack_b);
void move_zeros(t_stack **stack_a, t_stack **stack_b);
int num_digits(int num);
int get_msd(int num,int digit);

void free_split(char **split);
int check_av2(char **av);
void ft_errorrrrr(void);
void ft_errorrr(void);
void ft_errorrrr(void);
void print_stack(t_stack *stack);
void print_max_digit(int max_digit);


void ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void radix_sort(t_stack **stack_a, t_stack **stack_b, int num_digits_max);
void counting_sort_digit_rec(t_stack **stack, int digit_place, int num_buckets, int *bucket_count);
void count_occurrences(t_stack **stack, int digit_place, int num_buckets, int *bucket_count);


void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);

void ft_putstr(const char *str);
void ft_putchar(char c);
void ft_lstadd_frontnum(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);


void    ft_lstadd_backnum(t_stack **lst, t_stack *new);

#endif