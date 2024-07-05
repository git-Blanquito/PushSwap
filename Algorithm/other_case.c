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

void	order_case_0(int	*position_stack, t_list_ps	**lists,
	t_list_ps	**list_b)
{
	while (position_stack[3] < position_stack[5]
		|| position_stack[3] < position_stack[4])
	{
		position_stack = recharge_only_list_b(position_stack, list_b);
		if ((position_stack[3] < position_stack[4]
				&& position_stack[3] > position_stack[5])
			|| (position_stack[3] < position_stack[5]
				&& position_stack[3] > position_stack[4]))
			lists = sb(lists);
		else if (position_stack[3] < position_stack[5]
			&& position_stack[3] < position_stack[4])
			lists = rb(lists);
	}
	lists = pb(lists);
}

void	order_case_1(int	*position_stack, t_list_ps	**lists)
{
	if (position_stack[0] > position_stack[2])
	{
		if (position_stack[3] < position_stack[5]
			&& position_stack[3] > position_stack[4])
			lists = rr(lists);
		else
			lists = ra(lists);
	}
	else
	{
		if (position_stack[3] < position_stack[4]
			&& position_stack[3] > position_stack[5])
			lists = ss(lists);
		else
			lists = sa(lists);
	}
}

void	order_case_2(int *position_stack, t_list_ps	**lists)
{
	if (position_stack[0] > position_stack[1])
	{
		if (position_stack[3] < position_stack[4]
			&& position_stack[3] > position_stack[5])
			lists = ss(lists);
		else
			lists = sa(lists);
	}
	else
		lists = rra(lists);
}
