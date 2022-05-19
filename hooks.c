/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:23:35 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 16:19:43 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys(int keycode, t_data *data)
{
	get_player(data->map, data, 'P');
	if ((keycode == KEY_A) && (data->map[data->row][data->col - 1]) == 'E')
		check_coins(data);
	else if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D && data->map[data->row][data->col + 1] == 'E')
		check_coins(data);
	else if (keycode == KEY_D)
		move_right(data);
	if (keycode == KEY_S && data->map[data->row + 1][data->col] == 'E')
		check_coins(data);
	else if (keycode == KEY_S)
		move_down(data);
	if (keycode == KEY_W && data->map[data->row - 1][data->col] == 'E')
		check_coins(data);
	else if (keycode == KEY_W)
		move_up(data);
	if (keycode == KEY_ESC)
		end_game(data);
	return (0);
}

int	exit_game(t_data *data)
{
	free (data->map);
	ft_printf("Congrats, you won!\n");
	exit (0);
	return (1);
}

char	*get_player(char **map, t_data *data, char c)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == c)
			{
				data->row = row;
				data->col = col;
				data->map = map;
				return (map[row] + col);
			}
			col++;
		}
		row++;
	}
	return (NULL);
}

int	count_coins(t_data *data)
{
	data->coin_count = 0;
	data->row = 0;
	while (data->map[data->row])
	{
		data->col = 0;
		while (data->map[data->row][data->col])
		{
			if (data->map[data->row][data->col] == 'C')
				data->coin_count++;
			data->col++;
		}
		data->row++;
	}
	return (data->coin_count);
}	

int	check_coins(t_data *data)
{
	if (count_coins(data) == 0)
		exit_game(data);
	else
		ft_printf("Please eat everything!\n");
	return (0);
}
