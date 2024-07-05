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

t_list_ps	**format_list(int argc, char	**argv)
{
	t_list_ps	**lists;
	char		**c_src;
	int			i;

	i = 1;
	c_src = NULL;
	if (argc < 2)
		exit(1);
	lists = ft_calloc(3, 8);
	if (lists == NULL)
		ft_error();
	while (i < argc)
	{
		c_src = ft_split(argv[i++], 32);
		if (c_src == NULL)
		{
			freelists(lists);
			ft_error();
		}
		lists = format_list_1(lists, c_src);
		freesplit(c_src);
	}
	return (lists);
}
