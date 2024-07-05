/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_format_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 02:41:00 by aiblanco          #+#    #+#             */
/*   Updated: 2023/10/03 02:41:03 by aiblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list_ps	**pa(t_list_ps **lists)
{
	t_list_ps	*node;

	node = NULL;
	++lists;
	if (*lists != NULL)
	{
		node = *lists;
		if (node->next == NULL)
			*lists = NULL;
		else
			*lists = node->next;
		lists--;
		if (lists)
			node->next = *lists;
		else
			node->next = NULL;
		*lists = node;
		write (1, "pa\n", 3);
		return (lists);
	}
	return (--lists);
}
