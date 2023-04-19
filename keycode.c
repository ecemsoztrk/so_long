/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:29:01 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/12 16:31:56 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int key, t_list *data)
{
	if (key == 53 || key == 12)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(1);
	}
	if ((key == 13 || key == 126) && data->split[data->map_y - 1]
		[data->map_x] != '1')
		up(data);
	if ((key == 2 || key == 124) && data->split[data->map_y]
		[data->map_x + 1] != '1')
		right(data);
	if ((key == 0 || key == 123) && data->split[data->map_y]
		[data->map_x - 1] != '1')
		left(data);
	if ((key == 1 || key == 125) && data->split[data->map_y + 1]
		[data->map_x] != '1')
		down(data);
	return (1);
}

void	up(t_list *data)
{
	if (data->split[data->map_y - 1][data->map_x] == 'C')
	{
		data->coin--;
		data->split[data->map_y - 1][data->map_x] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y - 1][data->map_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y - 1][data->map_x] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	right(t_list *data)
{
	if (data->split[data->map_y][data->map_x + 1] == 'C')
	{
		data->coin--;
		data->split[data->map_y][data->map_x + 1] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x + 1] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	left(t_list *data)
{
	if (data->split[data->map_y][data->map_x - 1] == 'C')
	{
		data->coin--;
		data->split[data->map_y][data->map_x - 1] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_x--;
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x - 1] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	down(t_list *data)
{
	if (data->split[data->map_y + 1][data->map_x] == 'C')
	{
		data->coin--;
		data->split[data->map_y + 1][data->map_x] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y + 1][data->map_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0],
			data->map_x * 64, data->map_y * 64);
		data->map_y++;
		mlx_put_image_to_window(data->mlx, data->window, data->image[4],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y + 1][data->map_x] == 'E'
			&& data->coin == 0)
		step_escape(data);
}
