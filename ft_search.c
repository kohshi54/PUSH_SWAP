#include "push_swap.h"

int find_min(t_stack *list)
{
	int min;

	min = INT_MAX;
	while (list->index)
	{
		if (min > list->index)
			min = list->index;
		list = list->next;
	}
	return (min);
}

int	find_max(t_stack *list)
{
	int max;

	max = INT_MIN;
	while (list->index)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	return (max);
}

size_t	search_forward(t_stack *list, int target)
{
	size_t	count;

	count = 0;
	while (list->index != target)
	{
		count++;
		list = list->next;
	}
	return (count);
}

size_t	search_backward(t_stack *list, int target)
{
	size_t	count;

	count = 1;
	list = list->prev->prev;
	while (list->index != target)
	{
		count++;
		list = list->prev;
	}
	return (count);
}