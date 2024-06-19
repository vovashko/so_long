/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 17:26:45 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:15:04 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_and_nullify(t_check *check, t_data *data)
{
	int	x;
	int	y;

	check->map_copy = malloc(sizeof(int *) * data->map_height);
	if (!check->map_copy)
		error_handler('1');
	y = 0;
	while (y < data->map_height)
	{
		check->map_copy[y] = malloc(sizeof(int *) * data->map_width);
		y++;
	}
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			check->map_copy[y][x] = 0;
			x++;
		}
		y++;
	}
}

static void	path_exist(t_check *check, t_data *data, int x, int y)
{
	if (check->exit_or_collectible == 0)
		return ;
	if (check->map_copy[y][x] == 0 && data->map[y][x] != '1')
	{
		check->map_copy[y][x] = 1;
		if (data->map[y][x] == 'E' || data->map[y][x] == 'C')
			check->exit_or_collectible--;
		if (data->map[y][x] == 'E')
			return ;
		if (y > 0)
			path_exist(check, data, x, y - 1);
		if (y < data->map_height - 1)
			path_exist(check, data, x, y + 1);
		if (x > 0)
			path_exist(check, data, x - 1, y);
		if (x < data->map_width - 1)
			path_exist(check, data, x + 1, y);
	}
}

static void	free_check(t_data *data, t_check *check)
{
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		free(check->map_copy[y]);
		y++;
	}
	free(check->map_copy);
	check->map_copy = NULL;
}

void	check_valid_player_path(t_data *data, int x, int y)
{
	t_check	check;

	check.exit_or_collectible = data->collectibles + 1;
	copy_and_nullify(&check, data);
	path_exist(&check, data, x, y);
	if (check.exit_or_collectible != 0)
	{
		ft_printf("Error\nNo valid path found\n");
		exit(1);
	}
	free_check(data, &check);
}
