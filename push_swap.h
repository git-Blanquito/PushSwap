/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:05:32 by aiblanco          #+#    #+#             */
/*   Updated: 2023/09/30 23:05:35 by aiblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>//Argumentos función Open
# include <unistd.h>//Write y Open
# include <stdio.h>//Null y printf
# include <stdlib.h>//Malloc y free
# include <string.h>//Null y size-t
# include <limits.h>//OPEN_MAX para generar el numero de posiciones maximo
# include "stdarg.h"//Argumentos infinitos para funciones
# include "./libft/libft.h"

typedef struct a_list
{
	int				content;
	int				index;
	struct a_list	*next;
}	t_list_ps;

t_list_ps	**ft_lstadd_back2(t_list_ps **lst, t_list_ps *newe,
				char	**c_src);
t_list_ps	*ft_lstnew2(int content);
void		freesplit(char	**src);
void		freelists(t_list_ps	**lists);
t_list_ps	**format_list_1(t_list_ps	**list_a, char	**c_src);
t_list_ps	**format_list(int argc, char	**argv);
void		ft_error(void);
void		free_split_lists(t_list_ps	**list_a, char	**c_src,
				int i, ...);
long int	ft_atoi(const char *str, t_list_ps	**list_a, char	**c_src);
t_list_ps	**sa(t_list_ps **lists);
t_list_ps	**sb(t_list_ps **lists);
t_list_ps	**ss(t_list_ps **lists);
t_list_ps	**ss_sa(t_list_ps **lists);
t_list_ps	**ss_sb(t_list_ps **lists);
t_list_ps	**pa(t_list_ps **lists);
t_list_ps	**pb(t_list_ps **lists);
t_list_ps	**ra(t_list_ps **lists);
t_list_ps	**rb(t_list_ps **lists);
t_list_ps	**rr(t_list_ps **lists);
t_list_ps	**rr_ra(t_list_ps **lists);
t_list_ps	**rr_rb(t_list_ps **lists);
t_list_ps	**rra(t_list_ps **lists);
t_list_ps	**rrb(t_list_ps **lists);
t_list_ps	**rrr(t_list_ps **lists);
t_list_ps	**rrr_rra(t_list_ps **lists);
t_list_ps	**rrr_rrb(t_list_ps **lists);
t_list_ps	**algorithm(t_list_ps **lists);
int			nodecount(t_list_ps	**list);
void		order_case_0(int	*position_stack, t_list_ps	**lists,
				t_list_ps	**list_b);
void		order_case_1(int	*position_stack, t_list_ps	**lists);
void		order_case_2(int *position_stack, t_list_ps	**lists);
int			*recharge_position_lists(int *position_stack,
				t_list_ps	**lists, t_list_ps	**list_b);
int			*recharge_only_list_b(int *position_stack, t_list_ps	**list_b);
int			*recharge_only_list_a(int *position_stack, t_list_ps	**lists);
t_list_ps	*ft_lstlast2(t_list_ps	*lst);
void		move_for_order_lst_b(int *position_stack, t_list_ps **lists);
void		all_to_list_b(t_list_ps **lists, int *position_stack,
				t_list_ps **list_b);
t_list_ps	**set_index(t_list_ps **lists, int argc);
t_list_ps	**algorithm2(t_list_ps **lists, int max_nodes);

#endif
