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

t_list_ps	**set_index(t_list_ps **lists, int max_nodes)
{
	t_list_ps	*lst;
	int			i;
	int			z;
	long int	j;

	i = -1;
	j = -2147483649;
	while (max_nodes-- > 0 && i++ != -2)
	{
		lst = *lists;
		z = 2147483647;
		while (lst != NULL)
		{
			if (lst->content <= z && lst->content > j)
			{
				lst->index = i;
				z = lst->content;
			}
			lst = lst->next;
		}
		j = z;
	}
	return (lists);
}

int	max_bits(int max_nodes)
{
	int	bits;
	int	j;
	int	i;

	i = 0;
	j = 0;
	bits = 32;
	while (bits-- > 0)
	{
		if ((((max_nodes - 1) >> i) & 1) == 1)
			j = i;
		i++;
	}
	return (j);
}

t_list_ps	**prosecution(t_list_ps **lists, int max_nodes)
{
	t_list_ps	*lst;
	int			bits;
	int			i;
	int			j;

	bits = 0;
	j = max_bits(max_nodes);
	while (j-- >= 0)
	{
		lst = *lists;
		i = max_nodes;
		while (i-- > 0)
		{
			lst = *lists;
			if ((((lst->index) >> bits) & 1) == 1)
				lists = ra(lists);
			else
				lists = pb(lists);
		}
		while (*(lists + 1) != NULL)
			lists = pa(lists);
		bits++;
	}
	return (lists);
}

t_list_ps	**algorithm2(t_list_ps **lists, int max_nodes)
{
	lists = prosecution(lists, max_nodes);
	return (lists);
}
