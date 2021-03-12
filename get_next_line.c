/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:22:59 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 14:16:24 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (len == 0 && start > ft_strlen((char *)s))
		return (ft_strdup("\0"));
	if (len > ft_strlen((char *)s + start))
		len = ft_strlen((char *)s + start);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	while (i < len)
		str[i++] = s[start++];
	return (str);
}

char	*ft_read(int fd, char *buffer, char **line)
{
	int res;

	if (buffer)
		if (!(*line = ft_strdup(buffer)))
			return (0);
	if (((res = read(fd, buffer, BUFFER_SIZE)) < 0))
		return (0);
	buffer[res] = '\0';
	if (res < BUFFER_SIZE)
	{
		if (!(*line = ft_strjoindel(*line, buffer, 0)))
			return (0);
		return (*line);
	}
	if (!(*line))
		if (!(*line = ft_strdup(buffer)))
			return (0);
	if (!(ft_strchr(buffer, '\n')))
	{
		if (!(*line = ft_strjoindel(*line, ft_read(fd, buffer, line), 1)))
			return (0);
	}
	else if (!(*line = ft_strjoindel(*line, buffer, 0)))
		return (0);
	return (*line);
}

int		fill_line(char **line, char *buffer)
{
	char	*temp;
	int		i;

	i = -1;
	while (++i < BUFFER_SIZE)
		buffer[i] = 0;
	if (!(temp = ft_splitchelou(line)))
		return (-1);
	i = -1;
	while (temp[++i])
		buffer[i] = temp[i];
	free(temp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[10240][BUFFER_SIZE + 1];
	int			i;

	i = -1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	if (ft_strchr(buffer[fd], '\n'))
	{
		if (!(*line = ft_strdup(buffer[fd])))
			return (-1);
		return (fill_line(line, buffer[fd]));
	}
	else if ((ft_read(fd, buffer[fd], line)) && ft_strchr(*line, '\n'))
		return (fill_line(line, buffer[fd]));
	else
	{
		while (++i < BUFFER_SIZE)
			buffer[fd][i] = 0;
		if (!(*line = ft_strjoindel(*line, "", 0)))
			return (-1);
		return (0);
	}
}
