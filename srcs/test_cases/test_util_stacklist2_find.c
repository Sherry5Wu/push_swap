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
# if 0
// test case for min_value(), max_value() and find_index().
int		main(void)
{
	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 2;
	f ->next = NULL;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 12;
	e ->next = f;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 10;
	d ->next = e;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 1;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 5;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 6;
	a ->next = b;

	print_stack(a);
	printf("min=%d\nmax=%d\n",min_value(a), max_value(a));
	printf("index_min=%d\nindex_max=%d\n",find_index(a, min_value(a)), find_index(a, max_value(a)));
	printf("index=%d\n", find_index(a, 2));
	free_stack(&a);
	return (1);
}
#endif

// test case for find_place_in_stack_b and find_place_in_stack_a.
int		main(void)
{
	t_stack		*i = malloc(sizeof(t_stack));
	i ->nbr = 7;
	i ->next = NULL;

	t_stack		*h = malloc(sizeof(t_stack));
	h ->nbr = 2;
	h ->next = i;

	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 13;
	f ->next = h;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 7;
	e ->next = NULL;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 10;
	d ->next = e;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 1;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 5;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 9;
	a ->next = b;

	printf("stack_a:\n\t");
	print_stack(a);

	printf("push_num=%d\nindex_in_b=%d\n\n", 13, find_place_in_stack_b(a, 13)); 
	printf("push_num=%d\nindex_in_a=%d\n", 8, find_place_in_stack_a(a, 8));

	free_stack(&a);
	free_stack(&f);
	return (1);
}

