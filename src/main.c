/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:26 by joschka           #+#    #+#             */
/*   Updated: 2024/11/07 18:35:24 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	print_error(char *str, int errcode)
{
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
		return (print_error(ERR_DIR, 1));
	}
	// close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return(print_error(strerror(errno), errno));
	close(fd);
	if (check_extension(path))
		return (print_error(ERR_CUB, 1));
	return (0);
}

int	parsing(char *path, t_data *data)
{
	(void)data;
	if (check_file(path))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error(ERR_USAGE, 1));
	if (parsing(argv[1], &data))
		return (1);
	return (0);
}