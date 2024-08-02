/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:42:02 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/02 11:43:02 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// the function is for pushing a element from stack_a to stack_b
void	move_to_b(t_stack **stack_a, t_stack ** stack_b, int num)
{
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;

	index_a = find_index(stack_a, num);
	index_b = find_place_in_stack_b(stack_b, num);
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	if (index_a < ( size_a / 2) && index_b < (size_b / 2))
		execute_rarb(stack_a, stack_b, num, 1);
	else if (index_a > (size_a / 2) && index_b < (size_b / 2))
		excute_rrarb(stack_a, stack_b, num, 1);
	else if (index_a < (size_a / 2) && index_b > (size_b / 2))
		excute_rarrb(stack_a, stack_b, num, 1);
	else
		excute_rrarrb(stack_a, stack_b, num, 1);

}

// the function is for pushing a element from stack_b to stack_a
void	move_to_a(t_stack **stack_a, t_stack ** stack_b, int num)
{
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;

	index_a = find_place_in_stack_a(stack_a, num);
	index_b = find_index(stack_b, num);
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	if (index_a < ( size_a / 2) && index_b < (size_b / 2))
		execute_rarb(stack_a, stack_b, num, 2);
	else if (index_a > (size_a / 2) && index_b < (size_b / 2))
		excute_rrarb(stack_a, stack_b, num, 2);
	else if (index_a < (size_a / 2) && index_b > (size_b / 2))
		excute_rarrb(stack_a, stack_b, num, 2);
	else
		excute_rrarrb(stack_a, stack_b, num, 2);
}
