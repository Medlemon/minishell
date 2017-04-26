/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:53 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/13 10:01:16 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>

void			ft_env(t_var *v)
{
	int			i;

	i = 0;
	while (v->env[i] != NULL)
	{
		ft_putendl(v->env[i]);
		i++;
	}
}

char			*ft_errchk(const char *n, const char *val, int owrite, t_var *v)
{
	char		*str;
	char		*strtmp;
	char		*fr;

	str = NULL;
	strtmp = NULL;
	fr = ft_getenv(n, v);
	if (n == NULL || n[0] == '\0' || ft_strchr(n, '=') != NULL ||
			val == NULL || ft_strchr(n, ' '))
		return (NULL);
	if (fr != NULL && owrite == 0)
		return (NULL);
	if (!(strtmp = ft_strjoin(n, "=")))
		return (NULL);
	if (!(str = ft_strjoin(strtmp, val)))
		return (NULL);
	free(strtmp);
	if (str == NULL)
		return (NULL);
	if (fr != NULL)
		free(fr);
	return (str);
}

int				ft_setenv(const char *n, const char *val, int owrite, t_var *v)
{
	int			i;
	char		**tmp;
	char		*str;
	char		*strtmp;

	i = -1;
	strtmp = ft_errchk(n, val, owrite, v);
	while (v->env[++i] != NULL)
	{
		tmp = ft_strsplit(v->env[i], '=');
		if (ft_strncmp(tmp[0], n, ft_strlen(n)) == 0)
		{
			ft_strcpy(v->env[i], strtmp);
			ft_freearr(tmp);
			free(strtmp);
			return (0);
		}
		ft_freearr(tmp);
	}
	str = strtmp;
	v->env[i] = v->env[i - 1];
	v->env[i - 1] = str;
	v->env[i + 1] = NULL;
	return (0);
}

int				ft_unsetenv(const char *name, t_var *v)
{
	int			i;
	char		**tmp;

	i = 0;
	while (v->env[i])
	{
		tmp = ft_strsplit(v->env[i], '=');
		if (ft_strncmp(tmp[0], name, ft_strlen(name)) == 0)
		{
			free(v->env[i]);
			while (v->env[i])
			{
				v->env[i] = v->env[i + 1];
				i++;
			}
			ft_freearr(tmp);
			return (0);
		}
		ft_freearr(tmp);
		i++;
	}
	return (0);
}
