/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:07:52 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 10:50:24 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_start_position(int fork, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				if (fork == 1)
					return (i);
				if (fork == 0)
					return (j);
			}
			i++;
		}
		j++;
	}
	return (FALSE);
}

int	start_rendering(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		error_handling(data);
		ft_putstr_fd("Error\nCant initiate display\n", 2);
		return (FALSE);
	}
	if (!initiate_window(data))
	{
		ft_putstr_fd("Error\nCant initiate window\n", 2);
		return (FALSE);
	}
	if (!mlx_key_hook(data->wind, key_handler, data))
		return (FALSE);
	if (!mlx_hook(data->wind, 17, 0, close_instructions, data))
		return (FALSE);
	if (!mlx_loop(data->mlx))
		return (FALSE);
	return (TRUE);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		if (!close_window(keycode, data))
			return (FALSE);
	}
	else
	{
		move_count(keycode, data);
		player_movement(keycode, data);
	}
	return (TRUE);
}

int	initiate_window(t_data *data)
{
	data->wind = mlx_new_window(data->mlx, \
		data->back_x, data->back_y, "SO_LONG");
	if (data->wind == NULL)
		return (FALSE);
	if (config_images(data) == FALSE)
		return (FALSE);
	data->adress = mlx_get_data_addr(data->img, &data->bpp, \
		&data->width, &data->endian);
	if (data->adress == NULL)
		return (FALSE);
	if (!fill_window(data))
		return (FALSE);
	return (TRUE);
}

int	config_images(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "src/img/back.xpm", \
		&data->back_width, &data->back_heigth);
	if (data->img == NULL)
		return (close_instructions(data), FALSE);
	data->border = mlx_xpm_file_to_image(data->mlx, "src/img/border.xpm", \
		&data->back_width, &data->back_heigth);
	if (data->border == NULL)
		return (close_instructions(data), FALSE);
	data->player = mlx_xpm_file_to_image(data->mlx, "src/img/player.xpm", \
		&data->back_width, &data->back_heigth);
	if (data->player == NULL)
		return (close_instructions(data), FALSE);
	data->items = mlx_xpm_file_to_image(data->mlx, "src/img/items.xpm", \
		&data->back_width, &data->back_heigth);
	if (data->items == NULL)
		return (close_instructions(data), FALSE);
	data->exit = mlx_xpm_file_to_image(data->mlx, "src/img/exit.xpm", \
		&data->back_width, &data->back_heigth);
	if (data->exit == NULL)
		return (close_instructions(data), FALSE);
	return (TRUE);
}
