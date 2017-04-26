/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 12:27:15 by jerasmus          #+#    #+#             */
/*   Updated: 2016/08/08 16:27:32 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*ptr;
	char		buf[50];
	long int	num;
	int			neg;

	ptr = &buf[49];
	*ptr = '\0';
	neg = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		neg = 1;
	}
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		*--ptr = "01234567890ABCDEF"[num % 10];
		num /= 10;
	}
	if (neg == 1)
		*--ptr = '-';
	return (ft_strdup(ptr));
}
