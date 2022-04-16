/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:22:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 22:42:11 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

int	ft_close_window(t_fractol *data)
{
	ft_error_exit("", data, true);
	return (0);
}

int	key_press_handler(int keycode, t_fractol *data)
{
	if (keycode == ESC_KEY)
		ft_error_exit("", data, true);
	else if (keycode == UP_ARROW_KEY)
		data->center_y += 30 * data->x_scale;
	else if (keycode == DOWN_ARROW_KEY)
		data->center_y -= 30 * data->x_scale;
	else if (keycode == RIGHT_ARROW_KEY)
		data->center_x -= 30 * data->x_scale;
	else if (keycode == LEFT_ARROW_KEY)
		data->center_x += 30 * data->x_scale;
	else if (keycode == R_KEY)
		ft_reset_fractal(data);
	else if (keycode == P_KEY)
		ft_color_handle(data);
	return (0);
}

void	ft_reset_fractal(t_fractol *data)
{
	data->x_scale = (4.0 / WINDOW_WIDTH);
	data->y_scale = (4.0 / WINDOW_HEIGHT);
	data->center_x = 2.0;
	data->center_y = 2.0;
	data->max_iterations = 50;
	if (!data->value1)
		ft_fractol(data, ft_mandelbrot);
	else if (data->value1 == 1)
		ft_fractol(data, ft_julia);
}
