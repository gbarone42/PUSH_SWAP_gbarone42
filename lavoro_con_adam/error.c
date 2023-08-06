#include "push_swap.h"


void ft_error_few_arg(void)
{
    write(1, "\n\033[1;31mError\033[0m\n\n", 20);
    write(1, "4  (\\___/)           \n", 24);
    write(1, "   (='.'=)           \n", 24);
    write(1, "   (\")_(\")          2\n", 24);
    write(1, "\n\033[1;31mError00\033[0m\n\n", 22);
    write(1, "\n", 2);
    exit(1);
}

void ft_error(void)
{
    write(1, "\n", 1);
    write(1, "\n\033[1;31mError\033[0m\n\n", 19);
    write(1, "     /\\_/\\     \n", 16);
    write(1, "    ( o.o )    \n", 16);
    write(1, "    > ^ <    42\n", 16);
    write(1, "\n", 1);
    write(1, "\n\033[1;31mError01\033[0m\n\n", 21);
    write(1, "\n", 1);
    exit(1);
}


void ft_errorr(void)
{
    write(1, "\n", 1);
    write(1, "\n\033[1;31mError\033[0m\n\n", 19);
    write(1, "      ><(((°>      \n", 22);
    write(1, "    <°)))><       \n", 21);
    write(1, "   >°)))><        \n", 20);
    write(1, "  <°)))><         \n", 19);
    write(1, " ><°)))><          \n", 18);
    write(1, "       ><(((°>    \n", 22);
    write(1, " 42      <°)))><  \n", 21);
    write(1, "\n\033[1;31mError2\033[0m\n\n", 21);
    write(1, "\n", 1);
    exit(1);
}

void ft_errorrr(void)
{
    write(1, "\n", 1);
    write(1, "\n\033[1;31mError\033[0m\n\n", 19);
     write(1, " 4       <°)))><  \n", 21);
    write(1, "    /\\_/\\     \n", 17);
    write(1, "   ( o.o )    \n", 16);
    write(1, "   (> ^ <)      <°)))><  \n", 28);
    write(1, "  /      \\   2  \n", 18);
    write(1, " / /~~~~\\ \\  \n", 18);
    write(1, "/_/      \\_\\   \n", 20);
    write(1, "\n", 1);
    write(1, "\n\033[1;31mError03\033[0m\n\n", 21);
    write(1, "\n", 1);
    exit(1);
}

void ft_errorrrr(void)
{
  write(1, "\n", 2);
    write(1, "   <°)))><       \n", 20);
    write(1, "\n\033[1;31mError\033[0m\n\n", 20);
    write(1, "     /\\_/\\     \n", 17);
    write(1, "    ( o.o )    \n", 17);
    write(1, "    > ^ <    42\n", 17);
    write(1, "\n", 2);
    write(1, "\n\033[1;31mError04\033[0m\n\n", 22);
    write(1, "\n", 1);
    exit(1);
}

void ft_errorrrrr(void)
{
    write(1, "\n", 1);
    write(1, "\n\033[1;31mError\033[0m\n\n", 19);
    write(1, "     ><(((°>    \n", 19);
    write(1, "       <°)))><  \n", 18);
    write(1, "     /\\___/\\      \n", 21);
    write(1, " /  O O  \\       \n", 19);
    write(1, "( == ^ == )    2 \n", 19);
    write(1, "   )      (     \n", 17);
    write(1, "  /        \\   \n", 18);
    write(1, " /          \\  \n", 19);
    write(1, "/_ _ _ _ _ _\\ \n", 18);
    write(1, "     ><(((°>    \n", 19);
    write(1, " 4     <°)))><  \n", 18);
    write(1, "\n\033[1;31mError05\033[0m\n\n", 21);
    write(1, "\n", 1);
    exit(1);
}

void print_stack(t_stack *stack)
{
    printf("Stack: ");
    t_stack *current = stack;
    while (current != NULL)
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
}

void print_max_digit(int max_digit) 
{
    printf("Max Digit: %d\n", max_digit);
}