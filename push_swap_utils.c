#include "push_swap.h"

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

#include <stdio.h>
void	print_list(t_stack *list)
{
	ft_printf("-----print start----\n");
	while (list->coordinate)
	{
		printf("num: %ld, coordinate: %d\n", list->num, list->coordinate);
		list = list->next;
	}
	printf("num: %ld, coordinate: %d\n", list->num, list->coordinate);
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

void	coordinate_compress(t_info *info_a)
{
	int	count;
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*list;
	
	list = info_a->stack_head;
	head = list;
	while (list->next != head)
	{
		tmp = head;
		count = 1;
		while (tmp->next != head)
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

void	put_error_and_free_and_exit(t_info info_a)
{
	t_stack *tmp;

	ft_printf("Error\n");
	while (info_a.stack_head->coordinate)
	{
		tmp = info_a.stack_head->next;
		free(info_a.stack_head);
		info_a.stack_head = tmp;
	}
	free(info_a.stack_head);
	exit(EXIT_FAILURE);
}

void	input_validation(t_info info_a)
{
	t_stack	*head;
	t_stack	*tmp;

	head = info_a.stack_head;
	while (info_a.stack_head->coordinate)
	{
		if (info_a.stack_head->num == (WRONG_NUM))
			put_error_and_free_and_exit(info_a);
		tmp = head;
		while (tmp->coordinate)
		{
			if ((tmp != info_a.stack_head) && (tmp->num == info_a.stack_head->num))
				put_error_and_free_and_exit(info_a);
			tmp = tmp->next;
		}
		info_a.stack_head = info_a.stack_head->next;
	}
}