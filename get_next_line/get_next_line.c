/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:42:21 by meudier           #+#    #+#             */
/*   Updated: 2022/08/29 20:27:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

static int	there_is_newline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

static char	*ft_get_line_and_str(char **str)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	len++;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len - 1 && (*str)[i])
	{
		line[i] = (*str)[i];
		i++;
	}
	line[i] = 0;
	i = 0;
	while ((*str)[len])
		(*str)[i++] = (*str)[len++];
	(*str)[i] = 0;
	return (line);
}

static char	*no_leaks(char **str, char *buffer)
{
	char	*temp;

	if (buffer)
		free (buffer);
	if (*str && ft_strlen(*str))
	{
		temp = *str;
		*str = NULL;
		return (temp);
	}
	else if (*str)
		free(*str);
	return (NULL);
}

int	get_str(int *rtr, int fd, char *buffer, char **str)
{
	char	*temp;

	*rtr = read(fd, buffer, BUFFER_SIZE);
	if (*rtr == -1)
		return (0);
	buffer[*rtr] = 0;
	if (!ft_strlen(buffer) && !*rtr && !there_is_newline(*str))
		return (0);
	temp = *str;
	*str = ft_strjoin(temp, buffer);
	free (temp);
	if (there_is_newline(*str))
		return (1);
	return (2);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str = NULL;
	int			rtr;
	char		*line;
	int			ret;

	rtr = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (no_leaks(&str, buffer));
	while (rtr > 0)
	{
		ret = get_str(&rtr, fd, buffer, &str);
		if (!ret)
			return (no_leaks(&str, buffer));
		if (ret == 1)
			break ;
	}
	line = ft_get_line_and_str(&str);
	if (!line)
		return (no_leaks(&str, buffer));
	free (buffer);
	return (line);
}
