#include "push_swap.h"
/*
int get_msd(int num) {
    int msd = 0;
    while (num != 0) {
        msd = num % 10;
        num /= 10;
    }
    return msd;
}*/

int get_msd(int num, int digit) {
    int divisor = 1;
    int i = 1;
    while (i < digit) {
        divisor *= 10;
        i++;
    }
    int msd = (num / divisor) % 10;
    return msd;
}

int num_digits(int num) {
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

void ft_pb(t_stack **stack_a, t_stack **stack_b) {
    t_stack *tmp;

    if (*stack_a == NULL)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}
/*
void ft_ra(t_stack **stack_a) {
    t_stack *last;
    t_stack *first;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    last = *stack_a;
    first = *stack_a;
    while (last->next != NULL)
        last = last->next;
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}*/

void ft_ra(t_stack **stack_a) {
    t_stack *last;
    t_stack *first;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return; // If the stack is empty or has only one element, there is no need to rotate

    last = *stack_a;
    first = *stack_a;
    while (last->next != NULL)
        last = last->next;
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

// Helper function to check if a stack is sorted in ascending order
int is_sorted(t_stack *stack) {
    while (stack && stack->next) {
        if (stack->content > stack->next->content)
            return 0;
        stack = stack->next;
    }
    return 1;
}

// The Radix Sort function
void ft_radix_sort(t_stack **stack_a, t_stack **stack_b) {
    int max_digits = 0;
    int i;
    stack_b = NULL;
    // Find the number with the maximum digits in the stack_a
    t_stack *current = *stack_a;
    while (current)
    {
        int digits = num_digits(current->content);
        if (digits > max_digits)
            max_digits = digits;
        current = current->next;
    }
    printf("FINALMax Digits: %d\n", max_digits);
    
    //The code will now sort the array based on each digit's position 
    //from the least significant digit to the most significant digit.
    // Perform sorting based on digits
    i = 1;
    while (i <= max_digits)  //Looping over digits from least significant to most significant
    {
        t_stack *current = *stack_a;
        t_stack *next;
        while (current) //Looping over array elements to sort them based on the current digit
        {
            next = current->next;
            int msd = get_msd(current->content, i);
            if (msd == i)
            {
                ft_pb(stack_a, stack_b); // Move the current element to stack_b
                current = *stack_a; // Restart the iteration from the beginning
            }
            else
            {
                printf("oooo\n");
                ft_ra(stack_a); // Rotate the stack to bring next element to the top
            }
            current = next;
        }
        // Move elements from stack_b back to stack_a
        while (*stack_b)
        {
            ft_pa(stack_b, stack_a);
        }

        i++;
    }

    // Check if the stack is sorted in ascending order
    if (is_sorted(*stack_a))
        printf("The stack is sorted!\n");
    else
        printf("The stack is not sorted correctly!\n");

        
}