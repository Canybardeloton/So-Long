/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:59 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 13:41:15 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char **input)
{
	int		index_x;
	int		index_y;
	int		length;
	int		width;

	index_x = 0;
	index_y = 0;
	length = map_length(index_y, input);
	width = map_width(index_x, input);
	if ((length < 5 && width < 3) || (length < 3 && width < 5))
		return (FALSE);
	if (check_rectangular(length, width, input) == FALSE)
		return (FALSE);
	if (check_lines(length, width, input) == FALSE)
		return (FALSE);
	if (!flood_fill(input))
		return (FALSE);
	return (TRUE);
}

int	check_lines(int length, int width, char **map)
{
	if (check_walls(length, width, map) == FALSE)
		return (ft_putstr_fd("Error\nWall Error\n", 2), FALSE);
	if (check_start(map) == FALSE)
		return (ft_putstr_fd("Error\nStart Error\n", 2), FALSE);
	if (check_exit(map) == FALSE)
		return (ft_putstr_fd("Error\nExit Error\n", 2), FALSE);
	if (check_items(map) == FALSE)
		return (ft_putstr_fd("Error\nItems Error\n", 2), FALSE);
	if (check_filling(map) == FALSE)
		return (ft_putstr_fd("Error\nFilling Error\n", 2), FALSE);
	return (TRUE);
}

int	count_lines(int fd)
{
	int		count;
	char	map_name[4096];
	int		ret;

	count = 0;
	ret = read(fd, map_name, sizeof(map_name));
	if (ret == -1)
		return (close(fd), \
			ft_printf("Error\n Read Map%s\n", strerror(errno)), FALSE);
	count = ret;
	return (count);
}

int	check_file(char *input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	i = i - 4;
	if (ft_strncmp(&input[i], ".ber", 5) == 0)
		return (TRUE);
	return (FALSE);
}
