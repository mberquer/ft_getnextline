/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:02 by mberquer          #+#    #+#             */
/*   Updated: 2022/02/02 00:11:32 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
    if (!s)
        return (0);
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
		s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!s3)
			return (NULL);
		while(s1 && s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
		while(s2 && s2[j])
		{
			s3[i] = s2[j];
			j++;
			i++;
		}
		s3[i] = '\0';
        if (s1)
            free(s1);
		return (s3);
}

int	ft_check(char *buf)
{
    int	i;

    i = 0;
    while (buf && buf[i])
    {
        if ((buf[i]) == '\n')
            return (1);
        i++;
    }
	return (NULL);
}

char	*ft_read(char *vault, int fd)
{
	int		ret;
	char	*buf;

    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (NULL);
    ret = 1;
    while (!ft_check(buf) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
        if (ret < 0)
        {
            free(vault);
            free(buf);
            return (NULL);
        }
		buf[ret] = '\0';
        vault = ft_join(vault, buf);
	}
    free(buf);
	return (vault);
}

char	*get_next_line(int fd)
{
	static char	*vault;
	char 	*line;

	if (fd < 0 || BUFFER_SIZE  < 0)
		return (NULL);
	vault = ft_read(vault, fd);
    if (!vault)
        return (NULL);
    line = ft_get(vault);
    vault = ft_save(vault);
	return (line);
}
