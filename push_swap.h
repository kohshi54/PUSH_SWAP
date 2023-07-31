/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:39:19 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/07/31 18:56:34 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"
# include "LIBFT/get_next_line.h"

typedef struct stack
{
	long			num;
	size_t			index;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

typedef struct info
{
	t_stack	*head;
	size_t	size;
	size_t	max;
	size_t	min;
}	t_info;

/* ft_operatoin.c */
void	swap(t_stack **list);
void	push(t_stack **list_a, t_stack **list_b);
void	rotate(t_stack **list);
void	reverse_rotate(t_stack **list);
void	swap_a_and_b(t_stack **list_a, t_stack **list_b);

/* ft_operation2.c */
void	swap_b(t_stack **list);
void	swap_a(t_stack **list);
void	push_b(t_info *info_a, t_info *info_b);
void	push_a(t_info *info_a, t_info *info_b);

/* ft_operation3.c */
void	rotate_b(t_stack **list);
void	rotate_a(t_stack **list);
void	rotate_a_and_b(t_stack **list_a, t_stack **list_b);
void	reverse_rotate_b(t_stack **list);
void	reverse_rotate_a(t_stack **list);
void	reverse_rotate_a_and_b(t_stack **list_a, t_stack **list_b);

/* ft_create_list.c */
void	make_stack_b(t_info *info_a, t_info *info_b);
void	make_stack_a(t_info *info_a, char *argv[]);

/* ft_prepare.c */
void	free_all(t_stack *list_a, t_stack *list_b);
void	make_index(t_info *info_a);
void	put_error_and_free_and_exit(t_stack *list);
void	validate_input(t_info info_a);

/* ft_search.c */
int		find_min(t_stack *list);
int		find_max(t_stack *list);
size_t	search_forward(t_stack *list, size_t target);
size_t	search_backward(t_stack *list, size_t target);

/* ft_sort.c */
void	sort_by_input_number(t_info *info_a, t_info *info_b);
size_t	check_if_list_is_sorted(t_info info_a);

/* ft_push_to_a.c */
void	find_largest_and_push_a(t_info *info_a, t_info *info_b);

/* ft_push_to_b.c */
void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, \
											size_t pivot, size_t element);

/* bonus */
void	do_sa(t_stack **list);
void	do_sb(t_stack **list);
void	do_ss(t_stack **list_a, t_stack **list_b);
void	do_pa(t_info *info_a, t_info *info_b);
void	do_pb(t_info *info_a, t_info *info_b);
void	do_ra(t_stack **list);
void	do_rb(t_stack **list);
void	do_rr(t_stack **list_a, t_stack **list_b);
void	do_rra(t_stack **list);
void	do_rrb(t_stack **list);
void	do_rrr(t_stack **list_a, t_stack **list_b);

#endif