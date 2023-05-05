#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	t_info	info_a;
	t_info	info_b;

	if (argc < 2)
	{
		ft_printf("too few arguments");
		return (0);
	}

	a = make_list(argv, &info_a);
	// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a->max, info_a->min, info_a->size);
	print_list(a);
	b = make_b(&info_b);
	// print_list(b);
	// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a.max, info_a.min, info_a.size);
	// ft_printf("info_b->max: %d, info_b->min: %d, info_b->size: %d\n", info_b.max, info_b.min, info_b.size);
	int min = 0;
	while (a->next->next != a)
	{
		min = find_min(a);
		while (a->num != min)
			rotate_a(&a);
		push_b(&a, &b, &info_a, &info_b);
		// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a.max, info_a.min, info_a.size);
		// ft_printf("info_b->max: %d, info_b->min: %d, info_b->size: %d\n", info_b.max, info_b.min, info_b.size);
	}
	// print_list(b);
	while (b->num)
	{
		push_a(&a, &b, &info_a, &info_b);
		// ft_printf("info_a->max: %d, info_a->min: %d, info_a->size: %d\n", info_a.max, info_a.min, info_a.size);
		// ft_printf("info_b->max: %d, info_b->min: %d, info_b->size: %d\n", info_b.max, info_b.min, info_b.size);
	}

	print_list(a);
	free_all(a, b);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}