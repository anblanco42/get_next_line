/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:43:54 by anblanco          #+#    #+#             */
/*   Updated: 2024/05/02 14:41:34 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*concat_morsel(int fd, char *historic)
{
	char	*read_buffer;
	int		read_buffer_size;

	read_buffer_size = 1;
	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (ft_free(&historic));
	while (read_buffer_size > 0 && !ft_strchr(historic, '\n'))
	{
		read_buffer_size = read(fd, read_buffer, BUFFER_SIZE);
		if (read_buffer_size == -1)
			return (ft_free(&read_buffer), ft_free(&historic));
		read_buffer[read_buffer_size] = '\0';
		if (read_buffer_size > 0 && !historic)
			historic = ft_strdup(read_buffer);
		else if (read_buffer_size > 0)
			historic = ft_strjoin(historic, read_buffer);
	}
	ft_free(&read_buffer);
	return (historic);
}

char	*get_lines(char *historic, int size)
{
	int		len_line;
	char	*line;

	if (!ft_strchr(historic, '\n'))
		return (ft_strdup(historic));
	len_line = size;
	line = ft_substr(historic, 0, len_line);
	if (!line)
		return (ft_free(&line));
	return (line);
}

char	*update_historic(char *historic)
{
	char	*new_historic;
	int		i;
	int		pos_chr;

	i = 0;
	if (!ft_strchr(historic, '\n'))
		return (ft_free(&historic));
	new_historic = ft_strdup(historic);
	ft_free(&historic);
	if (!new_historic)
		return (NULL);
	pos_chr = ft_strchr(new_historic, '\n');
	historic = ft_substr(new_historic, pos_chr,
			ft_strlen(new_historic) - pos_chr);
	ft_free(&new_historic);
	if (!historic || !historic[0])
		return (ft_free(&historic));
	return (historic);
}

char	*get_next_line(int fd)
{
	static char	*historic[1392];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!historic[fd] || !ft_strchr(historic[fd], '\n'))
		historic[fd] = concat_morsel(fd, historic[fd]);
	if (!historic[fd])
		return (NULL);
	line = get_lines(historic[fd], ft_strchr(historic[fd], '\n'));
	if (!line)
		return (ft_free(&historic[fd]));
	historic[fd] = update_historic(historic[fd]);
	return (line);
}
