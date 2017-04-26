/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 13:01:23 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/09 10:04:18 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		ft_word_count(const char *str, char c)
{
	int			count;
	int			sub;

	count = 0;
	sub = 0;
	while (*str != '\0')
	{
		if (sub == 1 && *str == c)
			sub = 0;
		if (sub == 0 && *str != c)
		{
			sub = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static int		ft_word_length(const char *str, char c)
{
	int			len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			word_count;
	int			index;

	index = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count((const char *)s, c);
	if (!(array = (char **)ft_memalloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	while (word_count >= 1)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(array[index] = ft_strsub((char const *)s, 0,
						ft_word_length(s, c))))
			return (NULL);
		s = s + ft_word_length(s, c);
		index++;
		word_count--;
	}
	array[index] = NULL;
	return (array);
}
