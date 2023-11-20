/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:51:25 by fneri             #+#    #+#             */
/*   Updated: 2023/10/24 19:14:52 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
char	*ft_substr(char *str, int start, int len);
void	*ft_calloc(int count, int size);

#endif