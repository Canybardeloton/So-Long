/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:39:48 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/26 17:44:21 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handling(t_data *data)
{
	if (data->adress != NULL)
		free(data->adress);
	if (data->img != NULL)
		free(data->img);
	if (data->player != NULL)
		free(data->player);
	if (data->exit != NULL)
		free(data->exit);
	if (data->items != NULL)
		free(data->items);
	if (data->border != NULL)
		free(data->border);
	if (data->wind != NULL)
		free(data->wind);
	if (data->mlx != NULL)
		free(data->mlx);
}

void	close_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->items);
	mlx_destroy_image(data->mlx, data->border);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_window(data->mlx, data->wind);
	mlx_destroy_display(data->mlx);
	if (data->map)
		free_everything(data->map);
	free(data->mlx);
	free(data);
}
