/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:59:22 by jerasmus          #+#    #+#             */
/*   Updated: 2017/01/09 15:47:37 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_envloop(t_var *v, int i, const char *name, char **t)
{
	char		*ft;

	while (v->env[i])
	{
		t = ft_strsplit(v->env[i], '=');
		if (ft_strncmp(t[0], name, ft_strlen(name)) == 0)
		{
			ft = (char *)ft_memalloc(sizeof(char) * (ft_strlen(t[1] + 1)));
			ft_strcpy(ft, t[1]);
			ft_freearr(t);
			return (ft);
		}
		ft_freearr(t);
		i++;
	}
	return (NULL);
}

char			*ft_getenv(const char *name, t_var *v)
{
	int			i;
	char		**temp;
	char		*str;

	i = 0;
	temp = NULL;
	str = ft_envloop(v, i, name, temp);
	if (str != NULL)
		return (str);
	free(temp);
	return (NULL);
}
