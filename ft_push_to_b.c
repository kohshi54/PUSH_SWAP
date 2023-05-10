#include "push_swap.h"

size_t	get_count_of_less_than_pivot(t_stack *list, int pivot)
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

int	find_nearest_target(t_stack *list, int pivot)
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

void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, int pivot, int element)
{
	size_t	size;
	int		target;

	size = get_count_of_less_than_pivot(info_a->head, pivot + element);
	while (size--)
	{
		target = find_nearest_target(info_a->head, pivot + element);
			if (search_forward(info_a->head, target) <= search_backward(info_a->head, target))
		{
			while (info_a->head->index != target)
				rotate_a(&(info_a->head));
		}
		else
		{
			while (info_a->head->index != target)
				reverse_rotate_a(&(info_a->head));
		}
		push_b(info_a, info_b);
		if (info_b->head->index < (pivot - (element / 2)))
		{
			rotate_b(&(info_b->head));
		}
		else if (pivot < info_b->head->index && info_b->head->index < pivot + (element / 2))
		{
			rotate_b(&(info_b->head));
		}
	}
}

/*
void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, int pivot, int element)
{
	size_t	size;
	int		target;

	size = get_count_of_less_than_pivot(info_a->head, pivot);
	while (size--)
	{
		target = find_nearest_target(info_a->head, pivot);
		if (search_forward(info_a->head, target) <= search_backward(info_a->head, target))
		{
			while (info_a->head->index != target)
				rotate_a(&(info_a->head));
		}
		else
		{
			while (info_a->head->index != target)
				reverse_rotate_a(&(info_a->head));
		}
		push_b(info_a, info_b);
		if (info_b->head->index < (pivot - (element / 2)))
			rotate_b(&(info_b->head));
	}
}
*/