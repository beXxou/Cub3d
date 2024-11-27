/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:53 by joschka           #+#    #+#             */
/*   Updated: 2024/11/22 16:18:07 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <errno.h>

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"
# define ERR_DIR "is a directory"
# define ERR_CUB "file without .cub extension"
# define ERR_XPM "file is not a .xpm file"
# define ERR_ELEMENT "unallowed element in .cub file"
# define ERR_LAST "map is not last element in .cub file"
# define ERR_CHAR "unallowed character in map detected"
# define ERR_LABORD "or map is not sourrounded by walls (1)"
# define ERR_TEXT "texture element has too many arguments"
# define ERR_TEX "please provide path to texture"
# define ERR_TE "element has too few arguments"
# define ERR_COLOR "invalid color code"
# define ERR_MAP "no valid map in .cub file found"
# define ERR_WALL "map is not surrounded by walls"
# define ERR_PLAYCOUNT "there has to be exactly one player"

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_game;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map_tab;
	int		not_surrounded;
	int		player_count;
}	t_map;

typedef struct s_textures
{
	char	**north;
	char	**south;
	char	**west;
	char	**east;
	int		*floor;
	int		*ceiling;
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
	t_map		map;
	t_game		game;
}	t_data;

void	init(t_data *data);
void	squeaky_clean(t_data *data);
int		parsing(char *path, t_data *data);
int		print_error(char *src, char *str, int errcode);
int		skip_space(char *str);
void	free_array(char **arr);
int		get_scene(t_scenery *scenery);
void	cut_newline(char **arr);
int		check_elements(char **scene);
int		map_last(char **scene);
int		get_textures(t_data *data);
int		get_colors(t_data *data);
int		get_map(t_data *data);
int		find_mapstart(char **arr);
int		check_map(t_map *map);
int		is_player(char c);
void	game(t_data *data);

// DEBUG
void	print_array(char **arr);
void	print_colorcode(int *color);

#endif