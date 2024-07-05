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

int	nodecount(t_list_ps	**list)
{
	int			a;
	t_list_ps	*node;

	a = 1;
	node = NULL;
	if (*list == NULL)
		return (0);
	node = *list;
	while (node->next != NULL)
	{
		node = node->next;
		a++;
	}
	return (a);
}
