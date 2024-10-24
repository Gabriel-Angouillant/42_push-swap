/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:51:02 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/16 19:33:13 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_to_max(t_stack **a, t_stack **b, int max, int pos)
{
	while ((*b)->index != max)
	{
		if (pos == 0)
			rb(b, 1);
		else if (pos == 1)
			rrb(b, 1);
	}
	pa(a, b, 1);
}

static void	b_to_a(t_stack **a, t_stack **b, int chunk, int max)
{
	while (*b)
	{
		if (is_max_top(*b, max, chunk) == 1)
			move_to_max(a, b, max, 0);
		else
			move_to_max(a, b, max, 1);
		max--;
	}
}

int	is_max_top(t_stack *b, int max, int check)
{
	while (check && b)
	{
		if (b->index == max)
			return (1);
		b = b->next;
		check--;
	}
	return (0);
}

void	a_to_b(t_stack **a, t_stack **b, int chunk, int max)
{
	int	num;

	num = 0;
	while (*a)
	{
		if ((*a)->index > num + chunk)
			ra(a, 1);
		else if ((*a)->index < num)
		{
			pb(a, b, 1);
			num++;
		}
		else if ((*a)->index >= num && (*a)->index <= num + chunk)
		{
			pb(a, b, 1);
			rb(b, 1);
			num++;
		}
	}
	b_to_a(a, b, chunk, max);
}
