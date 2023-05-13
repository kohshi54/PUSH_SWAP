/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:36:27 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/12 17:31:08 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_count_of_less_than_pivot(t_stack *list, size_t pivot)
{
	size_t	count;

	count = 0;
	while (list->index)
	{
		if (list->index < pivot)
			count++;
		list = list->next;
	}
	return (count);
}

int	find_nearest_target(t_stack *list, size_t pivot)
{
	t_stack	*backward;

	backward = list->prev->prev;
	while (list->index != backward->index)
	{
		if (list->index < pivot)
			return (list->index);
		if (backward->index < pivot)
			return (backward->index);
		list = list->next;
		backward = backward->prev;
	}
	return (list->index);
}

void	execute_optimized_rotate_b(t_info *info_a, t_info *info_b, \
									size_t size, size_t pivot)
{
	size_t		target;

	target = find_nearest_target(info_a->head, pivot);
	if (size && search_forward(info_a->head, target) \
					<= search_backward(info_a->head, target))
		rotate_a_and_b(&(info_a->head), &(info_b->head));
	else
		rotate_b(&(info_b->head));
}

void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, \
											size_t pivot, size_t element)
{
	size_t	size;
	size_t	target;

	size = get_count_of_less_than_pivot(info_a->head, pivot + element);
	while (size--)
	{
		target = find_nearest_target(info_a->head, pivot + element);
		if (search_forward(info_a->head, target) \
				<= search_backward(info_a->head, target))
		{
			while (info_a->head->index != target)
				rotate_a(&(info_a->head));
		}
		else
			while (info_a->head->index != target)
				reverse_rotate_a(&(info_a->head));
		push_b(info_a, info_b);
		if (info_b->head->index < (pivot - (element / 2)) \
			|| (pivot < info_b->head->index \
			&& info_b->head->index < pivot + (element / 2)))
		{
			execute_optimized_rotate_b(info_a, info_b, size, pivot + element);
		}
	}
}
