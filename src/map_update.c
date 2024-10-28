/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:32:30 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	draw_map(data);
	draw_items(data);
	draw_player(data);
	exit_game(data);
	return (TRUE);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->index_y = 0;
	while (data->index_y < data->back_y && data->map[j])
	{
		data->index_x = 0;
		i = 0;
		while (data->index_x < data->back_y && data->map[j][i])
		{
			mlx_put_image_to_window(data->mlx, data->wind, data->img, \
				data->index_x * TILE_SIZE, data->index_y * TILE_SIZE);
			if (data->map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->wind, data->border, \
					data->index_x * TILE_SIZE, data->index_y * TILE_SIZE);
			else if (data->map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->wind, data->exit, \
					data->index_x * TILE_SIZE, data->index_y * TILE_SIZE);
			data->index_x++;
			i++;
		}
		data->index_y++;
		j++;
	}
}

void	draw_items(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->index_y = 0;
	while (data->index_y < data->back_y && data->map[j])
	{
		data->index_x = 0;
		i = 0;
		while (data->index_x < data->back_y && data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->wind, data->items, \
					data->index_x * TILE_SIZE, data->index_y * TILE_SIZE);
			data->index_x++;
			i++;
		}
		data->index_y++;
		j++;
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player_pos_x;
	y = data->player_pos_y;
	mlx_put_image_to_window(data->mlx, data->wind, data->player, \
		x * TILE_SIZE, y * TILE_SIZE);
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->c -= 1;
	}
}

void	exit_game(t_data *data)
{
	int	x;
	int	y;

	x = data->player_pos_x;
	y = data->player_pos_y;
	if (data->map[y][x] == 'E' && data->c == 0)
	{
		ft_printf("Congratulations, you win in %d moves\n", data->count);
		close_game(data);
		exit(1);
	}
}
