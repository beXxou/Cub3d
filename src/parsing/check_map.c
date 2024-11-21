/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:27:43 by joschka           #+#    #+#             */
/*   Updated: 2024/11/21 19:45:49 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_path(t_map *map, int row, int col)
{
	char	c;

	if (row < 0 || row >= map->height || col < 0 || col >= map->width)
		return (0);
	c = map->map_tab[row][col];
	if (c == '1')
		return (0);
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		map->not_surrounded++;
	if (c == ' ')
	{
		map->map_tab[row][col] = 'X';
		if (check_path(map, row - 1, col) || check_path(map, row + 1, col)
			|| check_path(map, row, col - 1) || check_path(map, row, col + 1))
		{
			return (1);
		}
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			if (map->map_tab[i][j] == ' ')
				check_path(map, i, j);
			j++;
		}
		i++;
	}
	print_array(map->map_tab);
	ft_printf("%d\n", map->not_surrounded);
	return (0);
}