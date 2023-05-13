/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:40:09 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/14 02:37:36 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest_or_second_largest(t_stack *list, size_t max)
{
	t_stack	*backward;

	backward = list->prev->prev;
	while (list->index != backward->index)
	{
		if (list->index == max || list->index == (max - 1) \
								|| list->index == (max - 2))
			return (list->index);
		if (backward->index == max || backward->index == (max - 1) \
									|| backward->index == (max - 2))
			return (backward->index);
		list = list->next;
		backward = backward->prev;
	}
	return (list->index);
}

void	execute_optimized_rotate_a(t_info *info_a, t_info *info_b)
{
	size_t	target;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	if (search_forward(info_b->head, target) \
			<= search_backward(info_b->head, target))
	{
		rotate_a_and_b(&(info_a->head), &(info_b->head));
	}
	else
	{
		rotate_a(&(info_a->head));
	}
}

void	execute_optimized_reverse_rotate_a(t_info *info_a, t_info *info_b)
{
	long	target;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	if (search_forward(info_b->head, target) \
				<= search_backward(info_b->head, target))
	{
		reverse_rotate_a(&(info_a->head));
	}
	else
	{
		reverse_rotate_a_and_b(&(info_a->head), &(info_b->head));
	}
}

int	check_put_back_on_top(t_info *info_a)
{
	return ((info_a->head->index - 1 == info_a->head->prev->prev->index \
			&& (info_a->head->index + 1 == info_a->head->next->index \
			|| info_a->head->index == info_a->max)) \
			|| info_a->head->index - 2 == info_a->head->prev->prev->index);
}
*/

void	find_larger_than_pivot_and_push_a(t_info *info_a, t_info *info_b)
{
	size_t	target;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	if (search_forward(info_b->head, target) \
			<= search_backward(info_b->head, target))
		while (info_b->head->index != target)
			rotate_b(&(info_b->head));
	else
		while (info_b->head->index != target)
			reverse_rotate_b(&(info_b->head));
	push_a(info_a, info_b);
	if (info_a->head->next->index + 1 == info_a->head->next->next->index)
	{
		if (info_a->head->index + 3 == info_a->head->next->index)
			execute_optimized_rotate_a(info_a, info_b);
	}
	else
	{
		if (info_a->head->index - 1 == info_a->head->next->index)
			swap_a(&(info_a->head));
		else
			execute_optimized_rotate_a(info_a, info_b);
	}
	while (check_put_back_on_top(info_a))
		execute_optimized_reverse_rotate_a(info_a, info_b);
}
