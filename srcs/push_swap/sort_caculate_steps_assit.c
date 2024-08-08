/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_caculate_steps_assit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:15:25 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/08 08:05:47 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	the fucntion caculates the steps if we push "num" to stack_a(or stack_b)
	only using rotate operation(rarb).

	num: the number we want to push;
	direction:
		1: from stack_a to stack_b;
		non 1 value: from stack_b to stack_a;
*/
int		if_rarb(t_stack *stack_a, t_stack *stack_b, int num, int direction)
{
	int		index_a;
	int		index_b;

	if (direction == 1)
	{
		index_a = find_index(stack_a, num);
		index_b = find_place_in_stack_b(stack_b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(stack_a, num);
		index_b = find_index(stack_b, num);
	}
	if (index_a > index_b)
		return(index_a);
	else
		return(index_b);
}

/*
	the fucntion caculates the steps if we push "num" to stack_a(or stack_b)
	only using rev_rotate operation(rrarrb).

	num: the number we want to push;
	direction:
		1: from stack_a to stack_b;
		non 1 value: from stack_b to stack_a;
*/
int		if_rrarrb(t_stack *stack_a, t_stack *stack_b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		steps_a;
	int		steps_b;

	if (direction == 1)
	{
		index_a = find_index(stack_a, num);
		index_b = find_place_in_stack_b(stack_b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(stack_a, num);
		index_b = find_index(stack_b, num);
	}
	steps_a = stack_size(stack_a) - index_a;
	steps_b = stack_size(stack_b) - index_b;
	if (steps_a > steps_b)
		return(steps_a);
	else
		return(steps_a);
}

/*
	the fucntion caculates the steps if we push "num" to stack_a(or stack_b)
	for stack_a, we use rev_rotate operation;
	for stack_b, we use rotate operation.

	num: the number we want to push;
	direction:
		1: from stack_a to stack_b;
		non 1 value: from stack_b to stack_a;
*/
int		if_rrarb(t_stack *stack_a, t_stack *stack_b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		steps_a;

	if (direction == 1)
	{
		index_a = find_index(stack_a, num);
		index_b = find_place_in_stack_b(stack_b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(stack_a, num);
		index_b = find_index(stack_b, num);
	}
	steps_a = stack_size(stack_a) - index_a;
	return(steps_a + index_b);
}

/*
	the fucntion caculates the steps if we push "num" to stack_a(or stack_b)
	for stack_a, we use rotate operation;
	for stack_b, we use rev_rotate operation.

	num: the number we want to push;
	direction:
		1: from stack_a to stack_b;
		non 1 value: from stack_b to stack_a;
*/
int		if_rarrb(t_stack *stack_a, t_stack *stack_b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		steps_b;

	if (direction == 1)
	{
		index_a = find_index(stack_a, num);
		index_b = find_place_in_stack_b(stack_b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(stack_a, num);
		index_b = find_index(stack_b, num);
	}
	steps_b = stack_size(stack_b) - index_b;
	return(steps_b + index_a);
}
