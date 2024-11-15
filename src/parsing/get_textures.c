/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:43:40 by jbeck             #+#    #+#             */
/*   Updated: 2024/11/15 13:23:32 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static int	check_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'm' || path[len - 2] != 'p'
		|| path[len - 3] != 'x' || path[len - 4] != '.')
		return (1);
	return (0);
}

static int	check_xpm_file(char *path)
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
	if (check_xpm_extension(path))
		return (print_error(path, ERR_XPM, 1));
	return (0);
}

void	cut_newline(char **arr)
{
	int		len;
	char	*tmp;
	
	len = ft_strlen(arr[1]);
	if (arr[1][len - 1] == '\n')
	{
		tmp = malloc((len) * sizeof(char));
		ft_strlcpy(tmp, arr[1], len );
		free(arr[1]);
		arr[1] = tmp;
		print_array(arr);
	}
}

int	check_array(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		ft_printf("heeee\n");
		if (i == 1)
			cut_newline(arr);
		if (i == 1 && check_xpm_file(arr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	save_texture(char *str, char **arr)
{
	if (arr)
		free_array(arr);
	arr = ft_split(str, ' ');
	if (!arr)
		return (1);
	if (check_array(arr))
	{
		free_array(arr);
		return (1);
	}
	return (0);
}

int	get_textures(t_data *data)
{
	char	**arr;
	int		i;
	int		ret;
	int		j;

	i = 0;
	ret = 0;
	j = 0;
	arr = data->scenery.scene;
	while (arr[i])
	{
		if (ret)
			break ;
		j = skip_whitespace(arr[i]);
		if (!ft_strncmp(&arr[i][j], "NO", 2) && !ret)
			ret = save_texture(arr[i], data->textures.north);
		i++;
	}
	return (ret);
}