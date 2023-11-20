/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:52:59 by fneri             #+#    #+#             */
/*   Updated: 2023/11/04 19:23:16 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *in, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long i);
int		ft_puthex_low(unsigned int num);
int		ft_puthex_up(unsigned int num);
int		ft_pointer_puthex(uintptr_t ptr, int w);
#endif