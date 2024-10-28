/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:13:54 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 14:17:23 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_instructions(t_data *data)
{
	if (data->img != NULL)
		mlx_destroy_image(data->mlx, data->img);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx, data->player);
	if (data->items != NULL)
		mlx_destroy_image(data->mlx, data->items);
	if (data->border != NULL)
		mlx_destroy_image(data->mlx, data->border);
	if (data->exit != NULL)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->wind != NULL)
		mlx_destroy_window(data->mlx, data->wind);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}

int	close_window(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_instructions(data);
	return (TRUE);
}
