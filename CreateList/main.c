/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:05:42 by aiblanco          #+#    #+#             */
/*   Updated: 2023/09/30 23:05:48 by aiblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	orderer(t_list_ps **lists)
{
	t_list_ps	*node;

	node = *lists;
	while (node->next != NULL
		&& (node->index < (node->next)->index))
		node = node->next;
	if (node->next == NULL)
	{
		freelists(lists);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_list_ps	**lists;
	int			max_nodes;

	lists = NULL;
	lists = format_list(argc, argv);
	max_nodes = nodecount(lists);
	lists = set_index(lists, max_nodes);
	orderer(lists);
	if (max_nodes < 51)
		lists = algorithm(lists);
	else
		lists = algorithm2(lists, max_nodes);
	freelists(lists);
	return (0);
}

/* void	readlists(t_list_ps	**lists)
{
	t_list_ps	*node;
	int			i;

	i = 0;
	node = NULL;
	if (*lists != NULL)
	{
		node = (*lists);
		while (i == 0)
		{
			ft_printf(" %d", node->content);
			if (node->next == NULL)
				i = 1;
			node = node->next;
		}
		ft_printf("\n");
	}
} */