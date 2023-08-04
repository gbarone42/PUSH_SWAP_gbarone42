/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:14:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/08/03 19:16:04 by gbarone          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "push_swap.h"



void free_split(char **split)
{
    if (!split)
        return;

    // Free each individual string
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }

    // Free the array of pointers
    free(split);
}

/// 
int check_av2(char **av)
{
        char **args = ft_split(av[1], ' ');
        if (!args)
        {
            ft_error();
            return 1;
        }

        int i = 0;
        while (args[i])
        {
            if (!check_duplicate(&args[i]))
            {
				//printf("sono");
				free_split(args);
                ft_errorr();
				//printf("sono")
                return 1;
            }
			int j = 0;
		while (args[i][j])
		{
            int ascii = args[i][j];
			//printf("sono");
            if (ft_isdigit_and_sign(ascii))
            {
				//printf("sono");
				free_split(args);
                ft_errorrr();
                return 1;
            }
            j++;
		}
		i++;
	}
        free_split(args);
	return(0);
}


int check_av(char **av)
{
	//printf("sonoduen9");
	int i = 0;
	while(av[i])
	{
    	if (!check_duplicate(&av[i]))
    	{	
			   ft_errorrrr();
		   	return 1;
		}
		i++;
	}
    return 0;
}
/*
int check_av(char **av)
{
	    char **args = ft_split(*av, ' ');
        if (!args)
        {
			
            ft_error();
            return 1;
        }

    int i = 0;

   while (args[i])
    {
		if (!check_duplicate(args))
        {   

			printf("ooook");
			free_split(args);
            ft_errorrrr();
            return 1;
        }
        int j = 0;
        while (args[i][j])
        {
            int ascii = args[i][j];
            if (ft_isdigit_and_sign(ascii))
            {
				free_split(args);
                ft_errorrrrr();
                return 1;
            }
            j++;
        }
        i++;
    }
	free_split(args);
    return 0;
}

*/




t_stack *allocate_stack(char **str)
{
	int i;
	t_stack *head = NULL;
	t_stack *current = NULL;
	t_stack *prev = NULL;

	i = 0;
	if (!str || !str[0])// Handle the case of an empty input or NULL pointer
        return NULL;
	while (str[i])//till its !(NULL), till encounters NULLpointer // linked list is built during the loop
	{
		current = malloc(sizeof(t_stack));//size of memory block is determined by the size  oft_stack structure representing a node in the linked list.
		if (!current) // After allocating memory for the current node, the function checks if the allocation was successful by verifying if current is not NULL. If the allocation fails (current is NULL), the function returns NULL, indicating that there was a memory allocation failure. This can be handled later in the program if needed.
			return (NULL); // Handle allocation failure, or you can exit the program
		current->content = ft_atoi(str[i]);
		current->next = NULL;
		if (!head) // means we are at the beginning of the list, since this is the first node
			head = current; // Set head if it's not set already
		if (prev)
			prev->next = current; // Link the previous node to the current node
		prev = current; // Move the previous pointer to the current node
		i++;
	}
	return (head);
}

int count_elements(t_stack *A)
{
    int count;
	
	count = 0;
    t_stack *current = A;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}




int check_av_b(int ac, char **av)
{
    int i = 1; // Start from 1 to skip the program name (av[0])
    while (i < ac)
    {
        int j = 0;
        while (av[i][j] != '\0')
        {
			//printf("wwww");
            int ascii = av[i][j];
            if (ft_isdigit_and_sign(ascii))
            {
				printf("zxwwzwwwaax");
				ft_errorrrrr();
				return 1;
            }
            j++;
        }
        i++;
    }

    return 0;
}



int main(int ac, char **av)
{
	t_stack_list stacks;
	if(ac <= 1)
	{
		ft_error_few_arg();
		return(1);
	}
	stacks.a = allocate_stack(av);
	stacks.b = NULL;
	if(ac == 2)
	{
		check_av2(av);
		return(0);
	}
	if (ac > 1 && ac != 2) //(ac > 2)
	{	
		check_av(av);
		check_av_b(ac,av);
		//return (0);
	}
	printf("ooo22w23");
	if(count_elements(stacks.a) == 1)
	{
		free(stacks.a);
		return (0);
	}
	else
	ft_radix_sort(&(stacks.a), &(stacks.b));
	return(0);
}


