/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:43:22 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/19 15:21:38 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_hold
{
	long int	*num;
}	t_hold;

// t_stack		*allocate_stack(char **str);
int			main(int ac, char **av);
int			check_av(char **av);
int			check_av_b(int ac, char **av);
int			validate_args(char **args);
int			count_elements(t_stack *A);
void		ft_free_list(t_stack **lst);
void		free_split(char **split);
int			check_av2(int ac, char **av);
int			check_av3(char **args, int ac);
void		sort_three_elements(t_stack **stack_a);
void		sort_five_elements(t_stack **stack_a, t_stack **stack_b);
void		ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_error(void);
void		ft_error_few_arg(void);
void		ft_errorr(void);
void		ft_errorrr(void);
void		ft_errorrrr(void);
void		ft_errorrrrr(void);
long int	ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
int			wordcount(const char *str, char c);
char		*stralloc(const char *str, int start, int finish);
char		**ft_split(const char *s, char c);

int			duplicates(int ac, char **av);
int			ft_strcmp(const char *str1, const char *str2);
int			check_duplicate(char **str);
int			ft_isdigit_and_sign(int c);		
void		ft_pa(t_stack **stack_b, t_stack **stack_a);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a, int print);
void		ft_sa(t_stack **stack_a, int print);
void		ft_rra(t_stack **stack_a, int print);

// new function
int			ft_check_if_sorted(int ac, char **av, char **args);
int			get_index(t_stack *stack, int value);
int			find_min(t_stack *stack);
void		ft_free_arr(char **str);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(void *content);

void		quick_sort(int arr[], int left, int right);
int			binary_search(int a[], int e, int l, int r);
void		create_list(char **av, t_stack **stack_a);
void		create_lists(int ac, char **av, t_stack **stack_a, t_hold *hold);

void		swap(int *arr, int i, int j);
int			*ft_copy_nums(int i, char **nums, int *arr, long int *new_num);
void		add_tolst(t_stack **stack_a, int size, long int *new_num, int *arr);
void		copy_nums(int i, char **av, int *arr, t_hold *hold);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);

#endif