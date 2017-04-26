/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:07:23 by jerasmus          #+#    #+#             */
/*   Updated: 2017/01/10 10:17:25 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_execute(t_var *v)
{
	int			i;
	int			p_count;
	char		*tmp;
	char		*tmp2;

	i = -1;
	p_count = 0;
	if (access(v->args[0], F_OK) != -1)
		return (v->args[0]);
	if (v->path != NULL)
	{
		while (v->path[p_count])
			p_count++;
		while (i++ < p_count && v->path[i] != NULL)
		{
			tmp2 = ft_strcat(v->path[i], "/");
			tmp = ft_strcat(tmp2, v->args[0]);
			if (access(tmp, F_OK) != -1)
				return (tmp);
		}
	}
	ft_putstr(v->args[0]);
	ft_putendl(": command not found");
	return (NULL);
}

int				ft_fork(t_var *v)
{
	pid_t		pid;
	int			sig;
	char		*tmp;

	tmp = ft_execute(v);
	sig = 1;
	if (tmp != NULL)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_putendl("error: forking failed");
			return (1);
		}
		if (pid > 0)
			wait(&sig);
		if (pid == 0)
			execve(tmp, v->args, v->env);
	}
	return (1);
}
