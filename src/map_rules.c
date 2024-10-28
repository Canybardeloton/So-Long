/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:57:06 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 13:46:00 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(int length, int width, char **map)
{
	int		index_x;
	int		index_y;

	index_x = 0;
	index_y = 0;
	(void)length;
	while (map[index_x])
	{
		if (map_width(index_x, map) != width)
			return (FALSE);
		index_x++;
	}
	return (TRUE);
}

int	check_walls(int length, int width, char **map)
{
	if (check_vertical_walls(width, map) == FALSE)
		return (FALSE);
	if (check_horizontal_walls(width, length, map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_vertical_walls(int width, char **map)
{
	int	index;
	int	count;

	index = 0;
	count = width - 1;
	while (map[index])
	{
		if (map[index][0] == '1' && map[index][count] == '1')
			index++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_horizontal_walls(int width, int length, char **map)
{
	int	index;
	int	count;

	index = 0;
	while (map[0][index] != '0' && index < width)
	{
		if (map[0][index] != '1')
			return (FALSE);
		index++;
	}
	index = 0;
	count = length - 1;
	while (map[count][index])
	{
		if (map[count][index] != '1')
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	check_items(char **map)
{
	int	index_x;
	int	index_y;
	int	count;

	index_x = 0;
	count = 0;
	index_y = 0;
	while (map[index_x])
	{
		index_y = 0;
		while (map[index_x][index_y])
		{
			if (map[index_x][index_y] == 'C')
				count++;
			index_y++;
		}
		index_x++;
	}
	if (count < 1)
		return (FALSE);
	return (count);
}
