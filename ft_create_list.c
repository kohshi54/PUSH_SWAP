/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:52 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/12 16:47:52 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_node(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = INT_MIN - (long)2;
	new->next = new;
	new->prev = new;
	new->index = 0;
	return (new);
}

t_stack	*add_list(char *str, t_stack *prev)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		while (prev)
		{
			tmp = prev->prev;
			free(prev);
			prev = tmp;
		}
		exit(EXIT_FAILURE);
	}
	new->num = ft_atoi(str);
	new->prev = prev;
	new->next = NULL;
	new->index = 0;
	prev->next = new;
	return (new);
}

t_stack	*make_list(char *argv[])
{
	t_stack	*cur;
	t_stack	*end;

	end = init_node();
	if (!end)
		exit(EXIT_FAILURE);
	cur = end;
	while (*(++argv))
	{
		cur = add_list(*argv, cur);
	}
	cur->next = end;
	end->prev = cur;
	return (end->next);
}

void	make_stack_b(t_info *info_a, t_info *info_b)
{
	t_stack	*tmp;

	info_b->size = 0;
	info_b->min = INT_MAX;
	info_b->max = INT_MIN;
	info_b->head = init_node();
	if (!info_b->head)
	{
		while (info_a->head->index)
		{
			tmp = info_a->head->next;
			free(info_a->head);
			info_a->head = tmp;
		}
		free(info_a->head);
		exit(EXIT_FAILURE);
	}
}

void	make_stack_a(t_info *info_a, char *argv[])
{
	info_a->size = 0;
	info_a->min = INT_MAX;
	info_a->max = INT_MIN;
	info_a->head = make_list(argv);
}
