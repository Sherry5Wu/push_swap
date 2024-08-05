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
	t_stack		*k = malloc(sizeof(t_stack));
	k ->nbr = 15;
	k ->next = NULL;

	t_stack		*j = malloc(sizeof(t_stack));
	j ->nbr = 18;
	j ->next = k;

	t_stack		*i = malloc(sizeof(t_stack));
	i ->nbr = 12;
	i ->next = j;

	t_stack		*h = malloc(sizeof(t_stack));
	h ->nbr = 11;
	h ->next = i;

	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 10;
	f ->next = h;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 17;
	e ->next = NULL;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 4;
	d ->next = e;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 3;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 5;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 7;
	a ->next = b;

	printf("stack_a:\n\t");
	print_stack(a);
	printf("stack_b:\n\t");
	print_stack(f);
	execute_rarrb(&a, &f, 5, 1);
	printf("stack_a:\n\t");
	print_stack(a);
	printf("stack_b:\n\t");
	print_stack(f);
}
