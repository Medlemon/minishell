/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 07:56:03 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/13 07:40:23 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!(s1 && s2))
		return (NULL);
	if (!(new = (char *)ft_memalloc(sizeof(char *) * ((ft_strlen(s1) +
							ft_strlen(s2)) + 1))))
		return (NULL);
	ft_strcpy(new, (char *)s1);
	ft_strcat((new), (char *)s2);
	return (new);
}
