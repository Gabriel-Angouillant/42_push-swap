/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:00:52 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/25 16:40:43 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_sort(t_stack **a, t_stack **b, int size)
{
	if (size + 1 == 2)
		two_stack(a);
	else if (size + 1 == 3)
		three_stack(a);
	else if (size + 1 == 4)
		four_stack(a, b);
	else if (size + 1 == 5)
		five_stack(a, b);
	else if (size + 1 <= 250)
		a_to_b(a, b, 15, size);
	else
		a_to_b(a, b, 30, size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (parsing(get_args(argc, argv), &a) == 0)
	{
		ft_lstclear(a);
		write(2, "Error\n", 6);
		return (0);
	}
	size = index_stack(a);
	if (is_sorted(a) == 0)
		choose_sort(&a, &b, size);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}
