/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:58:14 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 16:18:50 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data)
{
	int		width;
	int		height;

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			(data->col) * 64, (data->row) * 64, "Piggie got back");
	data->backgnd = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/grass.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/newall.xpm", &width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/piggie.xpm", &width, &height);
	data->coins = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/coins.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/Exit.xpm", &width, &height);
}

void	print_map(t_data *data)
{
	int	row;
	int	col;

	load_img(data);
	row = 0;
	while (row < data->row)
	{
		col = 0;
		while (col < data->col)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->backgnd, col * 64, row * 64);
			put_img(data->map[row][col], data, col, row);
			col++;
		}
		row++;
	}
}

void	put_img(char c, t_data *data, int col, int row)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall, col * 64, row * 64);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player, col * 64, row * 64);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->coins, col * 64, row * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit, col * 64, row * 64);
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->backgnd, col * 64, row * 64);
}

void	read_map(char *mapfile, t_data *data)
{
	int			fd;
	char		*all_char;
	char		*map;

	map = NULL;
	fd = open(mapfile, O_RDONLY);
	all_char = ft_strdup("");
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
			break ;
		all_char = ft_strjoin(all_char, map);
	}
	data->map = ft_split(all_char, '\n');
	close (fd);
}

char	*mapcheck(t_data *data)
{
	char		**newmap;

	newmap = data->map;
	data->row = 0;
	while (newmap[data->row])
	{
		data->col = 0;
		while (newmap[data->row][data->col])
		{
			data->col++;
		}
		data->row++;
	}
	return (*data->map);
}
