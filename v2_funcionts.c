/*
	The function is using to fine the right place for nbr_push, if we want push nbr_push
	into the stack.

	Parameters:
		stack: the stack where we need find the place in;
		nbr_push: the number we want to push to stack;

	Return value:
		the index of the right place;

	Steps:
		- if the nbr_push is greater than the biggest number or smaller than the smallest
		  number in the stack, then the right place is at the top of biggest number.
		- else, the right place should be at the top of the number which is smaller than
		  nbr_push and most closest to the nbr_push, which means (nbr_push - number) should
		  be smallest.
*/
int		find_place_in_stack(t_stack *stack, int nbr_push)
{
	int		index;
	t_stack	*tmp;
	int		differ;

	tmp = stack;
	if (nbr_push > max_value(stack) || nbr_push < min_value(stack))
		index = find_index(stack, max_value(stack));
	else
	{
		differ = nbr_push - (min_value(stack));
		index = find_index(stack, min_value(stack));
		while (tmp)
		{
			if (nbr_push > (tmp -> nbr) && (differ > (nbr_push - (tmp -> nbr))))
			{
				differ = nbr_push - (tmp -> nbr);
				index = find_index(stack, tmp -> nbr);
			}
			tmp = tmp -> next;
		}
	}
	return (index);
}
