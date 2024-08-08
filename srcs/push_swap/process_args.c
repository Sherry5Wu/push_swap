/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:20:29 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/08 09:09:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


#include <stdio.h>

int		is_duplicated(t_stack *stack)
{
	t_stack		*tmp_outer;
	t_stack		*tmp_inner;

	if (!stack || !(stack -> next))
		return (0);
	tmp_outer = stack;
	while (tmp_outer)
	{
		tmp_inner = tmp_outer -> next;
		while(tmp_inner)
		{
			if ((tmp_outer -> nbr) == (tmp_inner -> nbr))
				return (1);
			tmp_inner = tmp_inner -> next;
		}
		tmp_outer = tmp_outer -> next;
	}
	return (0);
}

/*
	sub_process is to split (seperator is space) *str to **str, then add each valid
	integer into stack a.
*/
void	sub_process(char *str, t_stack **a)
{
	char		**split_str;
	int			i;
	int			j;

	i = 0;
	split_str = ft_split(str, 32);
	if (!split_str)
	{
		free_stack(a);
		exit(1);
	}
	while (split_str[i])
	{
		j = ft_atoi_v2(split_str[i]);
		stack_add_back(a, stack_newnode(j));
		i++;
	}
	free_str(split_str);
//	free(split_str); // ????? why double freed split_str here???????
}

/*
	upgrade version of ft_atoi, it will call ft_error() when the error is found.
	Here it will show error:
	- when there is non-integer characters;
	- when it is overflow.
*/
int		ft_atoi_v2(char *str)
{
	long long int	num;
	long long int	integer;
	int				sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		num = num * 10 + *str - '0';
		str++;
	}
	integer = num * sign;
	if (integer > 2147483647 || integer < -2147483648)
		ft_error();
//	printf("integer=%lld\n", integer);  // remember to delete the line.
	return (integer);
}

/*
	Function process_args will do three things:
	1. return error if the the number of argument is less than 2;
	2. call sub_process if the number of argument is 2;
	3. ELse, changing each arument into integer and added them at the end of the stack.

	Return value:
	It will return a empty stack if the argument is less than 2. Otherwise, it will return
	a pointer point to the beginning of stack a .
*/
t_stack	*process_args(int argc, char **argv)
{
	t_stack		*a;
	int			i;
//	int			j;

	a = NULL;
	if (argc < 2)
		exit(1);
	if (argc == 2)
		sub_process(argv[1], &a);
	else
	{
		i = 1;
		while (i < argc)
		{
			sub_process(argv[i], &a);
			i++;
		}
	}
	return (a);
}

