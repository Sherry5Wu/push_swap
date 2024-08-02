/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:28 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/02 11:42:27 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	using rotate operation in both stacks.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
void	execute_rarb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while ((*stack_a) -> nbr != num && find_index(stack_b, num) > 0)
			rotate_rr(stack_a, stack_b, 0);
		while ((*stack_a) -> nbr != num)
			rotate(stack_a, 1, 0);
		while (find_index(stack_b, num) > 0)
			rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while ((*stack_b) -> nbr != num && find_index(stack_a, num) > 0)
			rotate_rr(stack_a, stack_b, 0);
		while ((*stack_b) -> nbr != num)
			rotate(stack_b, 2, 0);
		while (find_index(stack_a, num) > 0)
			rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
}
/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	using rev_rotate operation in both stacks.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
void	execute_rrarrb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while ((*stack_a) -> nbr != num && find_place_in_stack_b(stack_b, num) > 0)
			rev_rotate_rrr(stack_a, stack_b, 0);
		while ((*stack_a) -> nbr != num)
			rev_rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(stack_b, num) > 0)
			rev_rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while ((*stack_b) -> nbr != num && find_index(stack_a, num) > 0)
			rev_rotate_rrr(stack_a, stack_b, 0);
		while ((*stack_b) -> nbr != num)
			rotate(stack_b, 2, 0);
		while (find_index(stack_a, num) > 0)
			rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
}

/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	for stack_a, using rev_rotate operation, for stack_b, using rotate operation.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
void	execute_rrarb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while ((*stack_a) -> nbr != num)
			rev_rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(stack_b, num) > 0)
			rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while ((*stack_b) -> nbr != num)
			rotate(stack_b, 2, 0);
		while (find_place_in_stack_a(stack_a, num) > 0)
			rev_rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
}
/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	for stack_a, using rotate operation, for stack_b, using rev_rotate operation.

	direction:
		1: from stack_a to stack_b;
		otherwise, from stack_b to stack_a;
*/
void	execute_rarrb(t_stack **stack_a, t_stack **stack_b, int num, int direction)
{
	if (direction == 1)
	{
		while ((*stack_a) -> nbr != num)
			rotate(stack_a, 1, 0);
		while (find_place_in_stack_b(stack_b, num) > 0)
			rev_rotate(stack_b, 2, 0);
		push(stack_a, stack_b, 2, 0);
	}
	else
	{
		while ((*stack_b) -> nbr != num)
			rev_rotate(stack_b, 2, 0);
		while (find_place_in_stack_a(stack_a, num) > 0)
			rotate(stack_a, 1, 0);
		push(stack_b, stack_a, 1, 0);
	}
}
