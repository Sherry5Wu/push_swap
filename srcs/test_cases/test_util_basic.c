#include <stdio.h>
#include "../../includes/push_swap.h"

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

	printf("is_sorted=%d\n",is_sorted(a));
	free_stack(&a);
	return (1);
}
