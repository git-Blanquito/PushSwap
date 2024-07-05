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

t_list_ps	*ft_lstlast2(t_list_ps	*lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	*recharge_only_list_a(int *position_stack, t_list_ps	**lists)
{
	int	a;

	a = nodecount(lists);
	if (a == 1)
	{
		position_stack[0] = (*lists)->content;
		position_stack[1] = position_stack[0];
		position_stack[2] = position_stack[0];
	}
	else if (a == 2)
	{
		position_stack[0] = (*lists)->content;
		position_stack[1] = ((*lists)->next)->content;
		position_stack[2] = position_stack[1];
	}
	else
	{
		position_stack[0] = (*lists)->content;
		position_stack[1] = ((*lists)->next)->content;
		position_stack[2] = (ft_lstlast2(*lists))->content;
	}
	return (position_stack);
}

int	*recharge_only_list_b(int *position_stack, t_list_ps	**list_b)
{
	int	a;

	a = nodecount(list_b);
	if (a != 0)
	{
		if (a == 1)
		{
			position_stack[3] = (*list_b)->content;
			position_stack[4] = position_stack[3];
			position_stack[5] = position_stack[3];
		}
		if (a == 2)
		{
			position_stack[3] = (*list_b)->content;
			position_stack[4] = ((*list_b)->next)->content;
			position_stack[5] = position_stack[4];
		}
		if (a >= 3)
		{
			position_stack[3] = (*list_b)->content;
			position_stack[4] = ((*list_b)->next)->content;
			position_stack[5] = (ft_lstlast2(*list_b))->content;
		}
	}
	return (position_stack);
}

int	*recharge_position_lists(int *position_stack, t_list_ps	**lists,
	t_list_ps	**list_b)
{
	position_stack = recharge_only_list_a(position_stack, lists);
	position_stack = recharge_only_list_b(position_stack, list_b);
	return (position_stack);
}
