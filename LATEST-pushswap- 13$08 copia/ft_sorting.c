
#include "push_swap.h"

void ft_pa(t_stack **stack_b, t_stack **stack_a) {
    t_stack *tmp;

    if (*stack_b == NULL)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);
}


 void ft_pb(t_stack **stack_a, t_stack **stack_b)
 {
     t_stack *tmp;

     if (*stack_a == NULL)
         return;
     tmp = *stack_a;
     *stack_a = (*stack_a)->next;
     tmp->next = *stack_b;
     *stack_b = tmp;
     write(1, "pb\n", 3);
 }


void ft_ra(t_stack **stack_a) {
    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return; // If the stack is empty or has only one element, there is no need to rotate
    
    t_stack *first = *stack_a;
    *stack_a = first->next;
    first->next = NULL;
    
    t_stack *current = *stack_a;
    while (current->next != NULL)
        current = current->next;
    current->next = first;
    
    write(1, "ra\n", 3);
}


int count_elements(t_stack *A)
{
    int count = 0;
    t_stack *current = A;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("Number of elements: %d\n", count); // Print the count
    return count;
}

static int	countbits(int num)
{
	int	count;

	count = 1;
	while (num && count++)
		num >>= 1;
	return (count);
}


void ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int nb = countbits(count_elements(*stack_a) - 1);
    int i;
    int size;

    i = 0;
    while (i < nb)
    {
        size = count_elements(*stack_a);
        while (size--)
        {
            if (((*stack_a)->content) & (1 << i))
                ft_ra(stack_a);
            else
                ft_pb(stack_a, stack_b);
        }
        size = count_elements(*stack_b);
        while (size--)
            ft_pa(stack_a, stack_b);

        i++;
    }
}