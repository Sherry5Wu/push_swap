/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:03:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/30 14:55:10 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // for functions free, exit
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int					nbr;
	int					index;
	struct s_stack		*next;
	struct s_stack		*pre;
}	t_stack;

// process_arg
t_stack		*process_args(int argc, char **argv);
t_stack		*sub_process(char *str);
int			ft_atoi_v2(char *str);
int			is_duplicated(t_stack *stack);

// sort_ascending
void		sort_ascending(t_stack **stack_a);
t_stack		*push_sort_b(t_stack **stack_a);
t_stack		**sort_a(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack);
void		sort_till_3(t_stack **stack_a, t_stack **stack_b);

// sort_caculate
int			rotate_caculator_ab(t_stack *stack_a, t_stack *stack_b);

// operations
void		swap(t_stack **s, int stack_name, int if_print);
void		push(t_stack **depa, t_stack **dest, int stack_name, int if_print);
void		rotate(t_stack **s, char stack_name, int if_print);
void		rev_rotate(t_stack **s, char stack_name, int if_print);

// util_basic
void		free_stack(t_stack **node);
void		free_str(char **str);
void		ft_error(void);
int			is_sorted(t_stack *stack);

// util_stacklist1
void		stack_add_back(t_stack **lst, t_stack *new);
t_stack		*stack_last(t_stack *lst);
t_stack		*stack_newnode(int content);
int			stack_size(t_stack *stack);

// util_stacklist2_find
int			min_value(t_stack *stack);
int			max_value(t_stack *stack);
int			find_index(t_stack *stack, int value);



#endif
