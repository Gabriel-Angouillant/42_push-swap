/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:11:59 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/25 16:40:35 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	adjust_index(t_stack *stack, t_stack *node)
{
	while (stack)
	{
		if (stack != node && stack->content < node->content)
			node->index++;
		if (stack != node && stack->content > node->content)
			node->index--;
		stack = stack->next;
	}
	node->index /= 2;
}

int	is_sorted(t_stack *stack)
{
	int	min;

	min = -1;
	while (stack)
	{
		if (min > stack->index)
			return (0);
		min = stack->index;
		stack = stack->next;
	}
	return (1);
}

int	index_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		stack_size;

	tmp = stack;
	stack_size = ft_lstsize(stack);
	while (tmp)
	{
		tmp->index = stack_size;
		adjust_index(stack, tmp);
		tmp = tmp->next;
	}
	return (stack_size);
}

int	ft_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
