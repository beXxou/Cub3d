/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:53 by joschka           #+#    #+#             */
/*   Updated: 2024/11/08 14:09:31 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"
# define ERR_DIR "is a Directory"
# define ERR_CUB "file without .cub extension"

typedef struct s_data
{
	int		fd;
	int		lcount;
	char	*s_path;
	char	**scene;
}	t_data;


#endif