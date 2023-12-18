/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:06:33 by fneri             #+#    #+#             */
/*   Updated: 2023/12/18 19:51:44 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long	len;
	long	tmp_len;
	char	*res;

	len = len_nb(nbr);
	tmp_len = nbr;
	if (nbr < 0)
		tmp_len *= -1;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	if (tmp_len == 0)
		res[0] = '0';
	else
	{
		while (len--, tmp_len != 0)
		{
			res[len] = (tmp_len % 10) + '0';
			tmp_len = (tmp_len - (tmp_len % 10)) / 10;
		}
		if (nbr < 0)
			res[len] = '-';
	}
	return (res);
}
// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	//  char	*tmp;

// 	str = (char *)malloc(sizeof(char) * 2);
// 	if (!str)
// 		return (NULL);
// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		str[1] = '\0';
// 		str = ft_strjoin(str, ft_itoa(-n));
// 	}
// 	else if (n >= 10)
// 		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
// 	else if (n < 10 && n >= 0)
// 	{
// 		str[0] = n + '0';
// 		str[1] = '\0';
// 	}
// 	//  tmp = str;
// 	// free(tmp);
// 	return (str);
// }
/*
int main()
{
    int n = -2147483648;
    printf("%s\n", ft_itoa(n));
}
*/
