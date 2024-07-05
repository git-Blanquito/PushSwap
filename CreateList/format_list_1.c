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

t_list_ps	**ft_lstadd_back2(t_list_ps **lst, t_list_ps *newe, char	**c_src)
{
	t_list_ps	*last;
	int			i;

	i = 0;
	last = (*lst);
	if (*lst)
	{
		while (i == 0)
		{
			if (newe->content == last->content)
				free_split_lists(lst, c_src, 1, newe);
			if (last->next == NULL && i == 0)
			{
				last->next = newe;
				i = 1;
			}
			else
				last = last->next;
		}
	}
	else
		*lst = newe;
	return (lst);
}

t_list_ps	*ft_lstnew2(int content)
{
	t_list_ps	*nodo;

	nodo = (t_list_ps *) ft_calloc(sizeof(t_list_ps), 1);
	if (!nodo)
		return (NULL);
	nodo->content = content;
	nodo->index = -1;
	nodo->next = NULL;
	return (nodo);
}

t_list_ps	**format_list_1(t_list_ps	**list_a, char	**c_src)
{
	t_list_ps	*node;
	int			i;
	int			b;
	int			c;

	i = 0;
	while (c_src[i] != NULL)
	{
		c = -1;
		while (c_src[i][++c] != '\0')
		{
			if ((c_src[i][c] != 0 && c_src[i][c] != 43 &&
			c_src[i][c] != 45 && c_src[i][c] != 32 &&
			c_src[i][c] <= 47) || (c_src[i][c] >= 58))
				free_split_lists(list_a, c_src, 0);
		}
		b = ft_atoi(c_src[i++], list_a, c_src);
		node = ft_lstnew2(b);
		if (node == NULL)
			free_split_lists(list_a, c_src, 0);
		list_a = ft_lstadd_back2(list_a, node, c_src);
	}
	return (list_a);
}
