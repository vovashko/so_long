/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_rules.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 16:45:23 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 18:57:50 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_content(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height / IMG_H)
	{
		x = 0;
		while (x < data->map_width / IMG_W)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'P' && data->map[y][x] != 'C'
				&& data->map[y][x] != 'E')
			{
				ft_printf("Error\nUnknown character encountered\n");
				exit(1);
			}
			x++;
		}
		y++;
	}
}

static int	count_collectibles(t_data *data)
{
	int	x;
	int	y;
	int	collectibles;

	collectibles = 0;
	y = 0;
	while (y < data->map_height / IMG_H)
	{
		x = 0;
		while (x < data->map_width / IMG_W)
		{
			if (data->map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}

static int	count_player(t_data *data)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = 0;
	while (y < data->map_height / IMG_H)
	{
		x = 0;
		while (x < data->map_width / IMG_W)
		{
			if (data->map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	return (player);
}

static int	count_exit(t_data *data)
{
	int	x;
	int	y;
	int	exit_field;

	exit_field = 0;
	y = 0;
	while (y < data->map_height / IMG_H)
	{
		x = 0;
		while (x < data->map_width / IMG_W)
		{
			if (data->map[y][x] == 'E')
				exit_field++;
			x++;
		}
		y++;
	}
	return (exit_field);
}

void	check_rules(t_data *data)
{
	int	player;
	int	collectibles;
	int	exit_field;

	check_content(data);
	player = count_player(data);
	exit_field = count_exit(data);
	collectibles = count_collectibles(data);
	if (player != 1)
		error_handler('3');
	else if (collectibles < 1)
		error_handler('4');
	else if (exit_field != 1)
		error_handler('5');
	data->collectibles = collectibles;
}
