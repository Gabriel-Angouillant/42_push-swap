/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:29:06 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/29 13:38:42 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **a, int display)
{
	t_stack	*a_first;

	if (!*a || !(*a)->next)
		return ;
	a_first = *a;
	*a = (*a)->next;
	a_first->next = NULL;
	ft_lstadd_back(a, a_first);
	if (display == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int display)
{
	t_stack	*b_first;

	if (!*b || !(*b)->next)
		return ;
	b_first = *b;
	*b = (*b)->next;
	b_first->next = NULL;
	ft_lstadd_back(b, b_first);
	if (display == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int display)
{
	if (display == 1)
		ft_printf("rr\n");
	ra(a, 0);
	rb(b, 0);
}
