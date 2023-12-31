/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:35:18 by fneri             #+#    #+#             */
/*   Updated: 2023/10/11 20:28:48 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	pointer = (unsigned char *)s;
	while (i < n)
	{
		*(pointer + i++) = (unsigned char)c;
	}
	return (s);
}
/*int main()
{
	char str[] = "Hello world";
	char *p;
	p = ft_memset(str, 'w', 11);
	printf("%s", p);
	return (0);
}*/
/*
Riceve tre argomenti:
void *s: un puntatore a una zona di memoria da inizializzare.
int c: il valore con cui inizializzare i byte.
size_t n: il numero di byte da inizializzare 
a partire dall'indirizzo puntato da s.

All'interno della funzione, vengono dichiarate due variabili:
pointer, un puntatore a unsigned char, 
e i, una variabile di tipo size_t.

Un ciclo while itera da 0 fino a n - 1. 
Durante ogni iterazione, il valore c 
viene convertito in unsigned char 
e quindi assegnato all'indirizzo puntato da pointer + i. 
Questo comporta l'inizializzazione dei byte 
nella zona di memoria con il valore c.

Alla fine del ciclo, la funzione restituisce 
il puntatore originale s,
che punta alla zona di memoria inizializzata
*/
