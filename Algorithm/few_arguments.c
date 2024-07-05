/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_format_1.position_stack[2]                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 02:41:00 by aiblanco          #+#    #+#             */
/*   Updated: 2023/10/03 02:41:03 by aiblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	all_to_list_b(t_list_ps **lists, int *position_stack,
			t_list_ps **list_b)
{
	while (nodecount(lists) > 3)
	{
		if (position_stack[0] < position_stack[1]
			&& position_stack[0] < position_stack[2])
			order_case_0(position_stack, lists, list_b);
		else if (position_stack[1] < position_stack[0]
			&& position_stack[1] < position_stack[2])
			order_case_1(position_stack, lists);
		else if (position_stack[2] < position_stack[1]
			&& position_stack[2] < position_stack[0])
			order_case_2(position_stack, lists);
		position_stack = recharge_position_lists(position_stack, lists, list_b);
	}
}
