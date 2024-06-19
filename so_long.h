/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 17:04:53 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/02/29 19:17:17 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_W 64
# define IMG_H 64
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define WINDOW_NAME "Ring of Fire"

typedef struct s_textures
{
	void		*player;
	void		*wall;
	void		*floor;
	void		*collectible;
	void		*exit;
}				t_textures;

typedef struct s_check
{
	int			**map_copy;
	int			exit_or_collectible;
}				t_check;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map_width;
	int			map_height;
	int			x;
	int			y;
	char		**map;
	int			px;
	int			py;
	int			collectibles;
	int			moves;
	int			collectibles_collected;
	t_textures	*textures;
}				t_data;

// init data
void			init_data(t_data *data, char **argv);
void			init_window(t_data *data);

// player moves
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			move_up(t_data *data);

// key hooks
int				on_keypress(int key, t_data *data);
int				on_destroy(t_data *data);

// check map
void			check_rules(t_data *data);
void			check_valid_player_path(t_data *data, int x, int y);
void			check_map(t_data *data);

// init map
void			parse_map(t_data *data, char **argv);
void			fill_map(t_data *data);

// utils
void			error_handler(char c);
void			error_map(void);
int				map_height(int fd);
int				map_len(int fd);
#endif