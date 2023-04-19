/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:15:50 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/14 13:27:40 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_control(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->column)
	{
		if (data->split[0][i] != '1' || data->split[data->row - 1][i] != '1')
		{
			write(2, "wrong column wall\n", 18);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < data->row)
	{
		if (data->split[i][0] != '1' || data->split[i][data->column - 1] != '1')
		{
			write(2, "wrong row wall\n", 15);
			exit(0);
		}
		i++;
	}
	other_character_control(data);
	cpe_control(data);
	map_right(data);
}

void	other_character_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (data->split[i][j] != 'P' && data->split[i][j] != 'E'
				&& data->split[i][j] != 'C')
			{
				if (data->split[i][j] != '0' && data->split[i][j] != '1')
				{
					write(2, "other character error!\n", 23);
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
}

void	space_line(t_list *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
		{
			if (data->map[i - 1] != '1' || data->map[i + 1] != '1')
			{
				write(2, "Space Error!!\n", 14);
				exit(0);
			}
		}
		i++;
	}
}

void	cpe_control(t_list *data)
{
	int	i;

	data->player = 0;
	data->exit = 0;
	data->coin = 0;
	data->step = 0;
	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'P')
			data->player++;
		if (data->map[i] == 'E')
			data->exit++;
		if (data->map[i] == 'C')
			data->coin++;
		i++;
	}
	if ((data->coin == 0) || data->exit != 1 || data->player != 1)
	{
		write(2, "CPE BOOM!\n", 10);
		exit(0);
	}
}

void	map_right(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
			j++;
		if (j != data->column)
		{
			write(2, "map is not right\n", 17);
			exit(0);
		}
		i++;
	}
}
