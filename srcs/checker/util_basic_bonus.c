/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_basic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:19:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 14:05:30 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)-> next;
		(*stack)-> nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	free_str(char **str)
{
	char	*tmp;

	if (!str || !(*str))
		return ;
	while (*str)
	{
		tmp = *str;
		str++;
		free(tmp);
	}
	*str = NULL;
}

/*
	The fucntion is for print error message and exit the program.

	Type:
		1: non-integer found, print message "Must be all numbers" and change to newline;
		2: input is overflowed, print message "Input is overflowed" and change to newline;
		3: dupicated nummbers, print message "Duplicated numbers" and change to newline;
		4: the input instruction is wrong, print message "Instruction is not correct" and change to newline;
*/
void	ft_error(int type)
{
	if (type == 1)
		write(1, "Must be all numbers\n", 20);
	else if (type == 2)
		write(1, "Input is overflowed\n", 20);
	else if (type == 3)
		write(1, "Duplicated numbers\n", 19);
	else if (type == 4)
		write(1, "Instruction is not correct\n", 27);
	exit(1);
}

/*
	the order should be in ascending.
	Attention:
		when while loop the stack, the condtion should be "tmp -> next != NULL",
		 not "tmp != NULL"
	Return value:
		1:	sorted;
		0:	not sorted;
*/
int		is_sorted(t_stack *stack)
{
	t_stack		*tmp;

	if (!stack || !(stack -> next))
		return (1);
	tmp = stack;
	while (tmp -> next)
	{
		if (tmp -> nbr > (tmp -> next)-> nbr)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
