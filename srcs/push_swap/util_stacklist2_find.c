/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stacklist2_find.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:25:43 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/08 08:06:08 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// find the minimum value in a stack
int		min_value(t_stack *stack)
{
	int			min;
	t_stack		*tmp;

	tmp = stack -> next;
	min = stack -> nbr;
	while (tmp)
	{
		if (min > tmp -> nbr)
			min = tmp -> nbr;
		tmp = tmp -> next;
	}
	return (min);
}

int		max_value(t_stack *stack)
{
	int			max;
	t_stack		*tmp;

	tmp = stack -> next;
	max = stack -> nbr;
	while (tmp)
	{
		if (max < tmp -> nbr)
			max = tmp -> nbr;
		tmp = tmp -> next;
	}
	return (max);
}

int		find_index(t_stack *stack, int value)
{
	int			index;
	t_stack		*tmp;

	index = 0;
	tmp = stack;
	while (tmp && (tmp -> nbr) != value)
	{
		tmp = tmp -> next;
		index++;
	}
	return (index);
}

/*
	The function is using to fine the right place in stack_b for nbr_push, if we want
	push nbr_push into the stack_b.(In stack_b, the order is ascending.)

	Parameters:
		stack_a: the stack where we need find the place in;
		nbr_push: the number we want to push to stack;

	Return value:
		the index of the right place;

	Steps:
		- if the nbr_push is greater than the biggest number or smaller than the smallest
		  number in the stack, then the right place is at the top of biggest number.
		- else  the right place should be between num_a and num_b, that
		"num_a > nbr_push > num_b".
		  	-- we can loop the stack the find the right place, but the loop will miss one
			   condition, that is when num_a is the first number and num_b is the last
			   number, so we need to use a seperate "if" for checking this condition.
*/
int		find_place_in_stack_b(t_stack *stack, int nbr_push)
{
	int		index;
	t_stack	*tmp;

	index = 1;
	if (nbr_push > max_value(stack) || nbr_push < min_value(stack))
		index = find_index(stack, max_value(stack));
	else if (nbr_push > (stack -> nbr) && nbr_push < (stack_last(stack) -> nbr))
		index = 0;
	else
	{
		tmp = stack-> next;
		while (tmp && (nbr_push > (stack -> nbr) || nbr_push < (tmp -> nbr)))
		{
			stack = stack -> next;
			tmp = tmp -> next;
			index++;
		}
	}
	return (index);
}
/*
	The function is using to fine the right place in stack_a for nbr_push, if we want
	push nbr_push into the stack_a.(In stack_a, the order is descending.)

	Parameters:
		stack_a: the stack where we need find the place in;
		nbr_push: the number we want to push to stack;

	Return value:
		the index of the right place;

	Steps:
		- if the nbr_push is greater than the biggest number or smaller than the smallest
		  number in the stack, then the right place is at the top of smallest number.
		- else, the right place should be between num_a and num_b, that num_a < nbr_push,
		  and num_b > nbr_push.
		  	-- we can loop the stack the find the right place, but the loop will miss one
			   condition, that is when num_a is the first number and num_b is the last
			   number, so we need to use a seperate "if" for checking this condition.
*/
int		find_place_in_stack_a(t_stack *stack, int nbr_push)
{
	int		index;
	t_stack	*tmp;

	index = 1;
	if (nbr_push > max_value(stack) || nbr_push < min_value(stack))
		index = find_index(stack, min_value(stack));
	else if (nbr_push < (stack -> nbr) && nbr_push > (stack_last(stack) -> nbr))
		index = 0;
	else
	{
		tmp = stack-> next;
		while (tmp && (nbr_push < (stack -> nbr) || nbr_push > (tmp -> nbr)))
		{
			stack = stack -> next;
			tmp = tmp -> next;
			index++;
		}
	}
	return (index);
}
