#include "push_swap.h"

/*

#include <stdio.h>
void	print_list(t_stack *list)
{
	ft_printf("-----print start----\n");
	while (list->index)
	{
		printf("num: %ld, index: %d\n", list->num, list->index);
		list = list->next;
	}
	printf("num: %ld, index: %d\n", list->num, list->index);
	ft_printf("-----print end------\n");
}

void	print_forward(t_stack *list)
{
	t_stack	*head;

	ft_printf("-----forward start----\n");
	head = list;
	while (list->index)
	{
		ft_printf("num: %d, index: %d\n", list->num, list->index);
		list = list->next;
	}
	ft_printf("num: %d, index: %d\n", list->num, list->index);
	if (list->next->index == head->index)
		ft_printf("cycle yes\n");
	ft_printf("-----forward end------\n");
}

void	print_backward(t_stack *list)
{
	t_stack	*head;

	ft_printf("-----backward start----\n");
	list = list->prev->prev;
	head = list;
	while (list->index)
	{
		ft_printf("num: %d, index: %d\n", list->num, list->index);
		list = list->prev;
	}
	ft_printf("num: %d, index: %d\n", list->num, list->index);
	if (list->prev->index == head->index)
		ft_printf("cycle yes\n");
	ft_printf("-----backward end------\n");
}

*/

void	free_all(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	while (a->index)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	free(a);
	while (b->index)
	{
		tmp = b->next;
		free(b);
		b = tmp;
	}
	free(b);
}

void	index_compress(t_info *info_a)
{
	int	count;
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*list;
	
	list = info_a->head;
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
		list->index = count;
		if (count < info_a->min)
			info_a->min = count;
		if (count > info_a->max)
			info_a->max = count;
		info_a->size++;
		list = list->next;
	}
}

void	put_error_and_free_and_exit(t_info info_a)
{
	t_stack *tmp;

	ft_printf("Error\n");
	while (info_a.head->index)
	{
		tmp = info_a.head->next;
		free(info_a.head);
		info_a.head = tmp;
	}
	free(info_a.head);
	exit(EXIT_FAILURE);
}

void	input_validation(t_info info_a)
{
	t_stack	*head;
	t_stack	*tmp;

	head = info_a.head;
	while (info_a.head->index)
	{
		if (info_a.head->num == (WRONG_NUM))
			put_error_and_free_and_exit(info_a);
		tmp = head;
		while (tmp->index)
		{
			if ((tmp != info_a.head) && (tmp->num == info_a.head->num))
				put_error_and_free_and_exit(info_a);
			tmp = tmp->next;
		}
		info_a.head = info_a.head->next;
	}
}