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
	prev->next = new;
	return (new);
}

t_stack *make_list(char *argv[], t_info *info)
{
	t_stack *cur;
	t_stack *end;

	cur = init_node();
	end = cur;
	info->size = 0;
	info->min = INT_MAX;
	info->max = INT_MIN;
	while (*(++argv))
	{
		cur = add_list(*argv, cur);
		info->size++;
		if (cur->num > info->max)
			info->max = cur->num;
		if (cur->num < info->min)
			info->min = cur->num;
	}
	cur->next = end;
	end->prev = cur;

	return (end->next);
}

t_stack	*make_b(t_info *info)
{
	t_stack	*end;
	
	info->min = INT_MAX;
	info->max = INT_MIN;
	info->size = 0;
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
	while (list->coordinate)
	{
		if (min > list->num)
			min = list->num;
		list = list->next;
	}
	return (min);
}

int	find_max(t_stack *list)
{
	int max;

	max = INT_MIN;
	while (list->num)
	{
		if (max < list->num)
			max = list->num;
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

void	coordinate_compress(t_stack *list)
{
	size_t	count;
	t_stack	*head;
	t_stack	*tmp;

	head = list;
	while (list->next != head)
	{
		tmp = head;
		count = 1;
		while (tmp->next != head)
		{
			if (tmp->num < list->num)
			{
				count++;
			}
			tmp = tmp->next;
		}
		list->coordinate = count;
		list = list->next;
	}
	// list->coordinate = 0;
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