#include "push_swap.h"

size_t	get_count_of_less_than_pivot(t_info *info_a, int pivot)
{
	t_stack	*list;
	size_t	count;

	list = info_a->stack_head;
	count = 0;
	while (list->coordinate)
	{
		if (list->coordinate < pivot)
			count++;
		list = list->next;
	}
	return (count);
}

int	find_nearest_target(t_info *info_a, int pivot)
{
	t_stack	*forward;
	t_stack	*backward;

	forward = info_a->stack_head;
	backward = info_a->stack_head->prev->prev;
	while (forward->coordinate != backward->coordinate)
	{
		if (forward->coordinate < pivot)
			return (forward->coordinate);
		if (backward->coordinate < pivot)
			return (backward->coordinate);
		forward = forward->next;
		backward = backward->prev;
	}
	return (0);
}

void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, int pivot, int element)
{
	size_t	size;
	int		target;

	size = get_count_of_less_than_pivot(info_a, pivot);
	while (size--)
	{
		target = find_nearest_target(info_a, pivot);
		if (search_forward(info_a, target) <= search_backward(info_a, target))
		{
			while (info_a->stack_head->coordinate != target && target)
			{
				rotate_a(&(info_a->stack_head));
			}
		}
		else
		{
			while (info_a->stack_head->coordinate != target)
			{
				reverse_rotate_a(&(info_a->stack_head));
			}
		}
		push_b(info_a, info_b);
		if ((pivot - element) < info_b->stack_head->coordinate && info_b->stack_head->coordinate < (pivot - (element / 2)))
		{
			rotate_b(&(info_b->stack_head));
		}
	}
}

void	find_largest_and_push_a(t_info *info_a, t_info *info_b)
{
	size_t	size;

	size = info_b->size;
	while (size--)
	{
		if (search_forward(info_b, info_b->max) <= search_backward(info_b, info_b->max))
		{
			while (info_b->stack_head->coordinate != info_b->max)
			{
				rotate_b(&(info_b->stack_head));
			}
		}
		else
		{
			while (info_b->stack_head->coordinate != info_b->max)
			{
				reverse_rotate_b(&(info_b->stack_head));
			}
		}
		push_a(info_a, info_b);
	}
}

size_t	search_forward(t_info *info, int target)
{
	size_t	count;
	t_stack *list;

	count = 0;
	list = info->stack_head;
	while (list->coordinate != 0 && list->coordinate != target)
	{
		list = list->next;
		count++;
	}
	return (count);
}

size_t	search_backward(t_info *info, int target)
{
	size_t	count;
	t_stack *list;

	list = info->stack_head;
	count = 0;
	if (list->coordinate == target)
		return (0);
	list = list->prev->prev;
	count++;
	while (list->coordinate != 0 && list->coordinate != target)
	{
		list = list->prev;
		count++;
	}
	return (count);
}
