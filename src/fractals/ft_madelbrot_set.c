/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madelbrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:26:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/15 17:18:00 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

static int	calculate_mandelbrot(t_coor *coord, t_img_buff *data)
{
	t_complex	z;
	t_complex	c;
	int			i;

	data->screen.zoom = 1;
	data->screen.move_x = -.5;
	data->screen.move_y = 0;
	i = 0;
	z = complex_init(0, 0);
	c.r_part = 1.5 * (coord->x - data->screen.window_width / 2)
		/ (0.5 * data->screen.zoom * data->screen.window_width) + data->screen.move_x;
	c.i_part = 1.5 * (coord->y - data->screen.window_height / 2)
		/ (0.5 * data->screen.zoom * data->screen.window_height) + data->screen.move_y;
	while (i < data->screen.max_iterations)
	{
		z = complex_addition(complex_square(z), c);
		if (((z.r_part * z.r_part) + (z.i_part * z.i_part)) > 4)
			break ;
		i++;
	}
	return (i);
}

void	ft_mandelbrot(t_img_buff *data)
{
	t_coor		coord;
	int			i;

	data->screen.window_height = 920;
	data->screen.window_width = 920;
	data->screen.max_iterations = 300;
	coord.y = 0;
	ft_new_window(data);
	while (coord.y < data->screen.window_height)
	{
		coord.x = 0;
		while (coord.x < data->screen.window_width)
		{
			i = calculate_mandelbrot(&coord, data);
			if (i < data->screen.max_iterations)
				mg_pixel_put(data, coord.x, coord.y, 0x00FFFFFF);
			coord.x++;
		}
		coord.y++;
	}
	mlx_put_image_to_window(data->data_buff.mlx_p, data->data_buff.win_p,
		data->data_buff.img_p, 0, 0);
	mlx_loop(data->data_buff.mlx_p);
}
