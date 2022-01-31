/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:02 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/26 11:33:10 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_join(char *s1, char *s2)
{
	char	*s3;
	
	if (s1 && s2)
	{
		s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
		ft_strlcat(s3, s2, ft_strlen(s3) + ft_strlen(s2) + 1);
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

char	*ft_read(static char *vault, int fd, char *buf, int cvault)
{
	int		ret;
	char	*new;

	if (cvault == 1)
		return (ft_get(vault));
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	while (ret)
	{
		if (ft_check(buf))
		{
			new = ft_join(vault, ft_get(buf));
			ft_save(vault, buf);
			return (new);
		}
		ft_save(vault, buf);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	new = ft_join(vault, ft_get(buf));
	ft_save(vault, buf);
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
