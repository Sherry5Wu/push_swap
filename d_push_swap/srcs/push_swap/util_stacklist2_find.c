/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stacklist2_find.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:25:43 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/30 14:29:14 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
