#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;

	if (argc < 2)
		return (0);
	make_a(&info_a, argv);
	make_index(&info_a);
	validate_input(info_a);
	make_b(&info_a, &info_b);

	/*
	print_list(info_a.head);
	ft_printf("min: %d, max: %d\n", info_a.min, info_a.max);
	print_list(info_b.head);
	ft_printf("min: %d, max: %d\n", info_b.min, info_b.max);
	*/

	sort_by_input_number(&info_a, &info_b);

	// print_list(info_a.head);
	// print_list(info_b.head);
	free_all(info_a.head, info_b.head);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }