/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:19:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/30 14:31:13 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **node)
{
	t_list	*tmp;

	if (!node || !(*node))
		return ;
	while (*node)
	{
		tmp = (*node) -> next;
		(*node) -> nbr = 0;
		free(*node);
		*node = tmp;
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

// fd = 2, is for standard error
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*
	Return value:
		1:	sorted;
		0:	not sorted;
*/
int		is_sorted(t_stack *stack)
{
	t_stack		*tmp;

	if (!stack || (stack -> next))
		return (1);
	tmp = stack;
	while (tmp)
	{
		if (tmp -> nbr > (tmp ->next) -> nbr)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
