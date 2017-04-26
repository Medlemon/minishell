/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:51:57 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/08 13:27:01 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

static void		ft_printenv(char *str, t_var *v)
{
	int			i;
	int			j;
	char		temp[255];
	char		*strtmp;

	i = 1;
	j = 0;
	ft_memset(temp, '\0', 255);
	while (str[i] != '\0')
	{
		temp[j] = str[i];
		j++;
		i++;
	}
	strtmp = ft_getenv(temp, v);
	if (strtmp == NULL)
		ft_putendl("Environment Variable does not exist");
	else
		ft_putendl(strtmp);
	if (strtmp != NULL)
		free(strtmp);
}

static void		ft_dodouble(t_var *v, char *str)
{
	char *tmp;

	tmp = str;
	if (ft_countq(str) % 2 != 0)
	{
		while (1)
		{
			ft_putstr("dquote>");
			v->line = ft_getline();
			str = ft_strjoin(tmp, "\n");
			free(tmp);
			tmp = str;
			str = ft_strjoin(tmp, v->line);
			free(tmp);
			tmp = str;
			if (ft_countq(str) % 2 == 0)
			{
				ft_dquote(str);
				free(tmp);
				break ;
			}
		}
	}
	else if (ft_countq(str) % 2 == 0)
		ft_dquote(str);
}

static void		ft_dosingle(t_var *v, char *str)
{
	char *tmp;

	tmp = str;
	if (ft_countq(str) % 2 != 0)
	{
		while (1)
		{
			ft_putstr("squote>");
			v->line = ft_getline();
			str = ft_strjoin(tmp, "\n");
			free(tmp);
			tmp = str;
			str = ft_strjoin(tmp, v->line);
			free(tmp);
			tmp = str;
			if (ft_countq(str) % 2 == 0)
			{
				ft_squote(str);
				free(tmp);
				break ;
			}
		}
	}
	else if (ft_countq(str) % 2 == 0)
		ft_squote(str);
}

static void		ft_doquotes(t_var *v, char *str)
{
	int			i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\"')
		{
			ft_dodouble(v, str);
			break ;
		}
		else if (str[i] == '\'')
		{
			ft_dosingle(v, str);
			break ;
		}
	}
}

int				ft_echo(t_var *v)
{
	char		*str;

	str = "\0";
	if (v->args[1] == NULL)
	{
		ft_putchar('\n');
		return (0);
	}
	str = ft_argsjoin(v->args);
	if (str[0] == '$')
		ft_printenv(str, v);
	else if (ft_countq(str) == 0)
		ft_putendl(str);
	else if (ft_countq(str) != 0)
		ft_doquotes(v, str);
	if (str != NULL)
		free(str);
	return (0);
}
