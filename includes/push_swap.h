/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:03:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/02 13:05:45 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <stdlib.h> // for functions free, exit
# include "../lib/libft/libft.h"
//# include "../lib/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int					nbr;
//	int					index;
	struct s_stack		*next;
//	struct s_stack		*pre;
}	t_stack;

// process_arg
t_stack		*process_args(int argc, char **argv);
t_stack		*sub_process(char *str);
int			ft_atoi_v2(char *str);
int			is_duplicated(t_stack *stack);

// sort_ascending
void		sort_ascending(t_stack **stack_a);
t_stack		*push_sort_b(t_stack **stack_a);
t_stack		**push_sort_a(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack);
void		sort_till_3(t_stack **stack_a, t_stack **stack_b);

// sort_move
void		move_to_b(t_stack **stack_a, t_stack ** stack_b, int num);
void		move_to_a(t_stack **stack_a, t_stack ** stack_b, int num);

// sort_move_assit
int			find_cheapeast_num_to_b(t_stack *a, t_stack *b);
int			find_cheapeast_num_to_a(t_stack *a, t_stack *b);
int			caculate_step_to_b(t_stack *a, t_stack *b, int num);
int			caculate_step_to_a(t_stack *a, t_stack *b, int num);

// operations_swap_push
void		swap(t_stack **s, int direction, int if_print);
void		push(t_stack **depa, t_stack **dest, int direction, int if_print);

// operations_rotate
void		rotate(t_stack **s, char direction, int if_print);
void		rotate_rr(t_stack **stack_a, t_stack **stack_b, int if_print);
void		rev_rotate(t_stack **s, char direction, int if_print);
void		rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int if_print);

// operation_combs
void		execute_rarb(t_stack **stack_a, t_stack **stack_b, int num, int direction);
void		execute_rrarrb(t_stack **stack_a, t_stack **stack_b, int num, int direction);
void		execute_rrarb(t_stack **stack_a, t_stack **stack_b, int num, int direction);
void		execute_rarrb(t_stack **stack_a, t_stack **stack_b, int num, int direction);

// util_basic
void		free_stack(t_stack **stack);
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
int			find_place_in_stack_b(t_stack *stack_a, int nbr_push);
int			find_place_in_stack_a(t_stack *stack_b, int nbr_push);

#endif
