/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:56:34 by gangouil          #+#    #+#             */
/*   Updated: 2024/01/06 19:54:57 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line
{
	char	*buffer;
	int		cursor;
	int		read_index;
	int		size;
	int		at_eof;
}				t_line;

char	*get_next_line(int fd);
char	*ft_calloc(int size);
char	*ft_strndup(char *str, int n);
int		init_line(t_line *line);
int		find_newline(char *str, int i);

#endif
