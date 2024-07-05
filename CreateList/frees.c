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

void	freesplit(char	**src)
{
	char	**src_i;

	src_i = src;
	while (*src_i)
	{
		free(*src_i);
		src_i++;
	}
	free(src);
}

void	freelists(t_list_ps	**lists)
{
	t_list_ps	*list1;
	int			i;

	i = 0;
	while (i < 3)
	{
		while (*lists)
		{
			list1 = *lists;
			*lists = list1->next;
			free(list1);
		}
		i++;
		lists++;
	}
	free(lists - i);
}

void	free_split_lists(t_list_ps	**list_a, char	**c_src, int i, ...)
{
	va_list		arg;
	t_list_ps	*a;

	if (i == 1)
	{
		va_start(arg, i);
		a = va_arg(arg, t_list_ps *);
		if (a != NULL)
			free(a);
	}
	freesplit(c_src);
	if (list_a)
		freelists(list_a);
	if (i == 1)
		va_end(arg);
	ft_error();
}
