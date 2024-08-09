/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:48:38 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 14:12:47 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS.H
# define CHECKER_BONUS.H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"

# define ARG_MAX_NUM (1025)

typedef struct s_stack
{
	int					nbr;
	struct s_stack		*next;
}	t_stack;

// checker_main_bonus
void		check_sub(t_stack **a, t_stack **b, char *instrcs);
char		*check(t_stack **a, t_stack **b, char *instrcs);
void		checker(t_stack **a, t_stack **b, char *instrcs);

// process_args_bonus
t_stack		*process_args(int argc, char **argv);
void		sub_process(char *str, t_stack **a);
int			ft_atoi_v2(char *str);
int			is_duplicated(t_stack *stack);

// util_basic_bonus
void		free_stack(t_stack **stack);
void		free_str(char **str);
void		ft_error(int type);
int			is_sorted(t_stack *stack);

// operations_swap_push_bonus
void		swap(t_stack **s, int direction, int if_print);
void		push(t_stack **depa, t_stack **dest, int direction, int if_print);

// operations_rotate_bonus
void		rotate(t_stack **s, char direction, int if_print);
void		rotate_rr(t_stack **stack_a, t_stack **stack_b, int if_print);
void		rev_rotate(t_stack **s, char direction, int if_print);
void		rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int if_print);

#endif
