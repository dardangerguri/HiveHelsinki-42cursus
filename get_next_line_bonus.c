/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:46:48 by dgerguri          #+#    #+#             */
/*   Updated: 2022/12/11 19:50:31 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free_strjoin(char *s1, char *s2)
{
	int		i;
	int		i_s2;
	char	*str;

	i = -1;
	i_s2 = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(*s1) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[i_s2] != '\0')
		str[i++] = s2[i_s2++];
	str[i] = '\0';
	free(s1);
	return (str);
}

static char	*unused_in_archive(char *archive)
{
	int		i;
	int		j;
	int		length_of_line;
	char	*unused_part;

	i = 0;
	while (archive[i] && archive[i] != '\n' && archive[i] != '\0')
		i++;
	if (archive[i] == '\n')
		i++;
	if (archive[i] == '\0')
	{
		free(archive);
		return (NULL);
	}
	length_of_line = ft_strlen(archive) - i;
	unused_part = malloc(sizeof(*unused_part) * length_of_line + 1);
	if (unused_part == NULL)
		return (NULL);
	j = 0;
	while (archive[i] != '\0')
		unused_part[j++] = archive[i++];
	unused_part[j] = '\0';
	free(archive);
	return (unused_part);
}

static char	*line_from_archive(char *archive)
{
	int		i;
	char	*c_line;

	i = 0;
	if (archive == NULL)
		return (NULL);
	while (archive[i] && archive[i] != '\n')
		i++;
	c_line = malloc(sizeof(*c_line) * (i + 1) + 1);
	if (c_line == NULL)
		return (NULL);
	i = 0;
	while (archive[i] && archive[i] != '\n')
	{
		c_line[i] = archive[i];
		i++;
	}
	if (archive[i] == '\n')
		c_line[i++] = '\n';
	c_line[i] = '\0';
	return (c_line);
}

static char	*reading_saving(int fd, char *archive, char *buf)
{
	int	byte;

	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte] = '\0';
		if (byte > 0)
		{
		archive = ft_free_strjoin(archive, buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	free(buf);
	return (archive);
}

char	*get_next_line(int fd)
{
	static char	*archive[FD_MAX];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		buf = malloc(sizeof(buf) * BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	archive[fd] = reading_saving(fd, archive[fd], buf);
	if (archive[fd] == NULL)
		return (NULL);
	line = line_from_archive(archive[fd]);
	if (line == NULL)
		return (NULL);
	archive[fd] = unused_in_archive(archive[fd]);
	return (line);
}
