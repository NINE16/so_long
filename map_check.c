/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:55:45 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 16:20:41 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks(t_data *data)
{
	data->row = 0;
	while (data->map[data->row])
	{
		data->col = 0;
		while (data->map[data->row][data->col])
		{
			error_check(data, data->map[data->row][data->col]);
			data->col++;
		}
		data->row++;
	}
	check_must(data);
	check_wall(data);
}

void	check_must(t_data *data)
{
	if (data->num_c == 0 || data->num_e == 0 || data->num_p != 1
		|| data->row == data->col)
	{
		ft_printf("Error!\n");
		if (data->num_c == 0)
			ft_printf("You don't have any collectibles!\n");
		if (data->num_e == 0)
			ft_printf("You have no exit!\n");
		if (data->num_p < 1)
			ft_printf("You have no player!\n");
		if (data->row == data->col)
			ft_printf("Your map should be rectangular!\n");
		end_game(data);
	}
}

void	error_check(t_data *data, char c)
{
	if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1')
	{
		ft_printf("Wrong map!");
		end_game(data);
	}
	if (c == 'C')
		data->num_c++;
	if (c == 'E')
		data->num_e++;
	if (c == 'P')
		data->num_p++;
}

void	check_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		// if (data->map[1][y] != '1' || data->map[data->row - 1][y] != '1')
		// {
		// 	ft_printf("Your map does not have walls!1\n");
		// 	end_game(data);
		// }
		while (data->map[x][y])
		{
			if (data->map[0][y] != '1' || data->map[data->row - 1][y] != '1' ||
				data->map[x][0] != '1' || data->map[x][data->col - 1] != '1')
			{
				ft_printf("Your map does not have walls!\n");
				end_game(data);
			}
			y++;
		}
		x++;
	}
}

int	end_game(t_data *data)
{
	free (data->map);
	exit (0);
	return (1);
}
