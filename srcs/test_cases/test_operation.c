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
	t_stack		*h = malloc(sizeof(t_stack));
	h ->nbr = 45;
	h ->next = NULL;

	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 16;
	f ->next = h;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 12;
	e ->next = f;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 10;
	d ->next = NULL;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 8;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 5;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 1;
	a ->next = b;

	// test case for swap();
	// print_stack(c);
	// swap(&c, 1, 0);
	// print_stack(c);

	// test case for push()
	// printf("stack_a:\n\t");
	// print_stack(f);
	// printf("stack_b:\n\t");
	// print_stack(a);
	// push(&f,&a,1, 0);
	// printf("stack_a:\n\t");
	// print_stack(f);
	// printf("stack_b:\n\t");
	// print_stack(a);

	// test case for rotate()
	printf("stack_a:\n\t");
	print_stack(a);
	printf("stack_b:\n\t");
	print_stack(e);
	rev_rotate_rrr(&a, &e, 1);
	rev_rotate_rrr(&a, &e, 1);
	printf("stack_a:\n\t");
	print_stack(a);
	printf("stack_b:\n\t");
	print_stack(e);

//	free_stack(&a);
	return (1);
}
