/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:15:33 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/12 16:24:32 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_location(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (data->split[i][j] == 'P')
			{
				data->map_x = j;
				data->map_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	data->linesplit = ft_split(data->map, '\n');
	line(data, data->map_y, data->map_x);
}

void	exit_location(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (data->split[i][j] == 'E')
			{
				data->exit_x = j;
				data->exit_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	coin_reach(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->linesplit[i])
	{
		j = 0;
		while (data->linesplit[i][j])
		{
			if (data->linesplit[i][j] == 'C')
			{
				write(2, "Not reach the coin\n", 19);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	exit_reach(t_list *data)
{
	if (data->linesplit[data->exit_y][data->exit_x - 1] == '.')
		return ;
	if (data->linesplit[data->exit_y - 1][data->exit_x] == '.')
		return ;
	if (data->linesplit[data->exit_y][data->exit_x + 1] == '.')
		return ;
	if (data->linesplit[data->exit_y + 1][data->exit_x] == '.')
		return ;
	else
	{
		write(2, "not reach the exit\n", 19);
		exit(0);
	}
}

void	line(t_list *data, int y, int x)
{
	if (data->linesplit[y][x + 1] == '0' || data->linesplit[y][x + 1] == 'C'
		|| data->linesplit[y][x + 1] == 'P')
	{
		data->linesplit[y][x + 1] = '.';
		line(data, y, x + 1);
	}
	if (data->linesplit[y][x - 1] == '0' || data->linesplit[y][x - 1] == 'C'
		|| data->linesplit[y][x - 1] == 'P')
	{
		data->linesplit[y][x - 1] = '.';
		line(data, y, x - 1);
	}
	if (data->linesplit[y + 1][x] == '0' || data->linesplit[y + 1][x] == 'C'
		|| data->linesplit[y + 1][x] == 'P')
	{
		data->linesplit[y + 1][x] = '.';
		line(data, y + 1, x);
	}
	if (data->linesplit[y - 1][x] == '0' || data->linesplit[y - 1][x] == 'C'
		|| data->linesplit[y - 1][x] == 'P')
	{
		data->linesplit[y - 1][x] = '.';
		line(data, y - 1, x);
	}
}
