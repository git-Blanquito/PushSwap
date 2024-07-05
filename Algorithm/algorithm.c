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

int	*create_position_lists(t_list_ps	**lists, t_list_ps	**list_b)
{
	int	*position_stack;
	int	i;

	i = 0;
	position_stack = calloc(8, 6);
	if (position_stack == NULL)
	{
		freelists(lists);
		ft_error();
	}
	while (i <= 5)
		position_stack[i++] = 0;
	position_stack = recharge_only_list_a(position_stack, lists);
	position_stack = recharge_only_list_b(position_stack, list_b);
	return (position_stack);
}

int	*last_order_lst_b(int *position_stack, t_list_ps **lists,
	t_list_ps **list_b)
{
	if (nodecount(list_b) != 0)
	{
		while (position_stack[3] < position_stack[5]
			|| position_stack[3] < position_stack[4])
		{
			move_for_order_lst_b(position_stack, lists);
			position_stack = recharge_position_lists(position_stack,
					lists, list_b);
		}
	}
	return (position_stack);
}

int	*last_order_lst_a(int *position_stack, t_list_ps **lists,
	t_list_ps **list_b)
{
	while (position_stack[0] > position_stack[1]
		|| position_stack[0] > position_stack[2]
		|| position_stack[1] > position_stack[2])
	{
		if (position_stack[0] > position_stack[1]
			&& position_stack[0] < position_stack[2])
			lists = sa(lists);
		else if (position_stack[0] > position_stack[2]
			&& (position_stack[1] < position_stack[2]
				|| position_stack[0] > position_stack[1]))
			lists = ra(lists);
		else if (position_stack[1] > position_stack[2])
			lists = rra(lists);
		position_stack = recharge_position_lists(position_stack, lists, list_b);
	}
	return (position_stack);
}

int	*all_to_list_a(int *position_stack, t_list_ps **lists, t_list_ps **list_b)
{
	while (*list_b != NULL)
	{
		if (position_stack[0] > position_stack[3])
		{
			while (position_stack[2] < position_stack[0]
				&& position_stack[2] > position_stack[3])
			{
				lists = rra(lists);
				position_stack = recharge_only_list_a(position_stack, lists);
			}
			lists = pa(lists);
		}
		else
		{
			while (position_stack[0] < position_stack[3])
			{
				lists = ra(lists);
				position_stack = recharge_only_list_a(position_stack, lists);
			}
			lists = pa(lists);
		}
		position_stack = recharge_position_lists(position_stack, lists, list_b);
	}
	return (position_stack);
}

t_list_ps	**algorithm(t_list_ps **lists)
{
	t_list_ps	**list_b;
	int			*position_stack;

	list_b = lists + 1;
	position_stack = create_position_lists(lists, list_b);
	all_to_list_b(lists, position_stack, list_b);
	position_stack = last_order_lst_b(position_stack, lists, list_b);
	position_stack = last_order_lst_a(position_stack, lists, list_b);
	position_stack = all_to_list_a(position_stack, lists, list_b);
	free(position_stack);
	return (lists);
}
