/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:53 by joschka           #+#    #+#             */
/*   Updated: 2024/11/14 15:59:09 by jbeck            ###   ########.fr       */
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
# define ERR_XPM "file is not a .xpm file"
# define ERR_ELEMENT "unallowed Element in .cub file"
# define ERR_LAST "map is not last Element in .cub file"
# define ERR_CHAR "unallowed Character in map detected"
# define ERR_LABORD "or map is not sourrounded by Walls (1)"
# define ERR_TEXT "texture Element has wrong number of Arguments"

typedef struct s_textures
{
	char	**north;
	char	**south;
	char	**west;
	char	**east;
}	t_textures;


typedef struct s_scenery
{
	int		fd;
	int		lcount;
	char	*s_path;
	char	**scene;
}	t_scenery;

typedef struct s_data
{
	t_scenery	scenery;
	t_textures	textures;
}	t_data;

void	init(t_data *data);
int		parsing(char *path, t_data *data);
int		print_error(char *src, char *str, int errcode);
int		skip_whitespace(char *str);
void	free_array(char **arr);
int		get_scene(t_scenery *scenery);
int		check_elements(char **scene);
int		map_last(char **scene);
int		get_textures(t_data *data);


// DEBUG
void	print_array(char **arr);

#endif