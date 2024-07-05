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

t_list_ps	**rrr_rra(t_list_ps **lists)
{
	t_list_ps	*node;
	t_list_ps	*node2;

	node = NULL;
	node2 = NULL;
	if (*lists != NULL)
	{
		node = *lists;
		if (node->next == NULL)
			return (lists);
		while ((node->next)->next != NULL)
			node = node->next;
		node2 = node->next;
		node->next = NULL;
		node2->next = *lists;
		*lists = node2;
	}
	return (lists);
}
