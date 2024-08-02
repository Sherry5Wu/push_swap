/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_assit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:55:28 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/02 11:42:58 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	This function to find the cheapest cost num to push to stack_b from stack_a.
	It is used when pushing from stack_a to stack_b.
*/
int		find_cheapeast_num_to_b(t_stack *a, t_stack *b)
{
	int		steps;
	int		chepest_n;

	steps = caculate_step_to_b(a, b, a -> nbr);
	chepest_n = a -> nbr;
	while (a)
	{
		if (steps > caculate_step_to_b(a, b, a -> nbr))
			chepest_n = a -> nbr;
		a = a -> next;
	}
	return (chepest_n);
}
/*
	This function to find the cheapest cost num to push to stack_a from stack_b.
	It is used when pushing from stack_b to stack_a.
*/
int		find_cheapeast_num_to_a(t_stack *a, t_stack *b)
{
	int		steps;
	int		chepest_n;

	steps = caculate_step_to_a(a, b, b -> nbr);
	chepest_n = b -> nbr;
	while (b)
	{
		if (steps > caculate_step_to_a(a, b, b -> nbr))
			chepest_n = b -> nbr;
		b = b -> next;
	}
	return (chepest_n);
}

/*
	To caculate if pushing num from stack_a to stack_b, how many steps is needed.
*/
int		caculate_step_to_b(t_stack *a, t_stack *b, int num)
{
	int		index_a;
	int		index_b;

	index_a = find_index(a, num);
	index_b = find_place_in_stack_b(b, num);
	if (index_a < ( stack_size(a) / 2) && index_b < (stack_size(b) / 2))
	{
		if (index_a > index_b)
			return(index_a);
		else
			return(index_b);
	}
	else if (index_a > (stack_size(a) / 2) && index_b < (stack_size(b) / 2))
		return((stack_size(a) - index_a) + index_b);
	else if (index_a < (stack_size(a) / 2) && index_b > (stack_size(b) / 2))
		return(index_a + (stack_size(b) - index_b));
	else
	{
		if (index_a > index_b)
			return(index_a);
		else
			return(index_b);
	}
}

/*
	To caculate if pushing num from b to a, how many steps is needed.
*/
int		caculate_step_to_a(t_stack *a, t_stack *b, int num)
{
	int		index_a;
	int		index_b;

	index_a = find_place_in_stack_a(a, num);
	index_b = find_index(b, num);
	if (index_a < ( stack_size(a) / 2) && index_b < (stack_size(b) / 2))
	{
		if (index_a > index_b)
			return(index_a);
		else
			return(index_b);
	}
	else if (index_a > (stack_size(a) / 2) && index_b < (stack_size(b) / 2))
		return((stack_size(a) - index_a) + index_b);
	else if (index_a < (stack_size(a) / 2) && index_b > (stack_size(b) / 2))
		return(index_a + (stack_size(b) - index_b));
	else
	{
		if (index_a > index_b)
			return(index_a);
		else
			return(index_b);
	}
}
