/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:14:55 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/12 16:26:37 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reader(t_list *data, char *str)
{
	int	fd;

	data->column = 0;
	data->row = 0;
	fd = open(str, O_RDWR, O_RDONLY, 0777);
	data->map = get_next_line(fd);
	if (fd == -1)
	{
		write(2, "map can't be read\n", 18);
		exit(0);
	}
	if (!data->map)
	{
		write(2, "empty map\n", 10);
		exit(0);
	}
	data->split = ft_split(data->map, '\n');
	while (data->split[data->row])
	{
		data->column = 0;
		while (data->split[data->row][data->column])
			data->column++;
		data->row++;
	}
}

int	check_ber(char *checking)
{
	int		fd;
	size_t	len;

	fd = open(checking, O_RDONLY);
	if (fd < 0)
		return (0);
	len = ft_strlen(checking);
	if (checking[len - 1] == 'r' && checking[len - 2] == 'e'
		&& checking[len - 3] == 'b' && checking[len - 4] == '.')
		return (1);
	return (0);
}

int	exit_func(void)
{
	exit(1);
}

int	control(t_list *data, char *av)
{
	if (!check_ber(av))
	{
		write(2, "The extension of file is not .ber or wrong map file name!\n",
			59);
		return (0);
	}
	wall_control(data);
	other_character_control(data);
	space_line(data);
	cpe_control(data);
	map_right(data);
	player_location(data);
	coin_reach(data);
	exit_location(data);
	exit_reach(data);
	window(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_list));
		map_reader(data, av[1]);
		if (!control(data, av[1]))
			return (0);
		mlx_hook(data->window, 2, 1L << 0, keycode, data);
		mlx_hook(data->window, 17, 1L << 17, exit_func, data);
		mlx_loop(data->mlx);
	}
}
