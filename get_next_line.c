/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:02 by mberquer          #+#    #+#             */
/*   Updated: 2022/02/01 22:18:13 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_join(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*s3;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!s3)
		{
			free(s2);
			return (NULL);
		}
		while(s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
		while(s2[j])
		{
			s3[i] = s2[j];
			j++;
			i++;
		}
		s3[i] = '\0';
		free(s2);
		return (s3);
	}
	return (NULL);
}

int	ft_check(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if ((buf[i]) == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(char *vault, int fd, char *buf, int cvault)
{
	int		ret;
	char	*new;

	if (cvault == 1)
		return (ft_get(&vault));
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (ret < 0 || !buf)
		return (NULL);
	while (ret)
	{
		if (ft_check(buf))
		{
			vault = ft_join(vault, buf);
			new = ft_get(&vault);
			return (new);
		}
		vault = ft_join(vault, buf);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	vault = ft_join(vault, buf);
	new = ft_get(&vault);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*vault;

	if (fd < 0 || BUFFER_SIZE  < 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)	
		return (NULL);
	return (ft_read(vault, fd, buf, ft_check(vault)));
}
