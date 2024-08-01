/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_caculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:55:28 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/01 14:08:15 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	This function calculate and decides which rotation combination is best to
	use to sort the stack. Of course, after rotation there is always one push
	operation is left to do which i embeded to code.

	It is used when pushing from stack_a to stack_b.
*/
// int		caculator_rotate_atob(t_stack *stack_a, t_stack *stack_b)
// {
// 	int			steps;
// 	t_stack		*tmp;

// 	tmp = stack_a;
// 	steps = case_rrarrb(stack_a, stack_b, stack_a -> nbr);
// 	??????

// }
int		find_cheapeast_num(t_stack *a, t_stack *b)
{
	int		steps;
	int		chepest_n;

	steps = caculate_step(a, b, a -> nbr, 1);
	chepest_n = a -> nbr;
	while (a)
	{
		if (steps > caculate_step(a, b, a -> nbr, 1))
			chepest_n = a -> nbr;
		a = a -> next;
	}
	return (chepest_n);
}
// the function is for pushing a element from stack_a to stack_b
void	move_to_b(t_stack **stack_a, t_stack ** stack_b, int num)
{
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;

	index_a = find_index(stack_a, num);
	index_b = find_place_in_stack_b(stack_b, num);
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	if (index_a < ( size_a / 2) && index_b < (size_b / 2))
		execute_rarb(stack_a, stack_b, num, 1);
	else if (index_a > (size_a / 2) && index_b < (size_b / 2))
		excute_rrarb(stack_a, stack_b, num, 1);
	else if (index_a < (size_a / 2) && index_b > (size_b / 2))
		excute_rarrb(stack_a, stack_b, num, 1);
	else
		excute_rrarrb(stack_a, stack_b, num, 1);

}
/*
	To caculate if pushing num from a to b (or from b to a), how many steps is needed.

	direction:
	 1: pushing from a to b;
	 otherwise, pushing from b to a.
*/
int		caculate_step(t_stack *a, t_stack *b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;

	if (direction == 1)
	{
		index_a = find_index(a, num);
		index_b = find_place_in_stack_b(b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(a, num);
		index_b = find_index(b, num);
	}
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (index_a < ( size_a / 2) && index_b < (size_b / 2))
		return(index_a + index_b);
	else if (index_a > (size_a / 2) && index_b < (size_b / 2))
		return((size_a - index_a) + index_b);
	else if (index_a < (size_a / 2) && index_b > (size_b / 2))
		return(index_a + (size_b - index_b));
	else
		return((size_a - index_a) + (size_b - index_b));
}
