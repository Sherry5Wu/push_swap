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
	i ->nbr = 26;
	i ->next = j;

	t_stack		*h = malloc(sizeof(t_stack));
	h ->nbr = 21;
	h ->next = i;

	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 10;
	f ->next = h;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 17;
	e ->next = NULL;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 14;
	d ->next = e;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 13;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 25;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 1;
	a ->next = b;

	printf("stack_a:\n\t");
	print_stack(a);
	printf("stack_b:\n\t");
	print_stack(f);
#if 0
	printf("steps=%d\n\n", find_cheapest_steps_to_b(a, f));

	t_stack *tmp = a;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rarb(a, f, (tmp -> nbr), 1));
		tmp = tmp ->next;
	}
	printf("\n");
	tmp = a;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rrarrb(a, f, (tmp -> nbr), 1));
		tmp = tmp ->next;
	}
	printf("\n");
	tmp = a;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rrarb(a, f, (tmp -> nbr), 1));
		tmp = tmp ->next;
	}
	printf("\n");
	tmp = a;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rarrb(a, f, (tmp -> nbr), 1));
		tmp = tmp ->next;
	}
#endif

	printf("steps=%d\n\n", find_cheapest_steps_to_a(a, f));

	t_stack *tmp = f;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rarb(a, f, (tmp -> nbr), 2));
		tmp = tmp ->next;
	}
	printf("\n");
	tmp = f;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rrarb(a, f, (tmp -> nbr), 2));
		tmp = tmp ->next;
	}
	printf("\n");
	tmp = f;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rarrb(a, f, (tmp -> nbr), 2));
		tmp = tmp ->next;
	}
	printf("\n");
	tmp = f;
	while (tmp)
	{
		printf("for num=%d\tsteps=%d\n\n", tmp -> nbr, if_rrarrb(a, f, (tmp -> nbr), 2));
		tmp = tmp ->next;
	}
}
