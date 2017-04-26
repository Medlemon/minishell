/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:43:48 by jerasmus          #+#    #+#             */
/*   Updated: 2016/11/25 11:23:43 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*memptr;

	i = 0;
	memptr = (unsigned char *)b;
	while (i < len)
	{
		memptr[i] = (unsigned char)c;
		i++;
	}
	return (memptr);
}
