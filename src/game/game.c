/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:06 by joschka           #+#    #+#             */
/*   Updated: 2024/11/29 18:05:47 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_data *data)
{
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, WIDTH, HEIGHT, "Cub3d");
	data->game.img.img_ptr = mlx_new_image(data->game.mlx, WIDTH, HEIGHT);
	data->game.img.img_pixels_ptr = mlx_get_data_addr(data->game.img.img_ptr,
		&data->game.img.bits_per_pixel,
		&data->game.img.line_len,
		&data->game.img.endian);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*dst;
	
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	// (void)offset;
	// (void)color;
	dst = img->img_pixels_ptr + offset;
 	// dst[offset] = color & 0xFF;
    // dst[offset + 1] = (color >> 8) & 0xFF;
    // dst[offset + 2] = (color >> 16) & 0xFF;
	*(unsigned int *)dst = color;
}

void	color_screen(t_data *data, int color)
{
	for (int y = 0; y < HEIGHT; ++y)	
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			/*
			 * This function is much faster than the library one🏻
			 * 	~Buffer in the image and push only when ready-> No flickering effect
			*/
			my_pixel_put(&data->game.img,
						x, 
						y, 
						color);
		}
	}
}
void draw_square(int x, int y, int size, int color, t_game *game)
{
	for(int i = 0; i < size; i++)
		my_pixel_put(game->img.img_ptr, x + i, y, color);
	for(int i = 0; i < size; i++)
		my_pixel_put(game->img.img_ptr, x, y + i, color);
	for(int i = 0; i < size; i++)
		my_pixel_put(game->img.img_ptr, x + size, y + i, color);
	for(int i = 0; i < size; i++)
		my_pixel_put(game->img.img_ptr, x + i, y + size, color);
}

void	draw_map(t_data *data)
{
	int	x = 0;
	int y = 0;
	while (data->map.map_tab[y])
	{
		while (data->map.map_tab[y][x])
		{
			if (data->map.map_tab[y][x] == '1')
				draw_square(x * 64, y * 64, 64, 0xff, &data->game);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->game.mlx,
					data->game.win,
					data->game.img.img_ptr,
					0, 0);
}

int	esc_hook(t_data *data)
{
	write(1, "game over!!!\n", 13);
	mlx_destroy_image(data->game.mlx, data->game.img.img_ptr);
	mlx_destroy_window(data->game.mlx, data->game.win);
	mlx_destroy_display(data->game.mlx);
	squeaky_clean(data);
	exit(0);
}

int	ft_key(int key, t_data *data)
{
	ft_printf("%d\n", key);
	if (key == ESC)
		esc_hook(data);
	if (key == W)
		color_screen(data, 0xff);
	if (key == A)
		color_screen(data, 0xff00);
	mlx_put_image_to_window(data->game.mlx,
						data->game.win,
						data->game.img.img_ptr,
						0, 0);
	// mlx_destroy_image(data->game.mlx, data->game.img.img_ptr);
	return (0);
}

void	game(t_data *data)
{
	initialize(data);
	// draw_map(data);
	mlx_hook(data->game.win, 2, 1L << 0, ft_key, data);
	mlx_hook(data->game.win, 17, 0, esc_hook, data);
	mlx_loop(data->game.mlx);
}
