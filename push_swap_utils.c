#include "push_swap.h"

t_stack *init_node(void)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(EXIT_FAILURE);
	new->num = 0;
	new->next = new;
	new->prev = new;
	new->coordinate = 0;
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
	new->coordinate = 0;
	prev->next = new;
	return (new);
}

t_stack *make_list(char *argv[])
{
	t_stack *cur;
	t_stack *end;

	// cur = init_node();
	// end = cur;
	end = init_node();
	cur = end;
	while (*(++argv))
	{
		cur = add_list(*argv, cur);
	}
	cur->next = end;
	end->prev = cur;

	return (end->next);
}

void	make_b(t_info *info_b)
{
	info_b->size = 0;
	info_b->min = INT_MAX;
	info_b->max = INT_MIN;
	info_b->stack_head = init_node();
}

void	make_a(t_info *info_a, char *argv[])
{
	info_a->size = 0;
	info_a->min = INT_MAX;
	info_a->max = INT_MIN;
	info_a->stack_head = make_list(argv);
}

int find_min(t_stack *list)
{
	int min;

	min = INT_MAX;
	while (list->coordinate)
	{
		if (min > list->coordinate)
			min = list->coordinate;
		list = list->next;
	}
	return (min);
}

int	find_max(t_stack *list)
{
	int max;

	max = INT_MIN;
	while (list->coordinate)
	{
		if (max < list->coordinate)
			max = list->coordinate;
		list = list->next;
	}
	return (max);
}

void print_bit(int input)
{
	unsigned char byte = 1;
	
	byte = byte << 7;
	while (byte != 0)
	{
		if (input & byte)
			write(STDOUT_FILENO, "1", sizeof(char));
		else
			write(STDOUT_FILENO, "0", sizeof(char));
		byte = byte >> 1;
	}		
}

void	print_list(t_stack *list)
{
	ft_printf("-----print start----\n");
	while (list->coordinate)
	{
		ft_printf("num: %d, coordinate: %d (", list->num, list->coordinate);
		print_bit(list->coordinate);
		ft_printf(")\n");
		list = list->next;
	}
	ft_printf("num: %d, coordinate: %d\n", list->num, list->coordinate);
	ft_printf("-----print end------\n");
}

void	free_all(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	while (a->coordinate)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	free(a);
	while (b->coordinate)
	{
		tmp = b->next;
		free(b);
		b = tmp;
	}
	free(b);
}

void	coordinate_compress(t_stack *list, t_info *info_a)
{
	int	count;
	t_stack	*head;
	t_stack	*tmp;
	
	head = list;
	while (list->num)
	{
		tmp = head;
		count = 1;
		while (tmp->num)
		{
			if (tmp->num < list->num)
				count++;
			tmp = tmp->next;
		}
		list->coordinate = count;
		if (count < info_a->min)
			info_a->min = count;
		else if (count > info_a->max)
			info_a->max = count;
		info_a->size++;
		list = list->next;
	}
}

size_t	get_digit(int max)
{
	size_t	digit;

	digit = 0;
	while (max)
	{
		digit++;
		max = max >> 1;
	}
	return (digit);
}