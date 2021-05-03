/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:48:15 by csantos-          #+#    #+#             */
/*   Updated: 2021/05/03 04:24:30 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	sizestr;

	if (!s)
		return (0);
	sizestr = ft_strlen(s) + 1;
	if (start > sizestr)
		return (ft_strdup(""));
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	str_copy(subs, (s + start), len + 1);
	subs[len] = '\0';
	return (subs);
}

char	*new_line(char *temp, char **line, int n)
{
	char	*extra;
	int		i;

	extra = NULL;
	i = 0;
	while ((*(temp + i) != '\n') && (*(temp + i) != '\0'))
		i++;
	if (temp[i] == '\n')
	{
		*line = ft_substr(temp, 0, i);
		extra = ft_strdup(&((temp)[i + 1]));
		free(temp);
	}
	else
	{
		*line = ft_strdup(temp);
		free(temp);
	}
	if (n != 0)
		if (!extra)
			return (NULL);
	return (extra);
}

int	do_read(int fd, char *buffer, char **temp, int *n)
{
	char	*othertemp;

	while (*n && (!(ft_strchr(*temp, '\n'))))
	{
		*n = read(fd, buffer, BUFFER_SIZE);
		if (*n < 0 || *n > BUFFER_SIZE)
		{
			free(buffer);
			return (0);
		}
		*(buffer + *n) = '\0';
		othertemp = ft_strjoin(*temp, buffer);
		free(*temp);
		*temp = othertemp;
	}
	free(buffer);
	return (1);
}

/*int	get_next_line(int fd, char **line)
{
	static char	*temp;
	char		*buffer;
	int			n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > RLIMIT_NOFILE)
		return (-1);
	if (!temp)
		temp = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	if (!(do_read(fd, buffer, &temp, &n)))
		return (-1);
	temp = new_line(temp, line, n);
	if (!n)
		return (0);
	return (1);
}*/

int	get_next_line (int fd, char **line)
{
	static char		*new_str;
	char			*buffer;
	int				bytes;

	bytes = 1;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > RLIMIT_NOFILE)
		return (-1);
	buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_str)
		new_str = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer))
		return (-1);
	if(!(do_read(fd, buffer, &new_str, &bytes)))
		return (-1);
	new_str = new_line(new_str, line, bytes);
	if(!bytes)
		return (0);
	return (1);
}
