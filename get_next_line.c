/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:02 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/17 16:29:38 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char    *ft_join(char *s1, char *s2)
{

}
int     ft_cvault(static char vault)
{
    return (1);
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
	return (ft_read(vault, fd, buf, ft_cvault(vault)));
}
