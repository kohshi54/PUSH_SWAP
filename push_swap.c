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
	coordinate_compress(info_a.stack_head);
	print_list(info_a.stack_head);
	info_b.stack_head = make_b(&info_b);
	// print_list(info_b.stack_head);
	int min = 0;
	while ((info_a.stack_head)->next->next != info_a.stack_head)
	{
		min = find_min(info_a.stack_head);
		while (info_a.stack_head->num != min)
			rotate_a(&(info_a.stack_head));
		push_b(&(info_a.stack_head), &(info_b.stack_head), &info_a, &info_b);
	}
	// print_list(b);
	while (info_b.stack_head->coordinate)
	{
		push_a(&(info_a.stack_head), &(info_b.stack_head), &info_a, &info_b);
	}

	print_list(info_a.stack_head);
	free_all(info_a.stack_head, info_b.stack_head);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
