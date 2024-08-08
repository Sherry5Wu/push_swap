/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:41:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/08 15:00:33 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
	operate when the operation is in rra, rrb or rrr condition.
*/
void	check_sub(t_stack **a, t_stack **b, char *operation)
{
	if (operation[2] == 'a')
		rev_rotate(a, 1, 1);
	else if (operation[2] == 'b')
		rev_rotate(b, 2, 1);
	else if (operation[2] == 'r')
		rev_rotate_rrr(a, b, 1);
}

/*
	Check the operations and execute them.
*/
char	*check(t_stack **a, t_stack **b, char *operation)
{
	if (ft_strncmp(operation, "sa\n", ft_strlen(operation)) == 0)
		swap(a, 1, 1);
	else if (ft_strncmp(operation, "sb\n", ft_strlen(operation)) == 0)
		swap(b, 2, 1);
	else if (ft_strncmp(operation, "ss\n", ft_strlen(operation)) == 0)
	{
		swap(a, 1, 1);
		swap(b, 2, 1);
	}
	else if (ft_strncmp(operation, "pa\n", ft_strlen(operation)) == 0)
		push(a, b, 1, 1);
	else if (ft_strncmp(operation, "pb\n", ft_strlen(operation)) == 0)
		push(a, b, 2, 1);
	else if (ft_strncmp(operation, "ra\n", ft_strlen(operation)) == 0)
		rotate(a, 1, 1);
	else if (ft_strncmp(operation, "rb\n", ft_strlen(operation)) == 0)
		rotate(b, 2, 1);
	else if (ft_strncmp(operation, "rr\n", ft_strlen(operation)) == 0)
		rotate_rr(a, b, 1);
	else if (operation[0] == 'r' && operation[1] == 'r' && operation[3] == '\n')
		check_sub(a, b , operation);
	else
		ft_error();
	return (get_next_line(0));
}

/*
	The function is doing:
	- read the instructions from standard input(meaning from the terminal) and execute
	  them;
	- After execute all the instructions check if the stack_b is empty. If it is empty
	  print"KO";
	- Check if stack_a is sorted. If it isn't sorted, then print "KO";
	- Other conditions, print "OK"
*/
void	checker_sub(t_stack **a, t_stack **b, char *operation)
{
	char	*tmp;

	while (operation && *operation != '\n')
	{
		tmp = operation;
		operation = check(a, b, operation);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(operation);
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		*operation;

	a = process_args((ac), av);
	b = NULL;
	if (!a || is_duplicated(a))
	{
		free_stack(&a);
		write(1, "Duplicated numbers\n", 19); ??????
	}
	operation = get_next_line(0);
	if (!operation && ) ??????
	checker_sub(&a, &b, operation);

	free_stack(&a);
	free_stack(&b);
	exit(0);
}
