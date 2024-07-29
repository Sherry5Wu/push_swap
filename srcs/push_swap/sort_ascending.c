/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:33 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/29 14:42:19 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Algorithm:
	- push everything from STACK_A to STACK_B but in descending order.Why? Because
	  after I push them back to STACK_A, they will be automatically sorted.

	- Stacks are kind of circular linked list. It means, the last element of the
	  stack is actually not the last element. It is actually an element before the
	  first element.

	-  If the number you push from STACK_A to STACK_B is going to be the new biggest
	   or the smallest number, you should place it just above the old biggest number
	   in the STACK_B.
*/
void	sort_ascending(t_stack **stack_a)
{
	t_stack		*stack_b;

	// since there are only two elements, and the order is wrong. so what needs to do
	// is just simply swap stack a.
	if (ft_lstsize(stack_a) == 2)
		//ft_sa(stack_a, 0);

}
