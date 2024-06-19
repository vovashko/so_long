/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:00:38 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:15:20 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(char c)
{
	if (c == '1')
	{
		ft_printf("Error\nMalloc or ft_calloc failed\n");
		exit(1);
	}
	else if (c == '2')
	{
		ft_printf("Error\nget_next_line failed\n");
		exit(1);
	}
	else if (c == '3')
	{
		ft_printf("Error\nOnly one player is allowed\n");
		exit(1);
	}
	else if (c == '4')
	{
		ft_printf("Error\nNo collectibles found\n");
		exit(1);
	}
	else if (c == '5')
	{
		ft_printf("Error\nOnly one exit is allowed\n");
		exit(1);
	}
}

void	error_map(void)
{
	ft_printf("Error\nInvalid border\n");
	exit(1);
}

int	map_len(int fd)
{
	int		len;
	char	buf[1];

	len = 0;
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			break ;
		len++;
	}
	return (len);
}

int	map_height(int fd)
{
	int		height;
	char	*line;

	height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	return (height);
}
