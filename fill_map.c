/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 16:45:23 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:06:38 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_data *data, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures->wall, x, y);
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures->floor, x, y);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures->player, x, y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures->collectible, x, y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures->exit, x, y);
}

void	fill_map(t_data *data)
{
	data->collectibles_collected = 0;
	data->x = 0;
	data->y = 0;
	while (data->y < (data->map_height / IMG_H))
	{
		data->x = 0;
		while (data->x < (data->map_width / IMG_W))
		{
			if (data->map[data->y][data->x] == '1')
				put_img(data, data->x * IMG_W, data->y * IMG_H, '1');
			if (data->map[data->y][data->x] == '0')
				put_img(data, data->x * IMG_W, data->y * IMG_H, '0');
			if (data->map[data->y][data->x] == 'P')
				put_img(data, data->px * IMG_W, data->py * IMG_H, 'P');
			if (data->map[data->y][data->x] == 'C')
				put_img(data, data->x * IMG_W, data->y * IMG_H, 'C');
			if (data->map[data->y][data->x] == 'E')
				put_img(data, data->x * IMG_W, data->y * IMG_H, 'E');
			data->x++;
		}
		data->y++;
	}
}
