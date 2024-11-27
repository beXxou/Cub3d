/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:06 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 16:19:02 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_data *data)
{
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, WIDTH, HEIGHT, "Cub3d");
	// data->game.img = mlx_new_image(data->game.mlx, WIDTH, HEIGHT);
}

// int	handle_no_event(void *data)
// {
// 	/* This function needs to exist, but it is useless for the moment */
// 	(void)data;
// 	return (0);
// }

void	game(t_data *data)
{
	initialize(data);
	// mlx_loop_hook(data->game.mlx, &handle_no_event, &data);
	mlx_loop(data->game.mlx);
}