/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:22:04 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/29 13:36:07 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clear_line(t_line *line)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < line->cursor)
	{
		line->buffer[i] = 0;
		i++;
	}
	while (line->buffer[i + k] && i + k < line->size)
	{
		line->buffer[k] = line->buffer[i + k];
		k++;
	}
	line->read_index -= line->cursor;
	line->cursor = 0;
}

static char	*grow_buffer(t_line *line)
{
	char	*new_buffer;
	int		i;

	i = 0;
	new_buffer = ft_calloc(BUFFER_SIZE + line->size + 1);
	if (!new_buffer)
		return (NULL);
	while (line->buffer[i])
	{
		new_buffer[i] = line->buffer[i];
		i++;
	}
	line->size += BUFFER_SIZE;
	free(line->buffer);
	return (new_buffer);
}

static char	*get_line(t_line *line)
{
	char	*str;
	int		newline;

	newline = find_newline(line->buffer, line->cursor) + 1;
	if (line->at_eof == 1 && newline == 0)
	{
		str = ft_strndup(line->buffer, line->read_index);
		line->cursor = line->size;
		clear_line(line);
	}
	else
		str = ft_strndup(&line->buffer[line->cursor], newline - line->cursor);
	if (!str)
		return (NULL);
	line->cursor = newline;
	if (line->at_eof == 1)
	{
		free(line->buffer);
		line->buffer = NULL;
	}
	return (str);
}

static int	read_file(int fd, t_line *line)
{
	int	at_eol;
	int	read_bytes;

	at_eol = -1;
	while (at_eol == -1)
	{
		if (line->buffer[0] && line->size - line->read_index <= BUFFER_SIZE)
			line->buffer = grow_buffer(line);
		if (!line->buffer)
			return (-1);
		read_bytes = read(fd, &line->buffer[line->read_index], BUFFER_SIZE);
		line->read_index += read_bytes;
		if (read_bytes == -1)
		{
			free(line->buffer);
			return (-1);
		}
		if (read_bytes == 0 || read_bytes < BUFFER_SIZE)
		{
			line->at_eof = 1;
			return (0);
		}
		at_eol = find_newline(line->buffer, line->cursor);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_line	files[1024];
	t_line			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	line = &files[fd];
	if (init_line(line) == -1)
		return (NULL);
	if (find_newline(line->buffer, line->cursor) == -1)
	{
		if (line->cursor != 0)
			clear_line(line);
		if (read_file(fd, line) == -1)
			return (NULL);
	}
	if ((line->buffer && line->at_eof == 1 && line->buffer[0] == 0)
		|| (line->cursor == 0 && line->buffer && line->buffer[0] == '\n'))
	{
		free(line->buffer);
		line->buffer = NULL;
		return (NULL);
	}
	return (get_line(line));
}
