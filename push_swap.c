#include "push_swap.h"

size_t	check_if_list_is_sorted(t_info info_a)
{
	while (info_a.stack_head->next->coordinate)
	{
		if (info_a.stack_head->coordinate > info_a.stack_head->next->coordinate)
		{
			return (0);
		}
		info_a.stack_head = info_a.stack_head->next;
	}
	return (1);
}

void	sort_when_three(t_info **info_a)
{
	t_stack *list;

	list = (*info_a)->stack_head;
	if (list->coordinate == (*info_a)->min && list->next->coordinate == (*info_a)->max)
	{
		reverse_rotate_a(&((*info_a)->stack_head));
		swap_a(&((*info_a)->stack_head));
	}
	if (list->next->coordinate == (*info_a)->min && list->next->next->coordinate == (*info_a)->max)
		swap_a(&((*info_a)->stack_head));
	if (list->next->coordinate == (*info_a)->max && list->next->next->coordinate == (*info_a)->min)
		reverse_rotate_a(&((*info_a)->stack_head));
	if (list->coordinate == (*info_a)->max && list->next->coordinate == (*info_a)->min)
		rotate_a(&((*info_a)->stack_head));
	if (list->coordinate == (*info_a)->max && list->next->next->coordinate == (*info_a)->min)
	{
		rotate_a(&((*info_a)->stack_head));
		swap_a(&((*info_a)->stack_head));
	}
}

void	sort_from_four_to_six(t_info *info_a, t_info *info_b)
{
	while (info_a->size > 3)
	{
		if (search_forward(info_a, info_a->min) <= search_backward(info_a, info_a->min))
		{
			while (info_a->stack_head->coordinate != info_a->min)
				rotate_a(&(info_a->stack_head));
		}
		else
		{
			while (info_a->stack_head->coordinate != info_a->min)
				reverse_rotate_a(&(info_a->stack_head));
		}
		push_b(info_a, info_b);
	}
	sort_when_three(&info_a);
	while (info_b->size)
	{
		push_a(info_a, info_b);
	}
}

void	sort_above_seven(t_info *info_a, t_info *info_b)
{
	int		pivot;
	size_t	element;

	element = info_a->size / 6;
	pivot = 0;
	while (info_a->size)
	{
		pivot += element;
		find_less_than_pivot_and_push_b(info_a, info_b, pivot, element);
	}
	while (info_b->size)
	{
		find_largest_and_push_a(info_a, info_b);
	}
}

void	sort_by_input_number(t_info *info_a, t_info *info_b)
{
	if (check_if_list_is_sorted(*info_a) == 1)
		return ;
	if (info_a->size == 2)
		swap_a(&(info_a->stack_head));
	if (info_a->size == 3)
		sort_when_three(&info_a);
	if (3 < info_a->size && info_a->size < 7)
		sort_from_four_to_six(info_a, info_b);
	if (info_a->size >= 7)
		sort_above_seven(info_a, info_b);
}

int main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;

	if (argc < 2)
		return (0);
	make_a(&info_a, argv);
	coordinate_compress(&info_a);
	input_validation(info_a);
	make_b(&info_a, &info_b);
	// print_list(info_a.stack_head);
	// ft_printf("min: %d, max: %d\n", info_a.min, info_a.max);
	sort_by_input_number(&info_a, &info_b);

	// print_list(info_a.stack_head);
	// print_list(info_b.stack_head);
	free_all(info_a.stack_head, info_b.stack_head);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }