#include "push_swap.h"

size_t	get_count_of_larger_than_pivot(t_stack *list, int pivot)
{
	size_t	count;

	count = 0;
	while (list->index)
	{
		if (pivot <= list->index)
			count++;
		list = list->next;
	}
	return (count);
}


int	find_largest_or_pivot(t_stack *list, int max, int pivot)
{
	t_stack	*backward;

	backward = list->prev->prev;
	while (list->index != backward->index)
	{
		// if (list->index == max || list->index == (pivot))
		if (list->index == max || list->index == max-1 || list->index == (pivot))
			return (list->index);
		// if (backward->index == max || backward->index == (pivot))
		if (backward->index == max || list->index == max-1 || backward->index == (pivot))
			return (backward->index);
		list = list->next;
		backward = backward->prev;
	}
	return (list->index);
}

// int	find_closest_max_secondmax_pivot(t_stack *list, int max, int pivot)
// {
// 	t_stack	*backward;

// 	backward = list->prev->prev;
// 	while (list->index != backward->index)
// 	{
// 		// if (list->index == max || list->index == (pivot))
// 		if (list->index == max || list->index == max-1 || list->index == (pivot))
// 			return (list->index);
// 		// if (backward->index == max || backward->index == (pivot))
// 		if (backward->index == max || list->index == max-1 || backward->index == (pivot))
// 			return (backward->index);
// 		list = list->next;
// 		backward = backward->prev;
// 	}
// 	return (list->index);
// }

/*
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
*/

void	find_larger_than_pivot_and_push_a(t_info *info_a, t_info *info_b)
{
	int		target;
	int		pivot;

	pivot = info_b->max - 5;
	if (info_b->size < 5)
		pivot = 1;
	while (get_count_of_larger_than_pivot(info_b->head, pivot))
	{
		target = find_largest_or_pivot(info_b->head, info_b->max, pivot);
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
		if (info_a->head->index - 1 == info_a->head->next->index)
			swap_a(&(info_a->head));
		else if (!((info_a->head->index + 1 == info_a->head->next->index || info_a->head->index + 2 == info_a->head->next->index) && (info_a->head->next->index + 1 == info_a->head->next->next->index)))
		{
			if (!(info_a->head->index == info_a->max || info_a->head->index == info_a->max - 1 || info_a->head->index == info_a->max - 2))
				rotate_a(&(info_a->head));
		}
		if (info_a->head->index + 1 == info_a->head->next->index)
		{
			while (info_a->head->index - 1 == info_a->head->prev->prev->index)
				reverse_rotate_a(&(info_a->head));
		}
		if (info_a->head->index - 2 == info_a->head->next->index)
			reverse_rotate_a(&(info_a->head));
		// if (target == pivot)
		// {
			// pivot++;
		// }
		// print_list(info_a->head);
	}


	/*
	if (info_a->head->next->next != 0 && info_a->head->next->next->index < info_a->head->next->index)
		swap_second_and_third(info_a, info_b);
	*/
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
