/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 11:44:46 by jerasmus          #+#    #+#             */
/*   Updated: 2016/08/01 12:46:47 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temps;

	i = 0;
	temps = (unsigned char *)s;
	while (i < n)
	{
		if (temps[i] == (unsigned char)c)
			return (temps + i);
		i++;
	}
	return (0);
}
