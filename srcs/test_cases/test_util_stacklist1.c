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

	print_stack(a);

	stack_add_back(&c, stack_newnode(11));
	print_stack(a);
	printf("size=%d\n",stack_size(a));

	free_stack(&a);
	return (1);
}
