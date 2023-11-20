/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:47:21 by fneri             #+#    #+#             */
/*   Updated: 2023/10/24 19:24:29 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*leftover;
	int		i;

	if (!str)
		return (NULL);
	leftover = malloc(sizeof(char) * (len + 1));
	if (!leftover)
		return (NULL);
	i = 0;
	while (len--)
		leftover[i++] = str[start++];
	leftover[i] = '\0';
	return (leftover);
}

void	*ft_calloc(int count, int size)
{
	void			*appoggio;
	int				i;
	unsigned char	*l;

	appoggio = malloc(count * size);
	if (appoggio == NULL)
		return (appoggio);
	l = (unsigned char *)appoggio;
	i = 0;
	while (i < count)
	{
		*(l + i) = 0;
		i++;
	}
	return (appoggio);
}
