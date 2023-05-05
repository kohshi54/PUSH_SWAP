#include "push_swap.h"

t_stack *init_node(void)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(EXIT_FAILURE);
	new->num = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack *add_list(char *str, t_stack *prev)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(EXIT_FAILURE);
	new->num = ft_atoi(str);
	new->prev = prev;
	new->next = NULL;
	prev->next = new;
	return (new);
}

t_stack *make_list(char *argv[])
{
	t_stack *cur;
	t_stack *end;

	cur = init_node();
	end = cur;
	while (*(++argv))
	{
		cur = add_list(*argv, cur);
	}
	cur->next = end;
	end->prev = cur;

	return (end->next);
}

void	print_list(t_stack *list)
{
	ft_printf("-----print start----\n");
	while (list->num)
	{
		ft_printf("%d\n", list->num);
		list = list->next;
	}
	ft_printf("%d\n", list->num);
	ft_printf("-----print end------\n");
}

t_stack	*make_b()
{
	t_stack	*end;
	
	end = init_node();
	// end = add_list("5", end);
	end->next = end;
	end->prev = end;
	return (end);
}

// int	check_sort(t_stack *list)
// {
// 	while (list->num)
// 	{
// 		if (list->next->num != 0 && list->num > list->next->num)
// 			return (0);
// 		list = list->next;
// 	}
// 	return (1);
// }

int find_min(t_stack *list)
{
	int min;

	min = INT_MAX;
	while (list->num)
	{
		if (min > list->num)
			min = list->num;
		list = list->next;
	}
	return (min);
}

void	rotate_a(t_stack **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	free_all(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	while (a->num)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	free(a);
	while (b->num)
	{
		tmp = b->next;
		free(a);
	}
	free(b);
}

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
	{
		ft_printf("too few arguments");
		return (0);
	}

	a = make_list(argv);
	// print_list(a);
	b = make_b();
	// print_list(b);

	int min = 0;
	while (a->next->next != a)
	{
		min = find_min(a);
		while (a->num != min)
			rotate_a(&a);
		push_b(&a, &b);
	}
	// print_list(b);
	while (b->num)
	{
		push_a(&a, &b);
	}
	print_list(a);
	free_all(a, b);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }