/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:53 by joschka           #+#    #+#             */
/*   Updated: 2024/11/11 17:43:30 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <errno.h>

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"
# define ERR_DIR "is a Directory"
# define ERR_CUB "file without .cub extension"
# define ERR_ELEMENT "unallowed Element in .cub file"
# define ERR_LAST "map is not last Element in .cub file"
# define ERR_CHAR "unallowed Character in map detected"

typedef struct s_data
{
	int		fd;
	int		lcount;
	char	*s_path;
	char	**scene;
}	t_data;

void	init(t_data *data);
int		parsing(char *path, t_data *data);
int		print_error(char *src, char *str, int errcode);
void	free_array(char **arr);
int		get_scene(t_data *data);
int		check_elements(char **scene);
int		map_last(char **scene);

// DEBUG
void	print_array(char **arr);

#endif