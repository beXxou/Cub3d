/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:26 by joschka           #+#    #+#             */
/*   Updated: 2024/11/08 14:24:11 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	print_error(char *src, char *str, int errcode)
{
	if (src)
	{
		ft_putstr_fd(src, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (errcode);
}

int	check_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'b' || path[len - 2] != 'u'
		|| path[len - 3] != 'c' || path[len - 4] != '.')
		return (1);
	return (0);
}

int	check_file(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (print_error(path, ERR_DIR, 1));
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno), errno));
	close(fd);
	if (check_extension(path))
		return (print_error(path, ERR_CUB, 1));
	return (0);
}

int	emptystr(char *str)
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

int	get_linenumber(char *path)
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

void	ft_simpstrcpy(char *dest, char *src)
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

int	fill_scene(t_data *data)
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

void	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("%s", arr[i]);
		i++;
	}
}

int	parsing(char *path, t_data *data)
{
	if (check_file(path))
		return (1);
	data->s_path = path;
	if (get_scene(data))
		return (1);
	print_array(data->scene);
	return (0);
}

void	init(t_data *data)
{
	data->scene = NULL;
	data->s_path = NULL;
	data->lcount = 0;
	data->fd = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error(NULL, ERR_USAGE, 1));
	init(&data);
	if (parsing(argv[1], &data))
		return (1);
	free_array(data.scene);
	return (0);
}
