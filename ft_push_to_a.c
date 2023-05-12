#include "push_swap.h"

int	find_largest_or_second_largest(t_stack *list, int max)
{
	t_stack	*backward;

	backward = list->prev->prev;
	while (list->index != backward->index)
	{
		if (list->index == max || list->index == (max - 1) || list->index == (max - 2))
			return (list->index);
		if (backward->index == max || backward->index == (max - 1) || backward->index == (max - 2))
			return (backward->index);
		list = list->next;
		backward = backward->prev;
	}
	return (list->index);
}

void	execute_optimized_rotate_a(t_info *info_a, t_info *info_b)
{
	int		target;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	if (search_forward(info_b->head, target) <= search_backward(info_b->head, target))
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
	int		target;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	if (search_forward(info_b->head, target) <= search_backward(info_b->head, target))
	{
		reverse_rotate_a(&(info_a->head));
	}
	else
	{
		reverse_rotate_a_and_b(&(info_a->head), &(info_b->head));
	}
}

void	find_largest_and_push_a(t_info *info_a, t_info *info_b)
{
	int		target;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	if (search_forward(info_b->head, target) <= search_backward(info_b->head, target))
	{
		while (info_b->head->index != target)
			rotate_b(&(info_b->head));
	}
	else
	{
		while (info_b->head->index != target)
			reverse_rotate_b(&(info_b->head));
	}
	push_a(info_a, info_b);
	if (info_a->head->next->index + 1 == info_a->head->next->next->index)
	{
		if (info_a->head->index + 3 == info_a->head->next->index)
		{
			execute_optimized_rotate_a(info_a, info_b);
		}
	}
	else
	{
		if (info_a->head->index - 1 == info_a->head->next->index)
			swap_a(&(info_a->head));
		else
			execute_optimized_rotate_a(info_a, info_b);
	}
	while ((info_a->head->index - 1 == info_a->head->prev->prev->index && (info_a->head->index + 1 == info_a->head->next->index || info_a->head->index == info_a->max)) || info_a->head->index - 2 == info_a->head->prev->prev->index)
		execute_optimized_reverse_rotate_a(info_a, info_b);
}
