/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:43:39 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/25 16:25:43 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_empty(char *arg)
{
	int	i;
	int	all_space;

	i = 0;
	all_space = 1;
	while (arg[i])
	{
		if (arg[i] != ' ')
			all_space = 0;
		i++;
	}
	return (all_space);
}

static void	write_args(int argc, char **argv, char *join_args)
{
	int	i;
	int	k;
	int	j;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			join_args[k] = argv[i][j];
			j++;
			k++;
		}
		join_args[k] = ' ';
		k++;
		i++;
	}
	join_args[k - 1] = 0;
}

char	*get_args(int argc, char **argv)
{
	char	*join_args;
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (NULL);
		if (is_empty(argv[i]) == 1)
			return (NULL);
		len += ft_strlen(argv[i]);
		i++;
	}
	join_args = malloc(len + i - 1);
	write_args(argc, argv, join_args);
	return (join_args);
}
