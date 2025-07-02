/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:07:49 by afayad            #+#    #+#             */
/*   Updated: 2024/06/22 16:17:53 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
} */

static char	*_extract_line(char *line_buffer)
{
	char	*remainder;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	remainder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*remainder == 0)
	{
		free(remainder);
		remainder = NULL;
	}
	line_buffer[i + 1] = 0;
	return (remainder);
}

static char	*ft_find_char(char *s, int c)
{
	unsigned int	index;
	char			character;

	character = (char)c;
	index = 0;
	while (s[index])
	{
		if (s[index] == character)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == character)
		return ((char *)&s[index]);
	return (NULL);
}

static char	*_buffer_fill(int fd, char *remainder, char *buffer)
{
	ssize_t	i;
	char	*tmp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(remainder);
			return (NULL);
		}
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		tmp = remainder;
		remainder = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_find_char(buffer, '\n'))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remainder);
		free(buffer);
		remainder = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = _buffer_fill(fd, remainder, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = _extract_line(line);
	return (line);
}
