/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:53:53 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/13 17:30:44 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_to_min(t_stack **a, t_stack **b, int min, int pos)
{
	while ((*a)->index != min)
	{
		if (pos == 0)
			ra(a, 1);
		else if (pos == 1)
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	two_stack(t_stack **a)
{
	if ((*a)->index == 1)
		sa(*a, 1);
}

void	three_stack(t_stack **a)
{
	if ((*a)->index == 1 && (*a)->next->index == 2)
	{
		rra(a, 1);
		return ;
	}
	if ((*a)->index == 0 && (*a)->next->index == 2)
	{
		ra(a, 1);
		sa(*a, 1);
		rra(a, 1);
		return ;
	}
	if ((*a)->index == 2)
		ra(a, 1);
	if ((*a)->index == 1)
		sa(*a, 1);
}

void	four_stack(t_stack **a, t_stack **b)
{
	if (is_max_top(*a, 0, 3) == 1)
		move_to_min(a, b, 0, 0);
	else
		move_to_min(a, b, 0, 1);
	(*a)->index -= 1;
	(*a)->next->index -= 1;
	(*a)->next->next->index -= 1;
	three_stack(a);
	pa(a, b, 1);
}

void	five_stack(t_stack **a, t_stack **b)
{
	if (is_max_top(*a, 0, 3) == 1)
		move_to_min(a, b, 0, 0);
	else
		move_to_min(a, b, 0, 1);
	if (is_max_top(*a, 1, 2) == 1)
		move_to_min(a, b, 1, 0);
	else
		move_to_min(a, b, 1, 1);
	(*a)->index -= 2;
	(*a)->next->index -= 2;
	(*a)->next->next->index -= 2;
	three_stack(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
