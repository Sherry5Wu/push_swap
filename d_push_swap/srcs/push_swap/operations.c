/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:36:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/30 09:11:51 by jingwu           ###   ########.fr       */
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
		if_print = 0, output;
		if_print is not 0, don't output.
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
	if (if_print == 0)
	{
		if (stack_name == 1)
			write(1, "sa\n", 3);
		else if (stack_name  == 2)
			write(1, "sb\n", 3);
	}
}

/*
	push the first element from stack depa(departure) to the top of stack dest(destination)
	do nothing if depa or dest is null pointer or if depa is empty.

	stack_name;
		stack_name = 1, represents output "pa";
		stack_name = 2, represents output "pb";

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	push(t_stack **depa, t_stack **dest, int stack_name, int if_print)
{
	t_stack		*tmp;

	if (!depa || !dest || !*depa)
		return ;
	tmp = (*depa) -> next;
	tmp -> next = *dest;
	*dest = tmp;
	if (if_print == 0)
	{
		if (stack_name == 1)
			write(1, "pa\n", 3);
		else if (stack_name  == 2)
			write(1, "pb\n", 3);
	}
}

/*
	Shift up all elements of a stack by 1. The first element becomes the last one.
	If there is less than 2 elements, then return.

	stack_name;
		stack_name = 1, represents output "ra";
		stack_name = 2, represents output "rb";

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	rotate(t_stack **s, char stack_name, int if_print)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s) -> next)
		return ;
	tmp = *s;
	while (*s)
		*s = (*s) -> next;
	(*s) -> next = tmp;
	*s = tmp -> next;
	tmp -> next = 0;
	if (if_print == 0)
	{
		if (stack_name == 1)
			write(1, "ra\n", 3);
		else if (stack_name  == 2)
			write(1, "rb\n", 3);
	}
}

/*
	Shift down all elements of a stack by 1. The last element becomes the first one.
	If there is less than 2 elements, then return.

	stack_name;
		stack_name = 1, represents output "rra";
		stack_name = 2, represents output "rrb";

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	rev_rotate(t_stack **s, char stack_name, int if_print)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s) -> next)
		return ;
	tmp = *s;
	while (*s)
		*s = (*s) -> next;
	((*s) -> pre) -> next = 0;
	(*s) -> next = tmp;
	if (if_print == 0)
	{
		if (stack_name == 1)
			write(1, "rra\n", 3);
		else if (stack_name  == 2)
			write(1, "rrb\n", 3);
	}
}
