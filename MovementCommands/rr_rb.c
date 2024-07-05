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

t_list_ps	**rr_rb(t_list_ps **lists)
{
	t_list_ps	*node;
	t_list_ps	*node2;

	lists++;
	node = *lists;
	*lists = node->next;
	node->next = NULL;
	node2 = *lists;
	while (node2->next != NULL)
		node2 = node2->next;
	node2->next = node;
	return (--lists);
}
