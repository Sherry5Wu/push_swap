/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:03:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/18 14:53:40 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // for free function

typedef struct s_stack
{
	int					nbr;
	int					index;
	struct s_stack		*next;
	struct s_stack		*pre;
}	t_stack;

t_stack		*process_args(int n, char **str);
void		swap(t_stack **s);
void		push(t_stack **depa, t_stack **dest);
void		rotate(t_stack **s);
void		rev_rotate(t_stack **s);
void		*free_node(t_stack **node);

#endif