/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:26 by joschka           #+#    #+#             */
/*   Updated: 2024/11/11 17:41:35 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
