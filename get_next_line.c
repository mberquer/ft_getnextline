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

char	*ft_read(static char *vault, int fd, char *buf)
{
	int		ret;
	char	*new;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	while (!ft_check(buf))

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*vault;

	if (fd < 0 || BUFFER_SIZE  < 0 || count = -1)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)	
		return (NULL);
	return (ft_read(vault, fd, buf));
}
