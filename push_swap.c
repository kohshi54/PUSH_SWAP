#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;
	size_t	digit;

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

	digit = get_digit(info_a.size);
	// ft_printf("%d\n", digit);

	size_t	i;
	i = 0;
	while (i < digit)
	{
		t_stack *head = info_a.stack_head;
		bool flag = 1;
		while (flag || info_a.stack_head != head)
		{
			flag = 0;
			if (info_a.stack_head->coordinate & (1 << i))
			{
				rotate_a(&(info_a.stack_head));
			}
			else
			{
				if (head == info_a.stack_head)
				{
					head = info_a.stack_head->next;
					flag = 1;
				}
				push_b(&(info_a.stack_head), &(info_b.stack_head), &info_a, &info_b);
			}
		}
		while (info_b.stack_head->next != info_b.stack_head)
		{
			push_a(&(info_a.stack_head), &(info_b.stack_head), &info_a, &info_b);
		}
		i++;
	}

	print_list(info_a.stack_head);
	free_all(info_a.stack_head, info_b.stack_head);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
