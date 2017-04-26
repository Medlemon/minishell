/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:58:11 by jerasmus          #+#    #+#             */
/*   Updated: 2016/08/22 14:11:01 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		k = 0;
		j = i;
		while (big[j] == little[k])
		{
			if (j == len)
				break ;
			j++;
			k++;
			if (little[k] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
