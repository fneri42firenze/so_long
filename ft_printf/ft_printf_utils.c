/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:47:28 by fneri             #+#    #+#             */
/*   Updated: 2023/10/30 14:16:35 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(long i)
{
	int		count;

	count = 0;
	if (i == 0)
		return (ft_putchar('0'));
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
		count++;
	}
	if (i >= 10)
		count += ft_putnbr(i / 10);
	count += ft_putchar((i % 10) + '0');
	return (count);
}

int	ft_puthex_low(unsigned int num)
{
	char	*num_hex_low;
	int		count;

	num_hex_low = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_puthex_low(num / 16);
		count += ft_puthex_low(num % 16);
	}
	else
		count += ft_putchar(num_hex_low[num]);
	return (count);
}

int	ft_puthex_up(unsigned int num)
{
	char	*num_hex_up;
	int		count;

	num_hex_up = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += ft_puthex_up(num / 16);
		count += ft_puthex_up(num % 16);
	}
	else
		count += ft_putchar(num_hex_up[num]);
	return (count);
}

int	ft_pointer_puthex(uintptr_t ptr, int w)
{
	int		count;
	char	*num_hex_low;

	num_hex_low = "0123456789abcdef";
	count = 0;
	if (!ptr && !w)
		return (ft_putstr("(nil)"));
	if (w == 0)
		count += ft_putstr("0x");
	if (ptr >= 16)
	{
		count += ft_pointer_puthex(ptr / 16, 1);
		count += ft_pointer_puthex(ptr % 16, 1);
	}
	else
		count += ft_putchar(num_hex_low[ptr]);
	return (count);
}
