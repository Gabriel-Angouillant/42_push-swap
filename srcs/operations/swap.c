/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:54:05 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/29 13:38:26 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *a, int display)
{
	int	tmp_c;
	int	tmp_i;

	if (!a || !a->next)
		return ;
	tmp_c = a->next->content;
	tmp_i = a->next->index;
	a->next->content = a->content;
	a->next->index = a->index;
	a->content = tmp_c;
	a->index = tmp_i;
	if (display == 1)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int display)
{
	int	tmp_c;
	int	tmp_i;

	if (!b || !b->next)
		return ;
	tmp_c = b->next->content;
	tmp_i = b->next->index;
	b->next->content = b->content;
	b->next->index = b->index;
	b->content = tmp_c;
	b->index = tmp_i;
	if (display == 1)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, int display)
{
	if (display == 1)
		ft_printf("ss\n");
	sa(a, 0);
	sb(b, 0);
}
