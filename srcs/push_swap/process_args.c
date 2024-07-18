/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:20:29 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/18 13:34:41 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Function process_args will do two things:
	1. check if the  passed argument valid (non-integer characters, not bigger than integer
		range, and not duplicated)
	2. if the argument is valid, then put them into stack a.

	Return value:
	It will return a empty stack if the argument is not valid. Otherwise, if it will return
	a pointer to stack a.
*/
t_stack		*process_args(int n, char **str)
{
	if (is_all_integer(str) == 0)
		return (0);
	if (is_bigger_than_integer(str) == 1)
		return (0);
	if (is_duplicated(str) == 1)
		return (0);
	return (fill_the_stack(n, str));
}