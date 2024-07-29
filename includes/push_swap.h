/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:03:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/29 14:48:12 by jingwu           ###   ########.fr       */
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

// operations
void		swap(t_stack **s, char stack_name, int if_print);
void		push(t_stack **depa, t_stack **dest);
void		rotate(t_stack **s, char stack_name, int if_print);
void		rev_rotate(t_stack **s, char stack_name, int if_print);

// util_functions
void		free_stack(t_stack **node);
void		free_str(char **str);
void		ft_error(void);
int			is_sorted(t_stack *stack);

#endif
