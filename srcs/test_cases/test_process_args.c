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

int		main(int ac, char **av)
{
	t_stack		*a;

	a = process_args((ac), av);
	if (!a || is_duplicated(a))
	{
		free_stack(&a);
		ft_error();
	}
	printf("result stack_a=\n\t");
	print_stack(a);

#if 0
	(void)ac;
	(void)av;
	t_stack		*f = malloc(sizeof(t_stack));
	f ->nbr = 14;
	f ->next = NULL;

	t_stack		*e = malloc(sizeof(t_stack));
	e ->nbr = 1;
	e ->next = f;

	t_stack		*d = malloc(sizeof(t_stack));
	d ->nbr = 10;
	d ->next = e;

	t_stack		*c = malloc(sizeof(t_stack));
	c ->nbr = 5;
	c ->next = d;

	t_stack		*b = malloc(sizeof(t_stack));
	b ->nbr = 5;
	b ->next = c;

	t_stack		*a = malloc(sizeof(t_stack));
	a ->nbr = 12;
	a ->next = b;

	printf("is_duplicated=%d\n",is_duplicated(a));
#endif
	free_stack(&a);
	exit(0);
}
