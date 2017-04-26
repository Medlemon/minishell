/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:49:31 by jerasmus          #+#    #+#             */
/*   Updated: 2016/08/08 16:21:54 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	if (*s == c)
		return ((char *)s);
	s--;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
