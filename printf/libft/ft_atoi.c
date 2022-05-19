/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:13:15 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/27 10:29:38 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(unsigned char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	int			i;
	int			is_negative;

	nbr = 0;
	i = 0;
	is_negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr *= 10;
		nbr += (int) str[i] - '0';
		i++;
	}
	return (nbr * is_negative);
}
