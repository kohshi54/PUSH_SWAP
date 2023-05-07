#include "push_swap.h"

void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, int pivot)
{
	size_t	size;

	size = info_a->size;
	while (size--)
	{
		if (info_a->stack_head->coordinate < pivot)
		{
			push_b(info_a, info_b);
		}
		else
		{
			rotate_a(&(info_a->stack_head));
		}
	}
}

void	find_largest_and_push_a(t_info *info_a, t_info *info_b)
{
	size_t	size;

	size = info_b->size;
	while (size--)
	{
		if (search_forward(info_b) <= search_backward(info_b))
		{
			while (info_b->stack_head->coordinate != info_b->max)
			{
				rotate_b(&(info_b->stack_head));
			}
			push_a(info_a, info_b);
		}
		else
		{
			while (info_b->stack_head->coordinate != info_b->max)
			{
				reverse_rotate_b(&(info_b->stack_head));
			}
			push_a(info_a, info_b);
		}
	}
}

size_t	search_forward(t_info *info)
{
	size_t	count;
	int max;
	t_stack *list;

	count = 0;
	max = info->max;
	list = info->stack_head;
	while (list->coordinate != 0 && list->coordinate != max)
	{
		list = list->next;
		count++;
	}
	return (count);
}

size_t	search_backward(t_info *info)
{
	size_t	count;
	t_stack *list;
	int max;

	max = info->max;
	list = info->stack_head;
	count = 0;
	if (list->coordinate == max)
		return (0);
	list = list->prev->prev;
	count++;
	while (list->coordinate != 0 && list->coordinate != max)
	{
		list = list->prev;
		count++;
	}
	return (count);
}

int main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;

	if (argc < 2)
	{
		ft_printf("too few arguments");
		return (0);
	}

	make_a(&info_a, argv);
	coordinate_compress(info_a.stack_head, &info_a);
	// print_list(info_a.stack_head);
	make_b(&info_b);
	// print_list(info_b.stack_head);

	int		pivot = 0;
	size_t	element = info_a.size / 5;
	while (info_a.size)
	{
		pivot += element;
		find_less_than_pivot_and_push_b(&info_a, &info_b, pivot);
	}
	while (info_b.size)
	{
		find_largest_and_push_a(&info_a, &info_b);
	}

	// print_list(info_a.stack_head);
	// print_list(info_b.stack_head);
	free_all(info_a.stack_head, info_b.stack_head);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }