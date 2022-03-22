/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:45 by mberquer          #+#    #+#             */
/*   Updated: 2022/02/01 22:25:26 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(char *s, char a)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != a)
		i++;
	return (i);
}
char	*ft_get(char **s)
{
	char	*s2;
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = ft_strchr(*s, '\n');
	s2 = malloc((i + 2) * sizeof(char));
	if (!s2)
		return (NULL);
	while (j <= i)
	{
		s2[j] = s[0][j];
		j++;
	}
	s2[j] = '\0';
	temp = malloc((ft_strlen(*s) - i + 1) * (sizeof(char)));
	if (!temp)
		return (NULL);
	ft_cpy(temp, s);
	free(*s);
	*s = temp;
	return (s2);
}

void	ft_cpy(char *s1, char **s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[0][i] != '\n')
		i++;
	i++;
	while(s2[0][i])
	{
		s1[j] = s2[0][i];
		i++;
		j++;
	}
    s1[j] = '\0';
}
