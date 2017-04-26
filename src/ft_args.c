/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:51:57 by jerasmus          #+#    #+#             */
/*   Updated: 2017/01/10 10:41:49 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

void		ft_freearr(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}

int			ft_count_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

void		ft_freetmp(char *str)
{
	if (ft_isalnum(str[0]) == 1)
	{
		if (str != NULL)
		{
			free(str);
		}
	}
}

char		*ft_argsjoin(char **args)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = "\0";
	tmp = "\0";
	while (args[i])
	{
		str = ft_strjoin(tmp, args[i]);
		if (i > 1)
			free(tmp);
		if (i < (ft_count_arr(args) - 1))
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free(tmp);
		}
		tmp = str;
		i++;
	}
	return (str);
}
