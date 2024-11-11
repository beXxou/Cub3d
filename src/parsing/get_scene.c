/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:27:27 by joschka           #+#    #+#             */
/*   Updated: 2024/11/11 17:41:53 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	emptystr(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] && flag == 1)
	{
		if (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v')
			i++;
		else
			flag = 0;
	}
	return (flag);
}

static int	get_linenumber(char *path)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno), errno));
	else
	{
		line = get_next_line(fd);
		while (line)
		{
			if (!emptystr(line))
				count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (count);
}

static void	ft_simpstrcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return ;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	fill_scene(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		if (!emptystr(line))
		{
			data->scene[i] = malloc(ft_strlen(line) + 1 * sizeof(char));
			if (!data->scene[i])
			{
				free_array(data->scene);
				return (print_error(NULL, strerror(errno), errno));
			}
			ft_simpstrcpy(data->scene[i], line);
			i++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
	data->scene[i] = NULL;
	close(data->fd);
	return (0);
}

int	get_scene(t_data *data)
{
	data->lcount = get_linenumber(data->s_path);
	data->scene = malloc((data->lcount + 1) * sizeof(char *));
	if (!data->scene)
	{
		print_error(NULL, strerror(errno), errno);
		return (1);
	}
	data->fd = open(data->s_path, O_RDONLY);
	if (data->fd == -1)
		return (print_error(data->s_path, strerror(errno), errno));
	if (fill_scene(data))
	{
		free(data->scene);
		return (1);
	}
	return (0);
}