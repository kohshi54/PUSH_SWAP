/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:48:28 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/14 02:37:17 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	info_a;
	t_info	info_b;

	if (argc < 2)
		return (0);
	make_stack_a(&info_a, argv);
	make_index(&info_a);
	validate_input(info_a);
	make_stack_b(&info_a, &info_b);
	sort_by_input_number(&info_a, &info_b);
	free_all(info_a.head, info_b.head);
	return (0);
}
