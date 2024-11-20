/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:56:47 by joschka           #+#    #+#             */
/*   Updated: 2024/11/20 13:20:54 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_scenery(t_scenery *scenery)
{
	scenery->scene = NULL;
	scenery->s_path = NULL;
	scenery->lcount = 0;
	scenery->fd = 0;
}

void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
}

void	init(t_data *data)
{
	init_scenery(&data->scenery);
	init_textures(&data->textures);
}
