/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:20:34 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 17:19:41 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures->floor,
		data->px * IMG_W, data->py * IMG_H);
	if (data->map[data->py - 1][data->px] != '1' && data->map[data->py
		- 1][data->px] != 'E')
	{
		if (data->map[data->py][data->px] == 'C')
		{
			data->collectibles_collected++;
			data->map[data->py][data->px] = '0';
		}
		data->py--;
		data->moves++;
	}
	else if (data->map[data->py - 1][data->px] == 'E'
		&& data->collectibles_collected != data->collectibles)
		ft_printf("Collect all pieces of cake first!\n");
	else if (data->map[data->py - 1][data->px] == 'E'
		&& data->collectibles_collected == data->collectibles)
	{
		data->py--;
		data->moves++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->textures->player, data->px * IMG_W, data->py * IMG_H);
	mlx_do_sync(data->mlx_ptr);
}

void	move_down(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures->floor,
		data->px * IMG_W, data->py * IMG_H);
	if (data->map[data->py + 1][data->px] != '1' && data->map[data->py
		+ 1][data->px] != 'E')
	{
		if (data->map[data->py][data->px] == 'C')
		{
			data->collectibles_collected++;
			data->map[data->py][data->px] = '0';
		}
		data->py++;
		data->moves++;
	}
	else if (data->map[data->py + 1][data->px] == 'E'
		&& data->collectibles_collected != data->collectibles)
		ft_printf("Collect all pieces of cake first!\n");
	else if (data->map[data->py + 1][data->px] == 'E'
		&& data->collectibles_collected == data->collectibles)
	{
		data->py++;
		data->moves++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->textures->player, data->px * IMG_W, data->py * IMG_H);
	mlx_do_sync(data->mlx_ptr);
}

void	move_left(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures->floor,
		data->px * IMG_W, data->py * IMG_H);
	if (data->map[data->py][data->px - 1] != '1' && data->map[data->py][data->px
		- 1] != 'E')
	{
		if (data->map[data->py][data->px] == 'C')
		{
			data->collectibles_collected++;
			data->map[data->py][data->px] = '0';
		}
		data->px--;
		data->moves++;
	}
	else if (data->map[data->py][data->px - 1] == 'E'
		&& data->collectibles_collected != data->collectibles)
		ft_printf("Collect all pieces of cake first!\n");
	else if (data->map[data->py][data->px - 1] == 'E'
		&& data->collectibles_collected == data->collectibles)
	{
		data->px--;
		data->moves++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->textures->player, data->px * IMG_W, data->py * IMG_H);
	mlx_do_sync(data->mlx_ptr);
}

void	move_right(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures->floor,
		data->px * IMG_W, data->py * IMG_H);
	if (data->map[data->py][data->px + 1] != '1' && data->map[data->py][data->px
		+ 1] != 'E')
	{
		if (data->map[data->py][data->px] == 'C')
		{
			data->collectibles_collected++;
			data->map[data->py][data->px] = '0';
		}
		data->px++;
		data->moves++;
	}
	else if (data->map[data->py][data->px + 1] == 'E'
		&& data->collectibles_collected != data->collectibles)
		ft_printf("Collect all pieces of cake first!\n");
	else if (data->map[data->py][data->px + 1] == 'E'
		&& data->collectibles_collected == data->collectibles)
	{
		data->px++;
		data->moves++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->textures->player, data->px * IMG_W, data->py * IMG_H);
	mlx_do_sync(data->mlx_ptr);
}
