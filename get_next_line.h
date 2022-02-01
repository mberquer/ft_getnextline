/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:34 by mberquer          #+#    #+#             */
/*   Updated: 2022/02/01 22:23:45 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strchr(char *s, char a);
char	*get_next_line(int fd);
char	*ft_read(char *vault, int fd, char *buf, int cvault);
int		ft_check(char *buf);
char	*ft_join(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_get(char **s);
void	ft_cpy(char *s1, char *s2);

#endif
