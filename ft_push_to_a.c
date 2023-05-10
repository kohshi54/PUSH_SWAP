#include "push_swap.h"

int	find_largest_or_second_largest(t_stack *list, int max)
{
	t_stack	*backward;

	backward = list->prev->prev;
	while (list->index != backward->index)
	{
		if (list->index == max || list->index == (max - 1) || list->index == (max - 2))
			return (list->index);
		if (backward->index == max || backward->index == (max - 1) || list->index == (max - 2))
			return (backward->index);
		list = list->next;
		backward = backward->prev;
	}
	return (list->index);
}

void swap_second_and_third(t_info *info_a, t_info *info_b)
{
	int		target;
	bool	forward;

	target = find_largest_or_second_largest(info_b->head, info_b->max);
	forward = search_forward(info_b->head, target) <= search_backward(info_b->head, target);
	if (forward)
		rotate_a_and_b(&(info_a->head), &(info_b->head));
	else
		rotate_a(&(info_a->head));
	swap_a(&(info_a->head));
	if (forward)
		reverse_rotate_a(&(info_a->head));
	else
		reverse_rotate_a_and_b(&(info_a->head), &(info_b->head));
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
	if (info_a->head->next->index != 0 && info_a->head->next->index < info_a->head->index)
		swap_a(&(info_a->head));
	if (info_a->head->next->next != 0 && info_a->head->next->next->index < info_a->head->next->index)
		swap_second_and_third(info_a, info_b);
}

/*
void	find_largest_and_push_a(t_info *info_a, t_info *info_b)
{
	size_t	size;
	int		target;

	size = info_b->size;
	while (size--)
	{
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
		if (info_a->head->next->index != 0 && info_a->head->next->index < info_a->head->index)
			swap_a(&(info_a->head));
	}
}
*/
