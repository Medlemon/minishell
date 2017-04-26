/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:17:36 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/08 13:11:43 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_getchar(void)
{
	char			c;

	if (read(0, &c, 1) != 1)
		return (-1);
	return ((int)c);
}

char				*ft_getline(void)
{
	int				i;
	int				c;
	static char		buf[BUF_SIZE];

	i = 0;
	ft_memset(buf, 0, BUF_SIZE);
	while (1)
	{
		c = ft_getchar();
		if (c == '\n' || c == '\0')
		{
			buf[i] = '\0';
			return (buf);
		}
		else
			buf[i] = c;
		i++;
	}
	free(buf);
	return (0);
}
