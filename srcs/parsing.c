/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:00:44 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/25 16:23:04 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_atoi(char *str, int *is_valid, int *i)
{
	long long	num;
	int			istart;

	istart = *i;
	num = 0;
	if (str[*i] == '-')
		(*i)++;
	else if (str[*i] == '+')
		(*i)++;
	if (str[*i] < '0' || str[*i] > '9')
		*is_valid = 0;
	while (*is_valid == 1 && str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + (str[*i] - '0');
		if ((num > INT_MAX && str[istart] != '-') || (-num) < INT_MIN)
		{
			*is_valid = 0;
			return (0);
		}
		(*i)++;
	}
	if (str[istart] == '-')
		num = -num;
	return ((int)num);
}

static int	char_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')
			&& str[i] != ' ' && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

static int	duplicate_check(t_stack *stack, t_stack *new_elem)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->content == new_elem->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	args_check(t_stack **stack, char *str)
{
	t_stack	*new_elem;
	int		is_valid;
	int		i;

	i = 0;
	is_valid = 1;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (1);
		new_elem = ft_lstnew(ft_atoi(str, &is_valid, &i), NULL);
		if (!new_elem || is_valid == 0
			|| duplicate_check(*stack, new_elem) == 0)
		{
			free(new_elem);
			return (0);
		}
		ft_lstadd_back(stack, new_elem);
		if (str[i] && str[i] != ' ')
			return (0);
	}
	return (1);
}

int	parsing(char *args, t_stack **stack)
{
	int		i;
	int		is_valid;

	i = 0;
	if (!args)
		return (0);
	if (char_check(args) == 0)
	{
		free(args);
		return (0);
	}
	is_valid = args_check(stack, args);
	free(args);
	return (is_valid);
}
