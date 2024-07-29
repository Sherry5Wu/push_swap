/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:36:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/29 14:58:34 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	swap the top two elements in the stack.
	do nothing if there is only one or empty or null poiter.

	stack_name;
		stack_name = 1, represents output "sa";
		stack_name = 2, represents output "sb";

	if_print:
		when if_print = 0, meaning need to output, any other values ddn't need output;
*/
void	swap(t_stack **s, int stack_name, int if_print)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s) -> next)
		return ;
	tmp = *s;
	(*s) = (*s) -> next;
	tmp -> next = (*s) -> next;
	(*s) -> next = tmp;
	if (if_print = 1)
	{
		if (stack_name == 1)
			write(1, "ra\n", 3);
		else if (stack_name  == 2)
			write(1, "rb\n", 3);
	}
}

// push the first element from stack depa(departure) to the top of stack dest(destination)
// do nothing if depa or dest is null pointer or if depa is empty.
void	push(t_stack **depa, t_stack **dest)
{
	t_stack		*tmp;

	if (!depa || !dest || !*depa)
		return ;
	tmp = (*depa) -> next;
	tmp -> next = *dest;
	*dest = tmp;
}

void	rotate(t_stack **s, char stack_name, int if_print)
{

}

void	rev_rotate(t_stack **s, char stack_name, int if_print)
{

}
