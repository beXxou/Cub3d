/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_and_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:32 by joschka           #+#    #+#             */
/*   Updated: 2024/11/20 16:07:39 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	squeaky_clean(t_data *data)
{
	if (data->scenery.scene)
		free_array(data->scenery.scene);
	if (data->textures.north)
		free_array(data->textures.north);
	if (data->textures.south)
		free_array(data->textures.south);
	if (data->textures.west)
		free_array(data->textures.west);
	if (data->textures.east)
		free_array(data->textures.east);
	if (data->textures.floor)
		free(data->textures.floor);
	if (data->textures.ceiling)
		free(data->textures.ceiling);
}

int	print_error(char *src, char *str, int errcode)
{
	ft_putstr_fd("Error\n", 2);
	if (src)
	{
		ft_putstr_fd(src, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (errcode);
}
