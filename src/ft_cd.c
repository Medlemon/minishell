/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:20:57 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/08 13:20:42 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_path(char *str)
{
	int			i;
	int			j;
	char		*path;

	i = 0;
	j = 0;
	if (!(path = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '~')
			i++;
		path[j] = str[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

void			ft_cd(t_var *v)
{
	v->cd_path = NULL;
	v->home = NULL;
	v->pwd = NULL;
	v->old = NULL;
	v->home = ft_getenv("HOME", v);
	v->old = ft_getenv("OLD", v);
	v->pwd = ft_getenv("PWD", v);
	ft_setenv("OLDPWD", v->pwd, 1, v);
	if (v->args[1] != NULL)
	{
		v->cd_path = get_path(v->args[1]);
		if (v->args[1][0] == '~')
			chdir(ft_strcat(v->home, v->cd_path));
		else if (v->args[1][0] == '-')
			chdir(v->old);
		else
			chdir(v->cd_path);
	}
	else
		chdir(v->home);
	ft_setenv("PWD", getcwd(v->cwd, sizeof(v->cwd)), 1, v);
	free(v->cd_path);
	free(v->home);
	free(v->old);
	free(v->pwd);
}
