/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:04:19 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:17:42 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_assets(t_data *data)
{
	char	*path;
	int		img_width;
	int		img_height;

	data->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!data->textures)
	{
		ft_printf("Error\nmalloc failed\n");
		exit(1);
	}
	path = "assets/wall.xpm";
	data->textures->wall = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img_width, &img_height);
	path = "assets/floor.xpm";
	data->textures->floor = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img_width, &img_height);
	path = "assets/player.xpm";
	data->textures->player = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img_width, &img_height);
	path = "assets/donut.xpm";
	data->textures->collectible = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img_width, &img_height);
	path = "assets/exit.xpm";
	data->textures->exit = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img_width, &img_height);
}

static void	check_format(char *argv)
{
	if (ft_strnstr(argv, ".ber", ft_strlen(argv)) == NULL)
	{
		ft_printf("Error\nInvalid file format\n");
		exit(1);
	}
}

void	init_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width,
			data->map_height, WINDOW_NAME);
	if (!data->win_ptr)
	{
		ft_printf("Error\nmlx_new_window failed\n");
		exit(1);
	}
}

void	init_data(t_data *data, char **argv)
{
	int	fd;

	check_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile open failed\n");
		exit(1);
	}
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error\nmlx_init failed\n");
		exit(1);
	}
	data->map_width = (map_len(fd) * IMG_W);
	data->map_height = (map_height(fd) * IMG_H);
	data->map = ft_calloc(sizeof(char *), (data->map_height / IMG_H + 1));
	if (!data->map)
		error_handler('1');
	data->collectibles = 0;
	data->moves = 0;
	data->collectibles_collected = 0;
	init_assets(data);
	close(fd);
}
