/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:44:10 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 15:57:36 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("%s\n", "You don't have enough arguments!");
		exit(1);
	}
	if (!strchr(argv[1], '.'))
	{
		ft_printf("%s\n", "Invalid file!");
		exit(1);
	}
	if (ft_strncmp((ft_strrchr(argv[1], '.')), ".ber", 5))
	{
		ft_printf("%s\n", "Invalid extension!");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	char	*map;
	t_data	*data;

	check_args(argc, argv);
	data = init_data();
	map = NULL;
	read_map(argv[1], data);
	mapcheck(data);
	checks(data);
	print_map(data);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, end_game, data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 64, 16,
		0x00FFB6C1, "Steps");
	mlx_loop(data->mlx_ptr);
	free (data->map);
	return (0);
}
