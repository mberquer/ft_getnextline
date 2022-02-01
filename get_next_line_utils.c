/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:45 by mberquer          #+#    #+#             */
/*   Updated: 2022/02/01 17:08:08 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get(char **s)
{
	char	*s2;
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = ft_strchr(s, '\n');
	s2 = malloc((i + 2) * sizeof(char));
	if (!s2)
		return (NULL);
	while (j <= i)
	{
		s2[j] = s[j];
		s[j] = '0';
		j++;
	}
	s2[j] = '\0';
	temp = malloc((ft_strlen(s) - i + 1) * (sizeof(char)));
	if (!temp)
		return (NULL);
	ft_cpy(temp, s);
	free(s);
	*s = temp;
	return (s2);
}
