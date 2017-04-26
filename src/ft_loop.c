/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:17:14 by jerasmus          #+#    #+#             */
/*   Updated: 2017/01/10 10:42:26 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void			ft_freeargs(t_var *v)
{
	int			i;

	i = 0;
	if (v->args == NULL)
		return ;
	while (v->args[i] != NULL)
	{
		free(v->args[i]);
		i++;
	}
	if (v->args != NULL)
		free(v->args);
}

void			ft_exit(t_var *v)
{
	ft_putendl(GREEN "Goodguy. . . " RESET);
	ft_freeargs(v);
	ft_freearr(v->path);
	exit(0);
}

static int		ft_builtins(t_var *v)
{
	int			res;
	char		*str;

	str = v->args[0];
	res = 0;
	if (ft_strcmp(str, "echo") == 0 || ft_strcmp(str, "cd") == 0 ||
			ft_strcmp(str, "env") == 0 || ft_strcmp(str, "setenv") == 0 ||
			ft_strcmp(str, "unsetenv") == 0)
		res = 1;
	if (res == 1)
	{
		if (ft_strcmp(str, "echo") == 0)
			ft_echo(v);
		else if (ft_strcmp(str, "cd") == 0)
			ft_cd(v);
		else if (ft_strcmp(str, "env") == 0)
			ft_env(v);
		else if (ft_strcmp(str, "setenv") == 0 && v->args[1] != NULL &&
				v->args[2] != NULL)
			ft_setenv(v->args[1], v->args[2], 1, v);
		else if (ft_strcmp(str, "unsetenv") == 0 && v->args[1] != NULL)
			ft_unsetenv(v->args[1], v);
	}
	return (res);
}

static void		ft_printp(t_var *v)
{
	if (getcwd(v->cwd, sizeof(v->cwd)) != 0)
	{
		ft_putstr(CYAN);
		ft_putstr(v->cwd);
		ft_putstr(MAGENTA);
		ft_putstr(" $> ");
		ft_putstr(RESET);
	}
}

void			ft_loop(t_var *v)
{
	char		*tmp;
	char		*linetmp;

	while (42)
	{
		if (v->path != NULL)
			ft_freearr(v->path);
		if (v->args != NULL)
			ft_freearr(v->args);
		tmp = ft_getenv("PATH", v);
		ft_printp(v);
		linetmp = ft_getline();
		v->line = ft_strtrim(linetmp);
		v->args = ft_strsplit(v->line, ' ');
		v->path = ft_strsplit(tmp, ':');
		if (tmp != NULL)
			free(tmp);
		if (v->args[0] == '\0' || ft_builtins(v) == 1)
			continue;
		else if (ft_strcmp(v->args[0], "exit") == 0)
			ft_exit(v);
		else
			ft_fork(v);
	}
}
