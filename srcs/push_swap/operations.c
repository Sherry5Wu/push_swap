/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:36:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/18 14:57:14 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap the top two elements in the stack.
// do nothing if there is only one or empty or null poiter.
void	swap(t_stack **s)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s) -> next)
		return ;
	tmp = *s;
	(*s) = (*s) -> next;
	tmp -> next = (*s) -> next;
	(*s) -> next = tmp;
	free_node(tmp);
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
	free_node(tmp);
}

void	rotate(t_stack **s)
{
	
}

void	rev_rotate(t_stack **s)
{
	
}