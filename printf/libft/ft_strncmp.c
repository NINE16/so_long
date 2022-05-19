/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:15:59 by nnemeth           #+#    #+#             */
/*   Updated: 2021/10/29 16:16:00 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (n);
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
