/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:50:17 by gangouil          #+#    #+#             */
/*   Updated: 2024/01/06 19:50:19 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	init_line(t_line *line)
{
	if (line->buffer && line->at_eof == 1 && line->buffer[0] == 0)
	{
		free(line->buffer);
		return (-1);
	}
	if (!line->buffer)
	{
		line->buffer = ft_calloc(BUFFER_SIZE + 1);
		if (!line->buffer)
			return (-1);
		line->size = BUFFER_SIZE;
		line->cursor = 0;
		line->read_index = 0;
	}
	return (1);
}

int	find_newline(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *str, int n)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(n + 1);
	if (!new)
		return (NULL);
	while (str[i] && i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_calloc(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
