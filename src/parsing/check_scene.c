/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:32:19 by joschka           #+#    #+#             */
/*   Updated: 2024/11/14 14:56:14 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'))
		i++;
	return (i);
}

int	check_elements(char **scene)
{
	int	i;
	int	j;

	i = 0;
	while (scene[i])
	{
		j = skip_whitespace(scene[i]);
		if (!ft_strncmp(&scene[i][j], "NO", 2)
			|| !ft_strncmp(&scene[i][j], "SO", 2)
			|| !ft_strncmp(&scene[i][j], "WE", 2)
			|| !ft_strncmp(&scene[i][j], "EA", 2)
			|| !ft_strncmp(&scene[i][j], "F", 1)
			|| !ft_strncmp(&scene[i][j], "C", 1)
			|| !ft_strncmp(&scene[i][j], "1", 1)
			|| !ft_strncmp(&scene[i][j], "0", 1))
			i++;
		else
			return (print_error(NULL, ERR_ELEMENT, 1));
	}
	return (0);
}

static int	check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1'
			&& str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_last(char **scene)
{
	int	i;
	int	mapflag;
	int	j;

	i = 0;
	mapflag = 0;
	while (scene[i])
	{
		j = skip_whitespace(scene[i]);
		if (!strncmp(&scene[i][j], "1", 1))
			mapflag = 1;
		if (mapflag && strncmp(&scene[i][j], "1", 1))
			return (print_error(ERR_LAST, ERR_LABORD, 1));
		if (mapflag && check_chars(&scene[i][j]))
			return (print_error(NULL, ERR_CHAR, 1));
		i++;
	}
	return (0);
}
