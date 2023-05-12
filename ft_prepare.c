/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:48:14 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/12 16:49:52 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *list_a, t_stack *list_b)
{
	t_stack	*tmp;

	while (list_a->index)
	{
		tmp = list_a->next;
		free(list_a);
		list_a = tmp;
	}
	free(list_a);
	while (list_b->index)
	{
		tmp = list_b->next;
		free(list_b);
		list_b = tmp;
	}
	free(list_b);
}

void	make_index(t_info *info_a)
{
	int		count;
	t_stack	*tmp;
	t_stack	*list;

	list = info_a->head;
	while (list->next != info_a->head)
	{
		tmp = info_a->head;
		count = 1;
		while (tmp->next != info_a->head)
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

void	put_error_and_free_and_exit(t_stack *list)
{
	t_stack	*tmp;

	ft_putstr_fd("Error\n", STDERR_FILENO);
	while (list->index)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
	exit(EXIT_FAILURE);
}

void	validate_input(t_info info_a)
{
	t_stack	*head;
	t_stack	*tmp;

	head = info_a.head;
	while (info_a.head->index)
	{
		if (info_a.head->num == (WRONG_NUM))
			put_error_and_free_and_exit(head);
		tmp = head;
		while (tmp->index)
		{
			if ((tmp != info_a.head) && (tmp->num == info_a.head->num))
				put_error_and_free_and_exit(head);
			tmp = tmp->next;
		}
		info_a.head = info_a.head->next;
	}
}
