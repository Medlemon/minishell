/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 09:54:28 by jerasmus          #+#    #+#             */
/*   Updated: 2016/08/01 10:25:33 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		d;
	size_t				i;
	unsigned char		*tempdst;
	const unsigned char	*tempsrc;

	i = 0;
	d = (unsigned char)c;
	tempdst = (unsigned char *)dst;
	tempsrc = (const unsigned char *)src;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		if (tempdst[i] == d)
			return (tempdst + 1 + i);
		i++;
	}
	return (0);
}
