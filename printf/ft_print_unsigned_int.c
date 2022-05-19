/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:50:09 by nnemeth           #+#    #+#             */
/*   Updated: 2021/12/28 12:55:16 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	i;
	long long		nb;

	nb = n;
	i = ft_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (nb == 0)
		str[i] = '0';
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

unsigned int	ft_print_unsignedint(unsigned int c)
{
	unsigned int	len;
	char			*num;

	len = 0;
	num = ft_uitoa(c);
	len = ft_printstr(num);
	free(num);
	return (len);
}
