
#include "push_swap.h"

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	return ;
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	return ;
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*first;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
	return ;
}

int get_msd(int num)
{
    int msd = 0;
    while (num != 0)
    {
		msd = num % 10;
        num /= 10;
    }
    return msd;
}

// Helper function to calculate the number of digits in a number

int num_digits(int num)
{
    if (num == 0)
        return 1;

    int count = 0;
    while (num != 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

// Helper function to move numbers with the current digit equal to 0 to stack B


void move_zeros(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current = *stack_a;
    while (current != NULL)
    {
        int msd = get_msd(current->content);
        printf("Current MSD: %d\n", msd);
        printf("Current Content: %d\n", current->content);
        if (msd == 0)
        {
            printf("22");
            ft_pb(stack_a, stack_b); // Move the element to stack B
            printf("22");
        }
        current = current->next; // Move to the next node in the list
    }
}
// Helper function to move numbers from stack B back to stack A in the correct order
void move_from_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b != NULL)
        ft_pa(stack_b, stack_a);
}



/*
// Custom radix sort implementation
void ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_digit = 0;
    t_stack *current = *stack_a;

    //printf("outside");
    // Find the maximum number to determine the number of digits in the largest number
    while (current != NULL)
    {

      //  printf("1inside");
        int msd = get_msd(current->content);
        if (msd > max_digit)
            max_digit = msd;
        current = current->next;
    }
    print_max_digit(max_digit);

    //printf("2outside");
    int exp = 1;
    while (max_digit >= exp)
    {
        //printf("77777777");
        move_zeros(stack_a, stack_b);
        print_stack(*stack_a);
        print_stack(*stack_b);
        //printf("oooojjwjnnS");
        move_from_b_to_a(stack_a, stack_b);
        print_stack(*stack_a);
        print_stack(*stack_b);
        exp *= 10; // Move to the next digit position
    }
}

*/



// Custom radix sort implementation
void ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_digit = 0;
    t_stack *current = *stack_a;

    // Find the maximum number to determine the number of digits in the largest number
    while (current != NULL)
    {
        int msd = get_msd(current->content);
        if (msd > max_digit)
            max_digit = msd;
        current = current->next;
    }

    int num_digits_max = num_digits(max_digit); // Calculate the number of digits in the largest number

    int exp = 1;
    int i = 0;
    while (i < num_digits_max)
    {
        move_zeros(stack_a, stack_b);
        move_from_b_to_a(stack_a, stack_b);
        exp *= 10;
        i++;
    }
}











/*
#include "push_swap.h"

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	return ;
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	return ;
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*first;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
	return ;
}



int get_msd(int num)
{
    int msd = 0;
    while (num != 0)
    {
		msd = num % 10;
        num /= 10;
    }
    return msd;
}

// Helper function to calculate the number of digits in a number

int num_digits(int num)
{
    int count = 0;
    while (num != 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

// Helper function to move numbers with the current digit equal to 0 to stack B
void move_zeros(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current = *stack_a;
    while (current != NULL)
    {
        int msd = get_msd(current->content);
        if (msd == 0)
            ft_pb(stack_a, stack_b); // Move the element to stack B
        else
            ft_ra(stack_a); // Rotate stack A to the left (to process numbers with non-zero current digit)
        current = *stack_a; // Reinitialize the current pointer after rotation
    }clea
}

// Helper function to move numbers from stack B back to stack A in the correct order
void move_from_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b != NULL)
        ft_pa(stack_b, stack_a);
}

// Custom radix sort implementation
void ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_digit = 0;
    t_stack *current = *stack_a;

    // Find the maximum number to determine the number of digits in the largest number
    while (current != NULL)
    {
        int msd = get_msd(current->content);
        if (msd > max_digit)
            max_digit = msd;
        current = current->next;
    }

    int exp = 1;
    while (max_digit / exp > 0)
    {
        move_zeros(stack_a, stack_b);
        move_from_b_to_a(stack_a, stack_b);
        exp *= 10; // Move to the next digit position
    }
}*/