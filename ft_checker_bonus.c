/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:57:10 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/07/31 19:19:12 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error_and_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}

void	do_operation(char *line, t_info *info_a, t_info *info_b)
{
	if (ft_strcmp("sa\n", line) == 0)
		do_sa(&(info_a->head));
	else if (ft_strcmp("sb\n", line) == 0)
		do_sb(&(info_b->head));
	else if (ft_strcmp("ss\n", line) == 0)
		do_ss(&(info_a->head), &(info_b->head));
	else if (ft_strcmp("pa\n", line) == 0)
		do_pa(info_a, info_b);
	else if (ft_strcmp("pb\n", line) == 0)
		do_pb(info_a, info_b);
	else if (ft_strcmp("ra\n", line) == 0)
		do_ra(&(info_a->head));
	else if (ft_strcmp("rb\n", line) == 0)
		do_rb(&(info_b->head));
	else if (ft_strcmp("rr\n", line) == 0)
		do_rr(&(info_a->head), &(info_b->head));
	else if (ft_strcmp("rra\n", line) == 0)
		do_rra(&(info_a->head));
	else if (ft_strcmp("rrb\n", line) == 0)
		do_rrb(&(info_a->head));
	else if (ft_strcmp("rrr\n", line) == 0)
		do_rrr(&(info_a->head), &(info_b->head));
	else
		put_error_and_exit();
}

bool	check_if_infob_is_empty(t_info info_b)
{
	return (info_b.head == info_b.head->next);
}

int	main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;
	char	*line;

	if (argc < 2)
		return (0);
	make_stack_a(&info_a, argv);
	make_index(&info_a);
	validate_input(info_a);
	make_stack_b(&info_a, &info_b);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		do_operation(line, &info_a, &info_b);
		free(line);
	}
	if (check_if_list_is_sorted(info_a) && check_if_infob_is_empty(info_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(info_a.head, info_b.head);
	return (0);
}
