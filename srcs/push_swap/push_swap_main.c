/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:38:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/29 14:42:28 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	https://medium.com/@ayogun/push-swap-c1f5d2d41e97
	https://github.com/ayogun/push_swap/blob/main/includes/push_swap.h
	https://github.com/48d31kh413k/1337-push_swap-42/blob/main/src/quicksort.c
	https://github.com/LeeSinLiang/Push-Swap/tree/main/srcs
*/
int		main(int ac, char **av)
{
	t_stack		*a;

	a = process_args((ac), av);
	if (!a || is_duplicated(a))
	{
		free_stack(a);
		ft_error();
	}
	if (!is_sorted(a))
		sort_ascending(&a);
	free_stack(&a);
	exit(0);
}
