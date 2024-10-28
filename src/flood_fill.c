/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:56:07 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 11:15:29 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(char **map, int length, int row, int column)
{
	int	width;

	width = map_width(0, map);
	if (row >= length || column >= width || row <= 0
		|| column <= 0 || map[row][column] == '1'
		|| map[row][column] == 'F')
		return ;
	map[row][column] = 'F';
	fill_map(map, length, row + 1, column);
	fill_map(map, length, row - 1, column);
	fill_map(map, length, row, column + 1);
	fill_map(map, length, row, column - 1);
}

int	flood_fill(char **map)
{
	int		x;
	int		y;
	char	**tmp;
	int		i;
	int		length;

	length = map_length(0, map);
	x = get_start_position(1, map);
	y = get_start_position(0, map);
	tmp = ft_calloc(length + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	fill_map(tmp, length, y, x);
	if (check_exit(tmp) == TRUE)
		return (free_everything(tmp), FALSE);
	if (check_items(tmp) == TRUE)
		return (free_everything(tmp), FALSE);
	free_everything(tmp);
	return (TRUE);
}
