/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:58:42 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 13:31:56 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc (sizeof(t_data) + 1);
	data->img = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->backgnd = NULL;
	data->coins = NULL;
	data->map = NULL;
	data->player = NULL;
	data->ptr = NULL;
	data->steps = 0;
	data->num_c = 0;
	data->num_e = 0;
	data->num_p = 0;
	return (data);
}
