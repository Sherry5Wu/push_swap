#include <stdio.h>
#include "../../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack ->nbr);
		stack = stack ->next;
	}
	printf("\n");
}

int		main(void)
{
	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 16;
	f ->next = NULL;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 12;
	e ->next = f;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 10;
	d ->next = e;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 8;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 5;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 1;
	a ->next = b;

	print_stack(c);
	swap(&c, 1, 0);
	print_stack(c);
//	free_stack(&a);
	return (1);
}

cc -Wall -Wextra -Werror srcs/test_cases/test_operation.c includes/push_swap.h srcs/push_swap/util_basic.c srcs/push_swap/util_stacklist1.c srcs/push_swap/operations_swap_push.c && ./a.out
