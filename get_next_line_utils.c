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
char	*ft_get(char *s)
{
	char	*s2;
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
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char    *ft_save(char *vault)
{
	int	i;
	int	j;
    char *new;

	i = 0;
	j = 0;
	while (vault[i] != '\n')
		i++;
    if (!vault[i])
    {
        free(vault);
        return (NULL);
    }
    new = malloc(sizeof(char) * (ft_strlen(vault) - i + 1));
	i++;
	while(vault[i])
	{
		new[j] = vault[i];
		i++;
		j++;
	}
    new[j] = '\0';
    free(vault);
    return (new);
}
