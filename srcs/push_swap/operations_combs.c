/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:28 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/05 13:24:49 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	the function is for pushing a num from a stack to the other one(a to b,
	or b to a), and push it to the correct place, using rotate operation in
	both stacks.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
int		execute_rarb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while (*stack_a && (*stack_a) -> nbr != num && find_place_in_stack_b(*stack_b, num) > 0)
			rotate_rr(stack_a, stack_b, 0);
		while (*stack_a && (*stack_a) -> nbr != num)
			rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(*stack_b, num) > 0)
			rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while (*stack_b && (*stack_b) -> nbr != num && find_place_in_stack_a(*stack_a, num) > 0)
			rotate_rr(stack_a, stack_b, 0);
		while (*stack_b && (*stack_b) -> nbr != num)
			rotate(stack_b, 2, 0);
		while (find_place_in_stack_a(*stack_a, num) > 0)
			rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
	return (-1);
}
/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	and push it to the correct place, using rev_rotate operation in both stacks.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
int		execute_rrarrb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while (*stack_a && (*stack_a) -> nbr != num && find_place_in_stack_b(*stack_b, num) > 0)
			rev_rotate_rrr(stack_a, stack_b, 0);
		while (*stack_a && (*stack_a) -> nbr != num)
			rev_rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(*stack_b, num) > 0)
			rev_rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while (*stack_b && (*stack_b) -> nbr != num && find_place_in_stack_a(*stack_a, num) > 0)
			rev_rotate_rrr(stack_a, stack_b, 0);
		while (*stack_b && (*stack_b) -> nbr != num)
			rev_rotate(stack_b, 2, 0);
		while (find_place_in_stack_a(*stack_a, num) > 0)
			rev_rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
	return (-1);
}

/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	for stack_a, and push it to the correct place, using rev_rotate operation,
	for stack_b, using rotate operation.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
int		execute_rrarb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while (*stack_a && (*stack_a) -> nbr != num)
			rev_rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(*stack_b, num) > 0)
			rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while (*stack_b && (*stack_b) -> nbr != num)
			rotate(stack_b, 2, 0);
		while (find_place_in_stack_a(*stack_a, num) > 0)
			rev_rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
	return (-1);
}
/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	for stack_a, and push it to the correct place, using rotate operation, for
	stack_b, using rev_rotate operation.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
int		execute_rarrb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while (*stack_a && (*stack_a) -> nbr != num)
			rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(*stack_b, num) > 0)
			rev_rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while (*stack_b && (*stack_b) -> nbr != num)
			rev_rotate(stack_b, 2, 0);
		while (find_place_in_stack_a(*stack_a, num) > 0)
			rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
	return (-1);
}
