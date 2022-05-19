/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:49:55 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 13:44:25 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	get_player(data->map, data, 'P');
	data->col--;
	if (data->map[data->row][data->col] != '1')
	{
		if (data->map[data->row][data->col] != 'E' && data->coin_count != 0)
		{
			data->map[data->row][data->col] = 'P';
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player, data->col * 64, data->row * 64);
			data->map[data->row][data->col + 1] = '0';
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->backgnd, (data->col + 1) * 64,
				data->row * 64);
			data->steps++;
			ft_printf("%s%d\n", "Number of steps:", data->steps);
			count_steps(data);
		}
	}
}

void	move_right(t_data *data)
{
	get_player(data->map, data, 'P');
	data->col++;
	if (data->map[data->row][data->col] != '1')
	{
		if (data->map[data->row][data->col] != 'E' && data->coin_count != 0)
		{
			data->map[data->row][data->col] = 'P';
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player, data->col * 64, data->row * 64);
			data->map[data->row][data->col - 1] = '0';
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->backgnd, (data->col - 1) * 64,
				data->row * 64);
			data->steps++;
			ft_printf("%s%d\n", "Number of steps:", data->steps);
			count_steps(data);
		}
	}
}

void	move_down(t_data *data)
{
	get_player(data->map, data, 'P');
	data->row++;
	if (data->map[data->row][data->col] != '1')
	{
		data->map[data->row][data->col] = 'P';
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player, data->col * 64, data->row * 64);
		data->map[data->row - 1][data->col] = '0';
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->backgnd, data->col * 64, (data->row - 1) * 64);
		data->steps++;
		ft_printf("%s%d\n", "Number of steps:", data->steps);
		count_steps(data);
	}
}

void	move_up(t_data *data)
{
	get_player(data->map, data, 'P');
	data->row--;
	if (data->map[data->row][data->col] != '1')
	{
		data->map[data->row][data->col] = 'P';
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player, data->col * 64, data->row * 64);
		data->map[data->row + 1][data->col] = '0';
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->backgnd, data->col * 64, (data->row + 1) * 64);
		data->steps++;
		ft_printf("%s%d\n", "Number of steps:", data->steps);
		count_steps(data);
	}
}

void	count_steps(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
		0 * 64, 0 * 64);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 32, 16,
		0x00FFB6C1, ft_itoa(data->steps));
}
