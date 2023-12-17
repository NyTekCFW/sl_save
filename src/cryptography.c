/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cryptography.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:21:40 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/17 07:17:21 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/savedata.h"

void	*sv_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	ux;

	dest = s;
	ux = (unsigned char)c;
	while (n--)
		*dest++ = ux;
	return (s);
}

void	*sv_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

int	sv_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	*encrypt(void *mem, size_t size, unsigned char key)
{
	unsigned char	*buffer;
	unsigned char	*huffer;

	if (size < 1)
		return (error_handler(1), (void *)0);
	buffer = (unsigned char *)malloc(size);
	if (!buffer)
		return (error_handler(2), (void *)0);
	huffer = sv_memcpy(buffer, mem, size);
	while (size--)
	{
		*huffer = *huffer ^ key;
		huffer++;
	}
	return (buffer);
}
