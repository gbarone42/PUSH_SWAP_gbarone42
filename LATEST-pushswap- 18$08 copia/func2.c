/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/18 13:06:50 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*allocate_stack(char **str)
{
	int		i;
	t_stack	*head = NULL;
	t_stack	*current = NULL;
	t_stack	*prev = NULL;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i])
	{
		current = malloc(sizeof(t_stack));
		if (!current)
			return (NULL);
		current->content = ft_atoi(str[i]);
		current->next = NULL;
		if (!head)
			head = current;
		if (prev)
			prev->next = current;
		prev = current;
		i++;
	}
	return (head);
}

int	count_elements(t_stack *A)
{
	int		count = 0;
	t_stack	*current = A;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*p;
	int				l;
	int				j;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(l);
	if (!p)
		return (0);
	j = 0;
	i = 0;
	while (s1[i] != 0)
		p[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		p[j++] = s2[i++];
	p[j] = 0;
	return (p);
}
*/