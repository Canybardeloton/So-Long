/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:09:39 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 13:46:09 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include "../My_Libft/src/my_libft.h"
# include <stdbool.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <math.h>
# include <string.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define TRUE 1
# define FALSE 0
# define WINDOW_WIDTH 500
# define WINDOW_LENGTH 500
# define RENDER 32
# define TILE_SIZE 32

typedef struct s_data
{
	int		index_x;
	int		index_y;
	int		width;
	int		length;
	int		endian;
	int		count;
	int		c;
	int		p;
	int		e;
	int		back_x;
	int		back_y;
	int		back_width;
	int		back_heigth;
	char	*adress;
	int		player_pos_x;
	int		player_pos_y;
	int		bpp;
	void	*img;
	void	*border;
	void	*player;
	void	*exit;
	void	*items;
	char	**map;
	void	*wind;
	void	*mlx;
}			t_data;

// Map dimensions
int		map_width(int index, char **input);
int		map_length(int index, char **input);

// Map rules
int		check_walls(int length, int width, char **map);
int		check_vertical_walls(int width, char **map);
int		check_horizontal_walls(int width, int length, char **map);
int		check_items(char **map);
int		check_exit(char **map);
int		check_start(char **map);
int		check_rectangular(int length, int width, char **map);
int		check_filling(char **map);

// Map check
int		map_check(char **input);
int		check_lines(int length, int width, char **map);
void	fill_map(char **map, int length, int row, int column);
int		flood_fill(char **map);
int		get_start_position(int fork, char **map);
int		count_lines(int fd);
int		check_file(char *input);

// Struct Map
int		fill_struct(t_data *data);
void	print_struct(t_data *data);
char	*open_map(char **av);
int		init_struc(t_data *data, char **map);
void	error_handling(t_data *data);

// Rendering
int		start_rendering(t_data *data);
int		fill_window(t_data *data);
int		initiate_window(t_data *data);
int		config_images(t_data *data);
int		map_display(t_data *data, int i, int j);
int		map_display2(t_data *data, int i, int j);

// Action Handling
int		key_handler(int keycode, t_data *data);
int		move_count(int keycode, t_data *data);
int		player_movement(int keycode, t_data *data);
int		render(t_data *data);
void	draw_player(t_data *data);
void	draw_map(t_data *data);
void	draw_items(t_data *data);
void	exit_game(t_data *data);

// Close window
int		close_instructions(t_data *data);
int		close_window(int keysym, t_data *data);
void	free_final(t_data *data, char **map, char *full_map);
void	close_game(t_data *data);

#endif
