/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 17:04:39 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:16:24 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_border(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height / IMG_H)
	{
		x = 0;
		while (x < data->map_width / IMG_W)
		{
			if (y == 0 || y == data->map_height / IMG_H - 1)
			{
				if (data->map[y][x] != '1')
					error_map();
			}
			else if (x == 0 || x == data->map_width / IMG_W - 1)
			{
				if (data->map[y][x] != '1')
					error_map();
			}
			x++;
		}
		y++;
	}
}

static void	update_player_position(t_data *data)
{
	int	x;
	int	y;

	data->px = 0;
	data->py = 0;
	y = 0;
	while (y < data->map_height / IMG_H)
	{
		x = 0;
		while (x < data->map_width / IMG_W)
		{
			if (data->map[y][x] == 'P')
			{
				data->px = x;
				data->py = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_data *data)
{
	check_border(data);
	check_rules(data);
	update_player_position(data);
	check_valid_player_path(data, data->px, data->py);
}

void	parse_map(t_data *data, char **argv)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (y < data->map_height / IMG_H)
	{
		line = get_next_line(fd);
		if (!line)
			error_handler('2');
		data->map[y] = ft_strdup(line);
		if (!data->map[y])
		{
			ft_printf("Error\nft_strdup failed\n");
			exit(1);
		}
		y++;
		free(line);
	}
	data->map[y] = NULL;
	close(fd);
}
