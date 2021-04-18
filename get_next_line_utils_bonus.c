/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:01:38 by csantos-          #+#    #+#             */
/*   Updated: 2021/03/04 01:01:57 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != 0)
		len++;
	return (len);
}

char		*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while ((s[i] != '\0') && ((char)c != s[i]))
		i++;
	if ((char)c == s[i])
		return ((char *)s + i);
	else
		return (0);
}

char		*ft_strdup(char *s)
{
	char	*temp;

	if (!(temp = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	str_copy(temp, s, ft_strlen(s) + 1);
	return (temp);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!(temp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	str_copy(temp, s1, (ft_strlen(s1) + 1));
	str_copy((temp + ft_strlen(s1)), s2, (ft_strlen(s2) + 1));
	return (temp);
}

size_t		str_copy(char *dst, char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!(src))
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (*(src + i) != '\0' && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}
