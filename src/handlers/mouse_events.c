/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 01:17:21 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 22:51:26 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

int	default_handler(t_fractol *data)
{
	if (data->value1 == 0)
		ft_fractol(data, ft_mandelbrot);
	else if (data->value1 == 1)
		ft_fractol(data, ft_julia);
	else if (data->value1 == 2)
		ft_fractol(data, ft_burning_ship);
	return (0);
}

int	mouse_press_handler(int keycode, int x, int y, t_fractol *data)
{
	if (keycode == 4)
	{
		data->x_scale *= 0.5;
		data->y_scale *= 0.5;
		data->max_iterations += 20;
		data->center_x -= (x * data->x_scale);
		data->center_y -= (y * data->y_scale);
	}
	else if (keycode == 5)
	{
		data->center_x += (x * data->x_scale);
		data->center_y += (y * data->y_scale);
		data->x_scale /= 0.5;
		data->y_scale /= 0.5;
		data->max_iterations -= 20;
	}
	else if (keycode == 1)
		data->value2 += 1;
	return (0);
}

int	mouse_move_handler(int x, int y, t_fractol *data)
{
	if (data->value2 % 2)
	{
		if (x >= 0 && x <= WINDOW_WIDTH && y >= 0 && y <= WINDOW_HEIGHT)
		{
			data->julia = complex_init(data->x_scale * x - data->center_x, \
				data->y_scale * y - data->center_y);
		}
		else
			return (0);
	}
	else
		data->julia = complex_init(data->julia.r_part, data->julia.i_part);
	return (0);
}
