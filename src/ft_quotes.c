/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:15:34 by jerasmus          #+#    #+#             */
/*   Updated: 2016/11/24 14:25:21 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_dquote(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\"')
			i++;
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void			ft_squote(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\'')
			i++;
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

static int		ft_countdouble(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			j++;
		i++;
	}
	return (j);
}

static int		ft_countsingle(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			j++;
		i++;
	}
	return (j);
}

int				ft_countq(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			j = ft_countdouble(str);
			return (j);
		}
		else if (str[i] == '\'')
		{
			j = ft_countsingle(str);
			return (j);
		}
		else
			i++;
	}
	return (0);
}
