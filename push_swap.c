#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;

	if (argc < 2)
	{
		ft_printf("too few arguments");
		return (0);
	}

	info_a.stack_head = make_list(argv, &info_a);
	// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a->max, info_a->min, info_a->size);
	print_list(info_a.stack_head);
	info_b.stack_head = make_b(&info_b);
	// print_list(b);
	// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a.max, info_a.min, info_a.size);
	// ft_printf("info_b->max: %d, info_b->min: %d, info_b->size: %d\n", info_b.max, info_b.min, info_b.size);
	int min = 0;
	while ((info_a.stack_head)->next->next != info_a.stack_head)
	{
		min = find_min(info_a.stack_head);
		while (info_a.stack_head->num != min)
			rotate_a(&(info_a.stack_head));
		push_b(&(info_a.stack_head), &(info_b.stack_head), &info_a, &info_b);
		// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a.max, info_a.min, info_a.size);
		// ft_printf("info_b->max: %d, info_b->min: %d, info_b->size: %d\n", info_b.max, info_b.min, info_b.size);
	}
	// print_list(b);
	while (info_b.stack_head->num)
	{
		push_a(&(info_a.stack_head), &(info_b.stack_head), &info_a, &info_b);
		// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a.max, info_a.min, info_a.size);
		// ft_printf("info_b->max: %d, info_b->min: %d, info_b->size: %d\n", info_b.max, info_b.min, info_b.size);
	}

	print_list(info_a.stack_head);
	free_all(info_a.stack_head, info_b.stack_head);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}