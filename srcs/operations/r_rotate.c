/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:45:07 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/29 13:39:02 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **a, int display)
{
	t_stack	*a_last;
	t_stack	*previous;

	if (!*a || !(*a)->next)
		return ;
	a_last = *a;
	while (a_last->next)
	{
		previous = a_last;
		a_last = a_last->next;
	}
	ft_lstadd_front(a, ft_lstlast(*a));
	previous->next = NULL;
	if (display == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int display)
{
	t_stack	*b_last;
	t_stack	*previous;

	if (!*b || !(*b)->next)
		return ;
	b_last = *b;
	while (b_last->next)
	{
		previous = b_last;
		b_last = b_last->next;
	}
	ft_lstadd_front(b, ft_lstlast(*b));
	previous->next = NULL;
	if (display == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int display)
{
	if (display == 1)
		ft_printf("rrr\n");
	rra(a, 0);
	rrb(b, 0);
}
