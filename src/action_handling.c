/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:05:29 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 13:45:43 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_window(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->index_y < data->back_y && data->map[j])
	{
		data->index_x = 0;
		i = 0;
		while (data->index_x < data->back_x && data->map[j][i])
		{
			if (!map_display(data, i, j))
				return (FALSE);
			data->index_x++;
			i++;
		}
		data->index_y++;
		j++;
	}
	return (TRUE);
}

int	map_display(t_data *data, int i, int j)
{
	if (!mlx_put_image_to_window(data->mlx, data->wind, \
		data->img, data->index_x * TILE_SIZE, data->index_y * TILE_SIZE))
		return (FALSE);
	if (data->map[j][i] == '1')
	{
		if (!mlx_put_image_to_window(data->mlx, data->wind, \
		data->border, data->index_x * TILE_SIZE, data->index_y * TILE_SIZE))
			return (FALSE);
	}
	else if (!map_display2(data, i, j))
		return (FALSE);
	return (TRUE);
}

int	map_display2(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'P')
	{
		if (!mlx_put_image_to_window(data->mlx, data->wind, \
		data->player, data->index_x * TILE_SIZE, data->index_y * TILE_SIZE))
			return (FALSE);
	}
	else if (data->map[j][i] == 'C')
	{
		if (!mlx_put_image_to_window(data->mlx, data->wind, \
		data->items, data->index_x * TILE_SIZE, data->index_y * TILE_SIZE))
			return (FALSE);
	}
	else if (data->map[j][i] == 'E')
	{
		if (!mlx_put_image_to_window(data->mlx, data->wind, \
		data->exit, data->index_x * TILE_SIZE, data->index_y * TILE_SIZE))
			return (FALSE);
	}
	return (TRUE);
}

int	move_count(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->player_pos_x;
	y = data->player_pos_y;
	if ((keycode == XK_a || keycode == XK_Left)
		&& (data->map[y][x - 1] != '1'))
		return (++data->count, \
			ft_printf("Move count : %d\n", data->count), 0);
	else if ((keycode == XK_d || keycode == XK_Right) \
		&& (data->map[y][x + 1] != '1'))
		return (++data->count, \
			ft_printf("Move count : %d\n", data->count), 0);
	else if ((keycode == XK_s || keycode == XK_Down) \
		&& (data->map[y + 1][x] != '1'))
		return (++data->count, \
			ft_printf("Move count : %d\n", data->count), 0);
	else if ((keycode == XK_w || keycode == XK_Up) \
		&& (data->map[y - 1][x] != '1'))
		return (++data->count, \
			ft_printf("Move count : %d\n", data->count), 0);
	return (0);
}

int	player_movement(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->player_pos_x;
	y = data->player_pos_y;
	if ((keycode == XK_a || keycode == XK_Left) && (data->map[y][x - 1] != '1'))
		x -= 1;
	else if ((keycode == XK_d || keycode == XK_Right) \
		&& (data->map[y][x + 1] != '1'))
		x += 1;
	else if ((keycode == XK_s || keycode == XK_Down) \
		&& (data->map[y + 1][x] != '1'))
		y += 1;
	else if ((keycode == XK_w || keycode == XK_Up) \
		&& (data->map[y - 1][x] != '1'))
		y -= 1;
	if (x >= 0 && x < data->back_x && y >= 0 && y < data->back_y)
	{
		data->player_pos_x = x;
		data->player_pos_y = y;
		render(data);
	}
	return (0);
}
