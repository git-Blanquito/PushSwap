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

t_list_ps	**rrr(t_list_ps **lists)
{
	t_list_ps	*node;

	node = NULL;
	if (*lists == NULL)
		return (lists);
	node = *lists;
	if (node->next == NULL)
		return (lists);
	lists++;
	if (*lists == NULL)
		return (--lists);
	node = *lists;
	if (node->next == NULL)
		return (--lists);
	lists--;
	lists = rrr_rra(lists);
	lists = rrr_rrb(lists);
	write (1, "rrr\n", 4);
	return (lists);
}
