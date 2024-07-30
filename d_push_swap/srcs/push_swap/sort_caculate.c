/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_caculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:55:28 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/30 14:54:55 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	This function calculate and decides which rotation combination is best to
	use to sort the stack. Of course, after rotation there is always one push
	operation is left to do which i embeded to code.

	It is used when pushing from stack_a to stack_b.
*/
int		rotate_caculator_ab(t_stack *stack_a, t_stack *stack_b)
{
	int			steps;
	t_stack		*tmp;

	tmp = stack_a;
	steps = case_rrarrb(stack_a, stack_b, stack_a -> nbr);
	??????

}
