/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:14:32 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/14 13:29:33 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_by_step(t_list *data)
{
	char	*step;

	step = ft_itoa(data->step);
	mlx_put_image_to_window(data->mlx, data->window, data->image[0], 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[0], 64, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[1], 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[1], 64, 0);
	mlx_string_put(data->mlx, data->window, 0, 10, 0xffffff, "STEP =");
	mlx_string_put(data->mlx, data->window, 50, 10, 0xffffff, step);
	free(step);
}

void	step_plus(t_list *data)
{
	data->step++;
	step_by_step(data);
}

int	step_escape(t_list *data)
{
	step_plus(data);
	ft_printf("%d", data->step);
	exit(1);
}
