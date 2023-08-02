void ft_error(void)
{
    ft_printf("\n");
    ft_printf("     /\\_/\\     \n");
    ft_printf("    ( o.o )    \n");
    ft_printf("    > ^ <      \n");
    ft_printf("\n");
    ft_printf("\n\033[1;31mError\033[0m\n\n");
    ft_exit(1);
}

void ft_error_few_arg(void)
{
    ft_printf("\n");
    ft_printf("     /\\_/\\     \n");
    ft_printf("    ( o.o )    \n");
    ft_printf("    > ^ <      \n");
    ft_printf("\n");
    ft_printf("\n\033[1;31mError: TOO-FEW-ARGS\033[0m\n\n");
    exit(1);
}
