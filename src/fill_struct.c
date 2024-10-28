/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:19:25 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 13:40:21 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_struc(t_data *data, char **map)
{
	data->map = map;
	data->index_x = 0;
	data->index_y = 0;
	data->back_heigth = RENDER;
	data->back_width = RENDER;
	data->player_pos_x = get_start_position(1, map);
	data->player_pos_y = get_start_position(0, map);
	data->length = 0;
	data->count = 0;
	data->width = 0;
	data->endian = 0;
	data->back_x = 0;
	data->back_y = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	if (!fill_struct(data))
		return (FALSE);
	return (TRUE);
}

int	fill_struct(t_data *data)
{
	int	index;

	index = 0;
	data->length = map_length(0, data->map);
	if (!data->length)
		return (error_handling(data), FALSE);
	data->width = map_width(0, data->map);
	if (!data->width)
		return (error_handling(data), FALSE);
	data->c = check_items(data->map);
	if (!data->c)
		return (error_handling(data), FALSE);
	data->p = check_start(data->map);
	if (!data->p)
		return (error_handling(data), FALSE);
	data->e = check_exit(data->map);
	if (!data->e)
		return (error_handling(data), FALSE);
	data->back_x = RENDER * data->width;
	if (!data->back_x)
		return (error_handling(data), FALSE);
	data->back_y = RENDER * data->length;
	if (!data->back_y)
		return (error_handling(data), FALSE);
	return (TRUE);
}

char	*open_map(char **av)
{
	char	*full_map;
	int		fd;
	int		ret;
	int		size;
	char	*final_map;

	if (check_file(av[1]) == FALSE)
		return (ft_putstr_fd("Error\nWrong File\n", 2), NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nOpen Map\n", 2), NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_putstr_fd("Error\nWrong input\n", 2), NULL);
	size = count_lines(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nOpen Map\n", 2), NULL);
	full_map = ft_calloc(size + 1, sizeof(char));
	ret = read(fd, full_map, size);
	if (ret == -1)
		return (free(full_map), close(fd), \
			ft_putstr_fd("Error\nRead Map\n", 2), NULL);
	final_map = ft_strdup(full_map);
	return (free(full_map), close(fd), final_map);
}

void	print_struct(t_data *data)
{
	ft_printf("data->index_x : %d\n", data->index_x);
	ft_printf("data->index_y : %d\n", data->index_y);
	ft_printf("data->length : %d\n", data->length);
	ft_printf("data->width : %d\n", data->width);
	ft_printf("data->p : %d\n", data->p);
	ft_printf("data->c : %d\n", data->c);
	ft_printf("data->e : %d\n", data->e);
}
