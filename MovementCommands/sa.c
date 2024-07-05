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

t_list_ps	**sa(t_list_ps **lists)
{
	t_list_ps	*node;
	t_list_ps	*node2;

	if (lists == NULL)
		return (NULL);
	if (*lists == NULL)
		return (lists);
	node = *lists;
	if (node->next == NULL)
		return (lists);
	node2 = node->next;
	node->next = node2->next;
	node2->next = node;
	*lists = node2;
	write (1, "sa\n", 3);
	return (lists);
}
