/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:46:08 by fneri             #+#    #+#             */
/*   Updated: 2023/10/25 14:54:45 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*support[4096];
	char		*temp;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_characters = ft_calloc(1, (BUFFER_SIZE + 1));
	if (!read_characters)
		return (NULL);
	out = newline_creator(fd, read_characters, support[fd], temp);
	free(read_characters);
	read_characters = NULL;
	if (!out)
		return (NULL);
	support[fd] = create_advance(out);
	return (out);
}

// int main()
// {
// 	int fd[3];
// 	char *line;

// 	fd[0] = open("text.txt", O_RDONLY);
// 	fd[1] = open("ciao.txt", O_RDONLY);
// 	fd[2] = open("hello", O_RDONLY);
// 	do
// 	{
// 		line = get_next_line(fd[0]);
// 		printf("%s", line);
// 		line = get_next_line(fd[1]);
// 		printf("%s", line);
// 		line = get_next_line(fd[2]);
// 		printf ("%s", line);
// 	}
// 	while (line);
// 	return (0);
// }