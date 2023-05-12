/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:38:57 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/12 17:25:58 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *list)
{
	size_t	min;

	min = INT_MAX;
	while (list->index)
	{
		if (min > list->index)
			min = list->index;
		list = list->next;
	}
	return (min);
}

int	find_max(t_stack *list)
{
	size_t	max;

	max = 0;
	while (list->index)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	return (max);
}

size_t	search_forward(t_stack *list, size_t target)
{
	size_t	count;

	count = 0;
	while (list->index != target)
	{
		count++;
		list = list->next;
	}
	return (count);
}

size_t	search_backward(t_stack *list, size_t target)
{
	size_t	count;

	count = 1;
	list = list->prev->prev;
	while (list->index != target)
	{
		count++;
		list = list->prev;
	}
	return (count);
}
