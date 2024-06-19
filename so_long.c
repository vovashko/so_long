/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 17:04:48 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:18:17 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_exit(t_data *data)
{
	if (data->collectibles_collected == data->collectibles)
	{
		ft_printf("You Win!\n");
		ft_printf("Total moves: %d\n", data->moves);
		on_destroy(data);
	}
}

int	on_destroy(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map_height / IMG_H)
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
	exit(0);
}

void	display_move_count(t_data *data)
{
	char	*move_count;
	char	*moves_label;

	moves_label = "Moves: ";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0 * IMG_W, 1 * IMG_H,
		0x00FFFFFF, moves_label);
	move_count = ft_itoa(data->moves);
	if (!move_count)
	{
		perror("Error\nft_itoa failed\n");
		on_destroy(data);
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 2 * IMG_W, 1 * IMG_H,
		0x00FFFFFF, move_count);
	ft_printf("Moves: %s\n", move_count);
	free(move_count);
}

int	on_keypress(int key, t_data *data)
{
	if (key == 65307)
		on_destroy(data);
	else if ((key == 'w' || key == 65362))
		move_up(data);
	else if ((key == 'a' || key == 65361))
		move_left(data);
	else if ((key == 's' || key == 65364))
		move_down(data);
	else if ((key == 'd' || key == 65363))
		move_right(data);
	display_move_count(data);
	if (data->map[data->py][data->px] == 'E')
		handle_exit(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_data(&data, argv);
	parse_map(&data, argv);
	check_map(&data);
	init_window(&data);
	fill_map(&data);
	mlx_hook(data.win_ptr, 17, 1L << 2, on_destroy, &data);
	mlx_key_hook(data.win_ptr, on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
