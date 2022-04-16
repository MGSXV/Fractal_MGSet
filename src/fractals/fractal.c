/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:29:48 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 22:55:08 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_fractol(t_fractol *data, void (*f)(t_fractol *data))
{
	int	color;

	data->coord.x = -1;
	while (++data->coord.x < WINDOW_WIDTH)
	{
		data->coord.y = -1;
		while (++data->coord.y < WINDOW_HEIGHT)
		{
			f(data);
			if (data->iterations < data->max_iterations)
			{
				color = data->iterations * data->color.color;
				mg_pixel_put(data, data->coord.x, data->coord.y, color);
			}
			else
				mg_pixel_put(data, data->coord.x, data->coord.y, BLACK);
		}
	}
	mlx_put_image_to_window(data->mlx_req.mlx_p, data->mlx_req.win_p, \
		data->mlx_req.img_p, 0, 0);
}
