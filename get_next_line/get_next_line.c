/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:50:28 by fneri             #+#    #+#             */
/*   Updated: 2023/10/25 14:54:31 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newline_creator(int fd, char *read_characters,
							char *support, char *temp)
{
	int	readable;

	readable = 1;
	while (readable > 0)
	{
		readable = read(fd, read_characters, BUFFER_SIZE);
		if (readable == -1)
			return (NULL);
		if (readable == 0)
			break ;
		read_characters[readable] = '\0';
		if (!support)
		{
			support = ft_calloc(1, 1);
			if (!support)
				return (NULL);
			support[0] = '\0';
		}
		temp = support;
		support = ft_strjoin(temp, read_characters);
		free(temp);
		if (ft_strchr(support, '\n'))
			break ;
	}
	return (support);
}

char	*create_advance(char *out)
{
	int		i;
	char	*advance;

	i = 0;
	while (out[i] && out[i] != '\n')
		i++;
	if (out[i] == '\0')
		return (NULL);
	advance = ft_substr(out, i + 1, ft_strlen(out) - i);
	if (!advance)
		return (NULL);
	if (advance[0] == '\0')
	{
		free(advance);
		advance = NULL;
		return (NULL);
	}
	out[i + 1] = '\0';
	return (advance);
}

char	*get_next_line(int fd)
{
	char		*read_characters;
	char		*out;
	static char	*support;
	char		*temp;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_characters = ft_calloc(1, (BUFFER_SIZE + 1));
	if (!read_characters)
		return (NULL);
	out = newline_creator(fd, read_characters, support, temp);
	free(read_characters);
	read_characters = NULL;
	if (!out)
		return (NULL);
	support = create_advance(out);
	return (out);
}

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("ciao.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }