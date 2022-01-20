/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:02 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/20 15:42:24 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char    *ft_join(char *s1, char *s2)
{

}

int	ft_check(char *buf)
{
	int	i;

	i = 0;
	while (buf)
	{
		if ((buf[i]) == '\n')
			return (1);
	}
	return (0);
}

char	*ft_read(static char *vault, int fd, char *buf, int cvault)
{
	int		ret;
	char	*new;

	if (cvault == 1)
		return (ft_get(vault));
	while (ret = read(fd, buf, BUFFER_SIZE))
	{
		buf[ret] = '\0';
		if (ft_check(buf))
		{
			ft_join(vault, ft_save(buf));
			return (ft_get(ft_join(new, buf)));
		}
		ft_join(new, buf);
	}
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
