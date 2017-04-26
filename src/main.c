/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:53:08 by jerasmus          #+#    #+#             */
/*   Updated: 2017/01/09 15:47:27 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				init(t_var *v)
{
	extern char		**environ;
	int				e_count;
	int				i;

	i = 0;
	e_count = ft_count_arr(environ);
	v->line = NULL;
	v->args = NULL;
	v->cd_path = NULL;
	v->home = NULL;
	v->pwd = NULL;
	v->old = NULL;
	v->eexit = "exit";
	v->env = (char **)ft_memalloc(sizeof(char *) * (e_count + 2));
	while (environ[i] != NULL)
	{
		v->env[i] = (char *)ft_memalloc(sizeof(char) *
				(ft_strlen(environ[i]) + 1));
		ft_strcpy(v->env[i], environ[i]);
		i++;
	}
	v->env[i] = NULL;
}

int					main(void)
{
	t_var			v;

	init(&v);
	ft_putendl(GREEN "Minishell v0.1" RESET);
	ft_loop(&v);
	return (0);
}
