/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:24:06 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 02:26:02 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

char		*ft_strjoindel(char *s1, char *s2, int k)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen((char*)s1);
	len = j + ft_strlen((char*)s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < j)
		str[i] = s1[i];
	j = 0;
	while (i < len)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	k ? free(s2) : k;
	free(s1);
	return (str);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(*s) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_splitchelou(char **line)
{
	int		i;
	int		j;
	char	*temp;
	char	*retur;

	i = 0;
	j = 0;
	while (line[0][i] != '\n' && line[0][i])
		i++;
	if (!(retur = ft_substr(*line, i + 1, BUFFER_SIZE)))
		return (0);
	if (!(temp = ft_substr(*line, 0, i)))
		return (0);
	free(*line);
	if (!(*line = ft_strdup(temp)))
		return (0);
	free(temp);
	return (retur);
}
