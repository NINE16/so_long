/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:10:37 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/18 17:43:55 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_count(char *str, char c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*ft_cutoff(char *str, int start, int end)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc((end - start + 1) * sizeof(char));
	if (!new)
		return (0);
	while (start < end)
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tmp;
	int		start;

	if (!s)
		return (0);
	tmp = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!tmp)
		return (0);
	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && start >= 0)
		{
			tmp[j++] = ft_cutoff(s, start, i);
			start = -1;
		}
	}	
	tmp[j] = 0;
	return (tmp);
}

char	*ft_strdup(char *s1)
{
	char		*store;
	size_t		i;

	store = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (!s1)
		return (0);
	if (!store)
		return (0);
	while (s1[i])
	{
		store[i] = s1[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}

// char	*ft_strchr(char *s, int c)
// {
// 	int		i;
// 	char	*str;

// 	str = (char *) s;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((char) str[i] == (char) c)
// 			return (&str[i]);
// 		i++;
// 	}
// 	if ((char) str[i] == (char) c)
// 		return (&str[i]);
// 	return (0);
// }
