/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:07:32 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/29 13:36:56 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b, int display)
{
	t_stack	*push_a;

	if (!*b)
		return ;
	push_a = *b;
	*b = (*b)->next;
	push_a->next = NULL;
	ft_lstadd_front(a, push_a);
	if (display == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int display)
{
	t_stack	*push_b;

	if (!*a)
		return ;
	push_b = *a;
	*a = (*a)->next;
	push_b->next = NULL;
	ft_lstadd_front(b, push_b);
	if (display == 1)
		ft_printf("pb\n");
}
