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

void	move_for_order_lst_b(int *position_stack, t_list_ps **lists)
{
	if ((position_stack[3] < position_stack[4]
			&& position_stack[3] > position_stack[5])
		|| (position_stack[3] < position_stack[5]
			&& position_stack[3] > position_stack[4]))
	{
		if (position_stack[1] < position_stack[0]
			&& position_stack[0] < position_stack[2])
			lists = ss(lists);
		else
			lists = sb(lists);
	}
	else if (position_stack[3] < position_stack[5]
		&& position_stack[3] < position_stack[4])
	{
		if (position_stack[0] > position_stack[2]
			&& position_stack[1] < position_stack[2])
			lists = rr(lists);
		else
			lists = rb(lists);
	}
}
